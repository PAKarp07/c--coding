#include <iostream>
#include <fstream>

using namespace std;

int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Appending content to a file |-|-|-|-|-|-|-|-|-|" << endl;

    fstream file1, file2;

    file1.open("content.txt",  ios::in);

    if(!file1.is_open()){

        cout << "File not found!"<< endl;
        return 0;
    }else{

        file2.open("output.txt",  ios::out | ios::app);

        string text;

        while(getline(file1,text)){


            file2 << text << endl;

        }



        file2.close();
        file1.close();
    }

    cout << "Content appended to output successfully!"<< endl;
    return 0;
}
