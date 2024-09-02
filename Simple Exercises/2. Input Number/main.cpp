#include <iostream>
#include <climits>
#include <limits>

using namespace std;

int main() {

    int number = 0;

    cout << "Enter any integer number (any decimals inserted are ignored): ";

    //If cin is invalid, enter this loop
    while(!(cin >> number)){

        //Clear screen
        cout<<"\x1B[2J\x1B[0;0f";

        //Check why it is invalid
        switch (number) {

            case INT_MAX:
                cout << "Error! The number surpasses the maximum value accepted." << endl << "Try to enter another integer number: ";
                break;
            case INT_MIN:
                cout << "Error! The number surpasses the minimum value accepted." << endl << "Try to enter another integer number: ";
            default:
                cout << "Invalid Input! You can only enter a integer number: ";
        }


        //Clear cin and let user input again
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }


    cout << "Entered number: " << number << endl;

    return 0;
}
