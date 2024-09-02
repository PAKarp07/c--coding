#include <iostream>
#include <bits/stdc++.h>


using namespace std;


double findMaxFromArray(double* array, int size){


    return *max_element(array, array + size);
}

double findMinFromArray(double* array, int size){


    return *min_element(array, array + size);
}


int main() {



    double array[] = {1, 15, 6, 4, 51, 63,75, 8, 9, 10};

    cout << "Array: {";

    for(int value: array)
        cout << " " << value << " ";

    cout << "}" << endl;



    cout << "Maximum = " << findMaxFromArray(array, sizeof(array)/sizeof(array[0])) << endl;
    cout << "Minimum = " << findMinFromArray(array, sizeof(array)/sizeof(array[0])) << endl;

    return 0;
}
