#include <iostream>

using namespace std;


void merge(int* mergedArray, const int* left, int leftSize, const int* right, int rightSize){

    int index_merged = 0, index_left = 0, index_right = 0;

    while(index_left < leftSize && index_right < rightSize){

        if(left[index_left] <= right[index_right]){

            mergedArray[index_merged] = left[index_left];
            index_left++;

        }else{

            mergedArray[index_merged] = right[index_right];
            index_right++;

        }
        index_merged++;
    }


    while(index_left < leftSize){

        mergedArray[index_merged] = left[index_left];
        index_left++;
        index_merged++;
    }

    while(index_right < rightSize){

        mergedArray[index_merged] = right[index_right];
        index_right++;
        index_merged++;
    }


}




void mergeSort(int* array, int size){

    if(size <= 1)
        return;

    int mid = size / 2;

    int left[mid];
    int right[size - mid];

    for(int i = 0; i < mid; i++)
        left[i] = array[i];

    for(int i = mid; i < size; i++)
        right[i - mid] = array[i];


    mergeSort(left, mid);
    mergeSort(right, size - mid);

    merge(array, left, mid, right, size - mid);
}


void printArray(int* array, int size){

    cout  << "[ ";

    for(int i = 0; i < size; i++){


        if(i != size - 1)
            cout << array[i] << ", ";
        else
            cout << array[i];

    }

    cout  << " ]" << endl;
}



int main() {


    cout << "|-|-|-|-|-|-|-|-|-| Merge sort |-|-|-|-|-|-|-|-|-|" << endl;

    int arr[] = {1, 85, 41, 23, 11};
    cout << "Original array: " << endl;

    printArray(arr, sizeof(arr)/sizeof(arr[0]));

    cout << "---------" << endl;

    mergeSort(arr, sizeof(arr)/sizeof(arr[0]));

    cout << "Sorted array: " << endl;

    printArray(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
