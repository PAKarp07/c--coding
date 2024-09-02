#include <iostream>
#include <string>
#include <algorithm>

using namespace std;




int main() {



    cout << "|-|-|-|-|-|-|-|-|-| Sorting a string |-|-|-|-|-|-|-|-|-|" << endl;

    string str = "jgjgijsiadassdiopfdjishdasajksda";

    cout << "Original string: '" << str << "'" << endl;

    sort(str.begin(), str.end());

    cout << "Sorted string: '" << str << "'" << endl;

    return 0;
}
