#include <iostream>
#include <climits>
#include <limits>

using namespace std;


void checkInput(int &input){


    while(!(cin >> input)){

        switch (input) {

            case INT_MAX:
                cout << "Error! Value inserted higher than the upper limit accepted. Please insert the value again: ";
                break;

            case INT_MIN:
                cout << "Error! Value inserted higher than the lower limit accepted. Please insert the value again: ";
                break;

            default:
                cout << "Invalid Input! Please insert a number as a value: ";
                break;

        }


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}




bool primeNumLoopMethod(int input){


    if(input <= 1)
        return false;

    for(int i=2; i < input; i++){

        if(input % i == 0)
            return false;
    }

    return true;
}

bool primeNumLoopDivMethod(int input){


    if(input <= 1)
        return false;

    for(int i=2; i <= input/2; i++){

        if(input % i == 0)
            return false;
    }

    return true;
}


bool primeNumSqrtMethod(int input){


    if(input <= 1)
        return false;


    int div = 2;

    while(div * div <= input){

        if(input % div == 0)
            return false;

        div++;

    }

    return true;
}

bool primeNumSqrtOptMethod(int input){


    if(input <= 1)
        return false;
    else if(input == 2 || input == 3)
        return true;

    if(input % 2 == 0 || input % 3 == 0)
        return false;

    int div = 5;

    while(div * div <= input){

        if(input % div == 0)
            return false;

        div += 6;

    }

    return true;
}




bool primeNumRecursiveMethod(int input, int index = 2){


    if(input == 2 || index == input/2)
        return true;
    else if(input <= 1 || input % index == 0)
        return false;

    return primeNumRecursiveMethod(input, index + 1);
}




int main() {

    int input;

    cout << "|-|-|-|-|-|-|-|-|-|-| Prime numbers |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert the number: " << endl;

    checkInput(input);

    cout << "The number inserted '" << input << "' is " << (primeNumSqrtOptMethod(input) ? "a prime number." : "not a prime number.") << endl;

    return 0;
}
