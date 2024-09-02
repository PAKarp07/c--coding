#include <iostream>
#include <limits>
#include <climits>
#include "number_display.h"
#include <string>
#include <algorithm>

using namespace std;


void checkInput(int &input){


    while(!(cin >> input)){

        switch (input){

            case INT_MAX:
                cout << "Error! Value inserted higher than the upper limit accepted. Please insert the value again: ";
                break;
            case INT_MIN:
                cout << "Error! Value inserted higher than the lower limit accepted. Please insert the value again: ";
                break;
            default:
                cout << "Invalid Input! Please insert a number as a value: ";
                break;
        };


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void printNumber(int input){

    string result = to_string(input);
    reverse(result.begin(),result.end());
    size_t num_length = 0;

    while(num_length < NUM_HEIGHT){


        int num = stoi(result);

        while(num != 0){

            int digit = num % 10;
            cout << hashNumber[digit][0][num_length];
            num/=10;
        }

        cout << " \n";
        num_length++;

    }




}

int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Number in a large size |-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert a number: " << endl;

    int input;

    checkInput(input);

    printNumber(input);


    return 0;
}
