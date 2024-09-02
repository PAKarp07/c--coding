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


int main() {

    int input;

    cout << "|-|-|-|-|-|-|-|-|-|-| Odd or even |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert integer value: " << endl;

    checkInput(input);

    cout << "The inserted integer " << input << " is a " << ((input % 2 == 0) ? "even number." : "odd number.") << endl;




    return 0;
}
