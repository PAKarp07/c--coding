#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


void printSet(const set<int>& s){

    cout << "Values on a set: { ";

    std::for_each(s.begin(), s.end(),[](int value){
        cout << value << " ";
    });
    cout << "}" << endl;

}


int findMax(const set<int>& s){


    if(s.empty())
        throw runtime_error("ERROR! Cannot find maximum on set since it is empty");

    return *s.rbegin();
}

int findMin(const set<int>& s){


    if(s.empty())
        throw runtime_error("ERROR! Cannot find minimum on set since it is empty");

    return *s.begin();
}

int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Find max and min on a set |-|-|-|-|-|-|-|-|-|" << endl;

    set<int> s;
    int inputs[] = {14,4,2,123,64,43,85,52,982,1000,1002};

    s.insert(inputs, inputs + sizeof(inputs)/sizeof(inputs[0]));

    printSet(s);


    try{

        cout << "Max value: " << findMax(s) << endl;
        cout << "Min value: " << findMin(s) << endl;


    }catch(runtime_error &e){

        cout << "Exception occurred" << endl << e.what() <<  endl;
    }

    return 0;
}
