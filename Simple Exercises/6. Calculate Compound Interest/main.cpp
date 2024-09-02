#include <iostream>
#include <climits>
#include <limits>
#include <cmath>

using namespace std;


void checkInput(double &input){


    while(!(cin >> input)){

        if(input == LONG_MAX){
            cout << "Error! Value inserted higher than the upper limit accepted. Please insert the value again: ";
        }else if(input == LONG_MIN){
            cout << "Error! Value inserted higher than the lower limit accepted. Please insert the value again: ";
        }else{
            cout << "Invalid Input! Please insert a number as a value: ";
        };

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }


    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


void checkInput(int &input){

    while(!(cin >> input)){

        if(input == INT_MAX){
            cout << "Error! Value inserted higher than the upper limit accepted. Please insert the value again: ";
        }else if(input == INT_MIN){
            cout << "Error! Value inserted higher than the lower limit accepted. Please insert the value again: ";
        }else{
            cout << "Invalid Input! Please insert a number as a value: ";
        };

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }


    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


double calculateCompoundInterest(double balance, double rate, double time, int n = 1){


    return (balance * pow((1 + (rate/100)/n), time) - balance);

}


int main() {

    double principal_balance, rate, time;
    int num;

    cout << "|-|-|-|-|-|-|-|-|-| Compound Interest |-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert the principal balance: " << endl;

    checkInput(principal_balance);


    cout << "Insert the rate of interest (in percentage): " << endl;

    checkInput(rate);

    cout << "Insert the number of times interest is compounded per year (integer input): " << endl;

    checkInput(num);


    cout << "Insert the time (in years): " << endl;

    checkInput(time);

    cout << "Compound Interest: " << calculateCompoundInterest(principal_balance, rate, time, num) << endl;

    return 0;


}

