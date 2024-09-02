#include <iostream>
#include <limits>
#include <climits>

using namespace std;


void checkInput(int &input){

    while(!(cin >> input)){


        switch (input) {

            case INT_MAX:
                cout << "Error! The value inserted is higher than the limit accepted. Please, insert a new integer value." << endl;
                break;

            case INT_MIN:
                cout << "Error! The value inserted is lower than the limit accepted. Please, insert a new integer value." << endl;
                break;

            default:
                cout << "Invalid input! The input needs to be an integer number. Please, try again." << endl;
                break;

        }


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }


    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


int fibonacciSequence(int n){

    if(n <= 0){
        return 0;
    }else if(n <= 2){
        return 1;
    }

    int res = fibonacciSequence(n-2) + fibonacciSequence(n-1);


    return res;

}


int main() {


    int n_sequence;

    cout << "|-|-|-|-|-|-|-|-|-|-| Fibonacci sequence |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert nth number of the sequence: " << endl;

    checkInput(n_sequence);

    if(n_sequence < 0){

        n_sequence = abs(n_sequence);
        cout << "WARNING! A negative value has been inserted. The program will consider its absolute value." << endl;

    };

    int res = fibonacciSequence(n_sequence);


    cout << "Fibonacci output at '" << n_sequence << "': " << res << endl;

    return 0;
}
