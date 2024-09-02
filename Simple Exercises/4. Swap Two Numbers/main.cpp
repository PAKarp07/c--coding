#include <iostream>
#include <limits>
#include <climits>

using namespace std;




void checkInput(int& in){

    while(!(cin >> in)){

        switch (in) {

            case INT_MAX:
                cout << "Error! The input is higher than the upper limit. Insert an integer number again: ";
                break;

            case INT_MIN:
                cout << "Error! The input is higher than the lower limit. Insert an integer number again: ";
                break;

            default:
                cout << "Invalid Input! Insert an integer number: ";
                break;

        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


void methodMenu(bool cb){

    if(cb)
        cout << "Choose respective number for the method to be used." << endl;


    cout << "|-|-|-|-|-|-|-|-|-|-|-| METHODS |-|-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "1. Third variable method" << endl;
    cout << "2. Addition and subtraction method" << endl;
    cout << "3. Multiplication and division method" << endl;
    cout << "4. Bitwise XOR method" << endl;
    cout << "-------------------------------------------------------" << endl;
}

void chooseMethod(int& method){

    methodMenu(true);

    checkInput(method);

    while(method < 1 || method > 4){

        methodMenu(false);

        cout << "Option chosen does not exist. Choose a valid option from the list above." << endl;

        checkInput(method);


    }

}



//Swap values with a third variable
void swapThirdVariable(int& a, int& b){

    int temp = a;
    a = b;
    b = temp;


}

//Swap values with addition and subtraction
void swapAddSub(int& a, int& b){

    if(a + b > INT_MAX){

        cout << "ERROR! Not possible to swap values using this method due to the addition of the variables is higher than the maximum value accepted." << endl;
        cout << "Program closed." << endl;
        exit(0);
    }else if(a - b < INT_MIN){
        cout << "ERROR! Not possible to swap values using this method due to the subtractions of the variables is lower than the minimum value accepted." << endl;
        cout << "Program closed." << endl;
        exit(0);
    };

    a = a + b;
    b = a - b;
    a = a - b;

}


//Swap values with multiplication and division
void swapMulDiv(int& a, int& b){

    if(a * b > INT_MAX){

        cout << "ERROR! Not possible to swap values using this method due to the multiplication of the variables is higher than the maximum value accepted." << endl;
        cout << "Program closed." << endl;
        exit(0);
    }else if(a / b < INT_MIN){
        cout << "ERROR! Not possible to swap values using this method due to the division of the variables is lower than the minimum value accepted." << endl;
        cout << "Program closed." << endl;
        exit(0);
    }else if(a == 0 || b == 0){
        cout << "ERROR! Not possible to swap values using this method due to one of the values is equal to zero." << endl;
        cout << "Program closed." << endl;
        exit(0);

    };


    a = a * b;
    b = a / b;
    a = a / b;

}

//Swap values with Bitwise XOR
void swapXOR(int& a, int& b){

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

}



int main() {


    int a,b, method;
    string str_method;

    cout << "Insert number A: ";
    checkInput(a);

    cout << "Insert number B: ";
    checkInput(b);


    chooseMethod(method);


    cout << "-------------------------------------------------------" << endl;
    cout << "Inserted values: A = " << a << "; B = " << b << endl;


    switch (method) {

        case 1:
            swapThirdVariable(a,b);
            str_method = "Third variable";
            break;
        case 2:
            swapAddSub(a,b);
            str_method = "Addition and subtraction";
            break;
        case 3:
            swapMulDiv(a,b);
            str_method = "Multiplication and division";
            break;
        case 4:
            swapXOR(a,b);
            str_method = "Bitwise XOR";
            break;
        default:
            cout << "ERROR! Method was not detected. Please try again." << endl;
            cout << "Program closed." << endl;
            exit(0);
    };


    cout << "Swapped values: A = " << a << "; B = " << b << endl;
    cout << "Chosen method: " << str_method << endl;
    cout << "-------------------------------------------------------" << endl;

    return 0;


}
