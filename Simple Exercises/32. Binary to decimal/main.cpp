#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>
#include <bitset>

using namespace std;

void checkBinaryInput(string &input){

    while(true){

        getline(cin, input);


        if(input.find_first_not_of("01") == string::npos)
            break;

        cerr << "ERROR! The inserted value is not a binary number. Please, try again!" << endl;


    }


}


[[maybe_unused]] int btod(int binary){

    int res = 0, power = 0;

    while(binary != 0){

        int lsb = binary % 10;

        res += lsb * int(pow(2,power));
        power++;
        binary /= 10;


    }

    return res;
}


int main() {
    cout << "|-|-|-|-|-|-|-|-|-| Pascal's Triangle |-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert a binary number: " << endl;

    string input;

    checkBinaryInput(input);

    //cout << "Number in decimal: " << btod(stoi(input)) << endl;

    bitset<4> bits(input);
    cout << "Number in decimal: " << bits.to_ulong() << endl;

    return 0;
}
