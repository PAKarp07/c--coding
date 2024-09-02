#include <iostream>
#include <climits>
#include <limits>

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


void printPascals(int levels){

    for(int n = 1; n <= levels; n++){

        string spaces = string(levels - n, ' ');
        int res = 1;

        cout << spaces;

        for(int i = 1; i <= n; i++) {

            cout << res << " ";

            res = res * (n - i) / i;


        }

        cout << endl;
    }


}


int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Pascal's Triangle |-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert a number: " << endl;

    int input;

    checkInput(input);

    printPascals(input);

    return 0;
}
