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



bool palindromeNumberSol1(int number){

    if(abs(number) >= 0 && abs(number) <10){
        return true;
    }


    int aux_number = abs(number), rev_number = 0, rest;

    while(aux_number != 0){

        rest = aux_number % 10;
        rev_number = rev_number * 10 + rest;
        aux_number/=10;

    }


    return abs(rev_number) == abs(number);

}



bool palindromeNumberSol2(int number){

    string num_str = to_string(abs(number));
    int left = 0, right = num_str.length() - 1;

    while(left < right){

        if(num_str[left] != num_str[right])
            return false;

        left++;
        right--;


    }

    return true;
}





bool palindromeNumberSol3(int number, int* ptr_number){

    if(number >= 0 && number <10){
        return (number == (*ptr_number) % 10);
    }


    if(!palindromeNumberSol3(number / 10, ptr_number))
        return false;


    *ptr_number /= 10;


    return (number % 10 == (*ptr_number) % 10);
}


bool palindromeNumberSol3Init(int number){

    int aux_number = abs(number);
    int *ptr_aux_number = new int(aux_number);

    return palindromeNumberSol3(aux_number, ptr_aux_number);
}




int main() {



    int input;

    cout << "|-|-|-|-|-|-|-|-|-|-| Palindrome numbers |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert the number: " << endl;

    checkInput(input);

    cout << "The number inserted '" << input << "' is " << (palindromeNumberSol3Init(input) ? "a palindrome number." : "not a palindrome number.") << endl;

    return 0;
}
