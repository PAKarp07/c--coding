#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "|-|-|-|-|-|-|-|-|-| Creating a new file |-|-|-|-|-|-|-|-|-|" << endl;

    ofstream newFile("log.txt");

    newFile << "This is a log to this file";

    newFile.close();

    cout << "File created successfully!" << endl;
    return 0;
}
