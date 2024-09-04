#include <iostream>
#include <climits>
#include <limits>

using namespace std;



void checkInput(double& input){

    while(!(cin >> input)){

        if(input == LONG_MAX)
            cerr << "ERROR! The value inserted is higher than the limit accepted. Please, insert a lower value." << endl;
        else if(input == LONG_MIN)
            cerr << "ERROR! The value inserted is lower than the limit accepted. Please, insert a higher value." << endl;
        else
            cerr << "ERROR! The value inserted is invalid. Please, insert a valid number." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

double division(double num, double dem){

    if(dem == 0){
        throw runtime_error("Math error - Attempt to divide to zero\n");
    }

    return (num / dem);

}


int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Division calculator |-|-|-|-|-|-|-|-|-|" << endl;

    double num, dem;
    cout << "Insert the numerator" << endl;
    checkInput(num);

    cout << "Insert the dominator" << endl;
    checkInput(dem);

    try{

        double result = division(num,dem);

        cout << "Result of the division: " << result << endl;

    }
    catch (runtime_error &e){

        cout << "Exception occurred."<< endl << e.what() << endl;
    }


    return 0;
}
