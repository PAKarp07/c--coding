#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


void findPermutations(string& s){

    do{
        cout << s << endl;
    }
    while(next_permutation(s.begin(), s.end()));

    cout << s << endl;
}


void findPermutationsManuallyLoop(string& s, int size, vector<string>& permutations){


    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            swap(s[i], s[j]);

            if(permutations.empty() || find(permutations.begin(),permutations.end(),s) == permutations.end())
                permutations.push_back(s);

            swap(s[i], s[j]);
        }

    }


}


void findPermutationsManuallyRecursive(string& s, int size, vector<string>& permutations, int index = 0){

    if(index == size - 1){

        if(permutations.empty() || find(permutations.begin(),permutations.end(),s) == permutations.end())
            permutations.push_back(s);

    }
    else{
        for(int i = index; i < size; i++){

            swap(s[i], s[index]);
            findPermutationsManuallyRecursive(s, size, permutations, index + 1);
            swap(s[i], s[index]);
        }
    }

}

int main() {


    cout << "|-|-|-|-|-|-|-|-|-| Find all permutations |-|-|-|-|-|-|-|-|-|" << endl;

    string s = "ABA";
    vector<string> p;
    cout << "String being used: '" << s << "'" <<endl;

    cout << "All possible permutations" << endl;


    //findPermutations(s);
    findPermutationsManuallyLoop(s, s.size(), p);
    //findPermutationsManuallyRecursive(s, s.size(), p);


    for (const auto &perm : p) {
        std::cout << perm << std::endl;
    }

    return 0;
}
