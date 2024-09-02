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


int dtoo(int num){

    string res;

    while(num != 0){

        res.insert(0, to_string(num % 8));
        num /= 8;

    }

    return stoi(res);

}


int main() {


    cout << "|-|-|-|-|-|-|-|-|-| Decimal to Octal |-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert an integer number: " << endl;

    int input;

    checkInput(input);


    cout << "Octal number of '" << input << "': " << dtoo(input) << endl;
    return 0;
}
