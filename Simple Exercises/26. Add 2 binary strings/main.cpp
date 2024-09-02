#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


void checkBinaryInput(string& input){

    while(true){

        getline(cin, input);

        if(input.find_first_not_of("01") == string::npos){
            break;
        }


        cerr << "ERROR! The inserted value is not a binary number. Please, try again!" << endl;

    }



}



void addBinary(string str_a, string str_b, string& result){


    if(int(str_a.length() - str_b.length()) > 0 || int(str_a.length() - str_b.length()) < 0) {

        string prefix = string(abs(int(str_a.length() - str_b.length())), '0');

        (int(str_a.length() - str_b.length()) > 0) ? str_b.insert(0,prefix) : str_a.insert(0,prefix);

    }

    char c = '0';

    for(int i = int(str_a.length()) - 1; i >= 0; i--){

        result.push_back(char((str_a[i] ^ str_b[i]) ^ c));
        c = char((str_a[i] & str_b[i]) | (c & str_b[i]) | (str_a[i] & c));


    }


    if(c == '1'){

        result.push_back(c);
    }

    reverse(result.begin(),result.end());


}


int main() {


    cout << "|-|-|-|-|-|-|-|-|-|-| Add 2 binary strings |-|-|-|-|-|-|-|-|-|-|" << endl;

    string first_input, second_input, result;

    cout << "Insert the first binary number: " << endl;

    checkBinaryInput(first_input);

    cout << "Insert the second binary number: " << endl;

    checkBinaryInput(second_input);

    addBinary(first_input, second_input, result);

    cout << "Result: " << result << endl;

    return 0;
}
