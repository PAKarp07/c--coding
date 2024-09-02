#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//Function to validate if the input is an integer number
/*void checkInput(string& input){


    while(true){

        getline(cin,input);

        if(input.find_first_not_of("0123456789,.") == string::npos)
            break;


        cerr << "ERROR! The input inserted is not a valid number. Please, try again." << endl;

    }





}*/

int main() {



    cout << "|-|-|-|-|-|-|-|-|-|-| String into int |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert a string that contains only numbers: " << endl;

    string input;

    getline(cin,input);

    cout << "The inserted number is: " << stoi(input) << endl;

    return 0;
}
