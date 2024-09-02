#include <iostream>
#include <climits>
#include <limits>
#include <cstring>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


string reverseString(string str, int index = 0){


    if(index + 1 == str.length())
        return string(1,str[index]);

    string str_temp = string(1,str[index]);

    return reverseString(str, index+1).append(str_temp);


}



int main() {

    string input;

    cout << "|-|-|-|-|-|-|-|-|-|-| Reversing a string |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert a phrase: " << endl;

    getline(cin,input);

    cout << "Input: " << input << endl;
    cout << "Reversed input: " << reverseString(input) << endl;

    return 0;
}
