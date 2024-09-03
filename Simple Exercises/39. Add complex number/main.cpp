#include <iostream>
#include <string>
#include <limits>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

struct complexNumber{

    double real = 0;
    double imaginary = 0;

};


void checkInput(double& input){


    while(!(cin >> input)){

        if(input == LONG_MAX)
            cerr << "ERROR! Number inserted is higher than the maximum limit. Please, insert a lower value." << endl;
        else if(input == LONG_MIN)
            cerr << "ERROR! Number inserted is lower than the minimum limit. Please, insert a higher value." << endl;
        else
            cerr << "ERROR! Invalid number inserted. Please, insert valid number." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


void assignComplexNumber(complexNumber& num){

    double input;

    cout << "Insert the real part of number" << endl;

    checkInput(input);

    num.real = input;

    cout << "Insert the imaginary part of number" << endl;

    checkInput(input);

    num.imaginary = input;

}


void printComplexNumber(complexNumber num){

    cout << num.real;
    if(num.imaginary >=0)
        cout << "+";
    cout << num.imaginary << "i";


}


complexNumber addComplex(complexNumber num1, complexNumber num2){


    complexNumber res;

    res.real = num1.real + num2.real;
    res.imaginary = num1.imaginary + num2.imaginary;

    return res;
}


int main() {


    cout << "|-|-|-|-|-|-|-|-|-| Sum two complex numbers |-|-|-|-|-|-|-|-|-|" << endl;

    complexNumber num1;
    complexNumber num2;

    cout << "--First complex number--" << endl;

    assignComplexNumber(num1);

    cout << "Value inserted: ";
    printComplexNumber(num1);
    cout << endl << "---------" << endl;

    cout << "--Second complex number--" << endl;

    assignComplexNumber(num2);

    cout << "Value inserted: ";
    printComplexNumber(num2);
    cout << endl << "---------" << endl;

    cout << "(";
    printComplexNumber(num1);
    cout << ")";
    cout << " + ";
    cout << "(";
    printComplexNumber(num2);
    cout << ") = ";
    printComplexNumber(addComplex(num1,num2));
    cout << endl;


}
