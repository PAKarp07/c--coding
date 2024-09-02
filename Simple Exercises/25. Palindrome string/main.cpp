#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    cout << "|-|-|-|-|-|-|-|-|-|-| Palindrome strings |-|-|-|-|-|-|-|-|-|-|" << endl;

    string input;

    cout << "Insert a string:" << endl;

    getline(cin,input);

    string aux = input;

    reverse(aux.begin(), aux.end());


    cout << "The string '" << input << "' is " << (input == aux ? "a palindrome string." : "not a palindrome string.") << endl;



    return 0;
}
