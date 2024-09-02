#include <iostream>
#include <string>
#include <climits>
#include <limits>

using namespace std;


int main() {


    cout << "|-|-|-|-|-|-|-|-|-|-| Compare two strings |-|-|-|-|-|-|-|-|-|-|" << endl;

    string first_string;
    string second_string;

    cout << "Insert the first string: " << endl;

    getline(cin,first_string);

    cout << "Insert the second string: " << endl;

    getline(cin,second_string);

    cout << "The string '" << first_string << "' is " << ((first_string == second_string) ? "equal to" : "not equal to") << " the string '" << second_string << "'" << endl;


    return 0;
}
