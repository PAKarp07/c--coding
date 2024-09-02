#include <iostream>
#include <limits>
#include <climits>

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

bool isLeapYear(int year){


    if(year % 400 == 0 || (year % 4  == 0 && year % 100  != 0))
        return true;
    else
        return false;

}



int main() {

    int input;

    cout << "|-|-|-|-|-|-|-|-|-|-| Leap year or not |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert the year: " << endl;

    checkInput(input);

    cout << "The inserted year " << input << " is " << (isLeapYear(input) ? "a leap year." : "not a leap year.") << endl;




    return 0;
}
