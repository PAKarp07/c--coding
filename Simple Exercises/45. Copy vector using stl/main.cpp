#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Vector copying using STL |-|-|-|-|-|-|-|-|-|" << endl;

    vector<int> vector1 = {3, 1, 5, 6, 10, 2, 3, 5};
    vector<int> vector2;

    cout << "Original vectors:" << endl;

    cout << "Vector nº1: { ";

    for(auto elem : vector1)
        cout << elem << " ";

    cout << "}" << endl;

    cout << "Vector nº2: { ";

    for(auto elem : vector2)
        cout << elem << " ";

    cout << "}" << endl;

    cout << "-----------" << endl;

    copy(vector1.begin(), vector1.end(), back_inserter(vector2));

    cout << "Vector nº1 copied to vector nº2: { ";

    for(auto elem : vector2)
        cout << elem << " ";

    cout << "}" << endl;


    return 0;
}
