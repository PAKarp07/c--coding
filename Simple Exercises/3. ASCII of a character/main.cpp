#include <iostream>
#include <climits>
#include <limits>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {


    char c;

    cout << "WARNING: If more than 2 characters are inserted, it will only count the first one." << endl;
    cout << "Input a character: ";
    cin >> c;


    cout << "ASCCI Value of '" << c << "' = " << int(c) << endl;
    return 0;


}
