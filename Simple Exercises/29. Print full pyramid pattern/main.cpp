#include <iostream>
#include <limits>
#include <climits>

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

void printPyramid(int levels){

    for(int i = 0; i < levels; i++){

        string spaces = string(levels - 1 - i, ' ');

        cout << spaces;

        for(int n = 0; n < i + 1; n++){

            cout << "* ";

        }

        cout << endl;
    }

}




int main() {

    cout << "|-|-|-|-|-|-|-|-|-|-| Pyramid Pattern |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert the levels of the pyramid: " << endl;

    int input;

    checkInput(input);

    cout << "---------" << endl;
    cout << "Simple pyramid: " << endl;

    printPyramid(input);


    return 0;
}
