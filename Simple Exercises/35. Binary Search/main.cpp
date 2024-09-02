#include <iostream>

using namespace std;


//ORDERED ARRAY
int binarySearch(const int* array, int size, int val){

    int res = -1, left = 0, right = size - 1;

    while(left <= right){

        int mid = left + (right - left) / 2;

        if(array[mid] == val)
            return mid;

        if(array[mid] < val)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return res;
}


int main() {
    cout << "|-|-|-|-|-|-|-|-|-| Sort an array |-|-|-|-|-|-|-|-|-|" << endl;

    int array[10] = {0, 4, 5,6,12,13, 21, 21, 33, 54};

    int value = 12;

    cout << "Value to Search: " << value << endl;

    int index = binarySearch(array,sizeof(array)/sizeof(array[0]),value);

    cout << "The value " << value;

    if(index != -1){

        cout << " is at index " << index;
    }else{
        cout << " was not found in the array";
    }

    cout << endl;

    return 0;
}
