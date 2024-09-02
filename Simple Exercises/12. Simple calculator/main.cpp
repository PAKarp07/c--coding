#include <iostream>
#include <climits>
#include <limits>

using namespace std;

void checkInput(double &input){


    while(!(cin >> input)){

        if(input == LONG_MAX)
            cout << "Error! Value inserted higher than the upper limit accepted. Please insert the value again: " << endl;
        else if(input == LONG_MIN)
            cout << "Error! Value inserted higher than the lower limit accepted. Please insert the value again: " << endl;
        else
            cout << "Invalid Input! Please insert a number as a value: " << endl;


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void checkInputOperation(char &input){


    while((cin >> input)){

        if(input == '+' || input == '-' || input == '*' || input == 'x' || input == 'X' || input == '/')
            break;

        cout << "The inserted symbol is valid, try again." << endl;
        cout << "Insert the first operation symbol: ";


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

bool anotherCalc(char &input){

    while((cin >> input)){

        switch (input) {

            case 'Y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Please input 'Y' to do another calculation or 'n' to exit the program." << endl;
                cout << "Do you wish to do another calculation? (Y/n)" << endl;
                break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Something unexpected as occurred. Closing the program." << endl;
    cout << "Program closed." << endl;
    return false;

}



double calculate(double num1, char operation, double num2){

    switch (operation) {

        case '+':
            return num1 + num2;

        case '-':
            return num1 - num2;

        case '*':
        case 'X':
        case 'x':
            return num1 * num2;

        case '/':
            return num1 / num2;

        default:
            cout << "Something unexpected as occurred. Please start the program again." << endl;
            cout << "Program closed." << endl;
            break;
    }

    exit(0);

}



int main() {


    cout << "|-|-|-|-|-|-|-|-|-|-| Simple calculator |-|-|-|-|-|-|-|-|-|-|" << endl;
    double a, b;
    char operation, retry;


    while(true){

        cout << "Insert the first number: ";
        checkInput(a);

        cout << "Insert the first operation symbol: ";
        checkInputOperation(operation);

        cout << "Insert the second number: ";
        checkInput(b);


        double result = calculate(a,operation,b);

        cout << a << " " << operation << " " << b << " = " << result << endl;

        cout << "Do you wish to do another calculation? (Y/n)" << endl;

        if(!anotherCalc(retry)){
            cout << "Calculator closed." << endl;
            break;
        }



    }




    return 0;
}
