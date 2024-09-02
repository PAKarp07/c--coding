#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;


void split_vector_sol(string input, vector<string>& output){

    size_t pos = 0;
    string delimiter = " ";

    while((pos = input.find(delimiter)) != string::npos){

        output.push_back(input.substr(0,pos));
        input.erase(0, pos + delimiter.length());

    }

    output.push_back(input);


}

void split_tok(string input){

    char* string_char = input.data();
    char * split_string;

    split_string = strtok(string_char, " ");

    cout << "---Words on the string inserted---" << endl;

    while(split_string != NULL){

        cout << split_string << endl;
        split_string = strtok(NULL, " ");
    }


}


int main() {


    cout << "|-|-|-|-|-|-|-|-|-|-| Divide string by its words |-|-|-|-|-|-|-|-|-|-|" << endl;
    cout << "Insert a string: " << endl;

    string input;
    vector<string> split_input;

    getline(cin, input);

    split_vector_sol(input, split_input);


    cout << "---Words on the string inserted---" << endl;

    for(const auto &word : split_input){

        cout << word << endl;
    }


    return 0;
}
