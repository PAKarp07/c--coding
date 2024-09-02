#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "|-|-|-|-|-|-|-|-|-|-| Length if a string |-|-|-|-|-|-|-|-|-|-|" << endl;

    string input;


    getline(cin,input);

    cout << "Size of the inputted string: " << input.size() << endl;

    return 0;
}
