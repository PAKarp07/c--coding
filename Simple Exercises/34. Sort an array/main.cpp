#include <iostream>
#include <algorithm>


using namespace std;

void printArray(int* array, int size){

    for(int i = 0; i < size; i++){
        cout << array[i] << " ";

    }

    cout << endl;

}

void bubbleSort(int* array, int size){

    bool swap_flag;

    if(size <= 1)
        return;

    for(int i = 0; i < size - 1; i++){

        swap_flag = false;

        for(int j = 0; j < size - i - 1; j++){

            if(array[j] > array[j+1]){
                swap(array[j], array[j+1]);
                swap_flag = true;
            }

        }

        if(!swap_flag)
            break;

    }



}


void selectionSort(int* array, int size){

    if(size <= 1)
        return;

    for(int i = 0; i < size - 1; i++){

        int min = i;

        for(int j = i + 1; j < size; j++){

            if(array[min] > array[j])
                min = j;
        }

        swap(array[i], array[min]);
    }
}


void insertionSort(int* array, int size){

    if(size <= 1)
        return;

    for(int i = 1; i < size; i++){

        int index = i;

        for(int j = i - 1; j >= 0; j--){

            if(array[index] < array[j]){
                swap(array[index],array[j]);
                index = j;
            }

        }

    }
}



void merge(int* arrayMerged, const int* left, int leftSize, const int* right, int rightSize){

    int leftIndex = 0, rightIndex = 0, mergedIndex = 0;

    while(leftIndex < leftSize && rightIndex < rightSize){

        if(left[leftIndex] <= right[rightIndex]){
            arrayMerged[mergedIndex] = left[leftIndex];
            leftIndex++;

        }else{
            arrayMerged[mergedIndex] = right[rightIndex];
            rightIndex++;

        }
        mergedIndex++;

    }

    while(leftIndex < leftSize){
        arrayMerged[mergedIndex] = left[leftIndex];
        mergedIndex++;
        leftIndex++;

    }

    while(rightIndex < rightSize){
        arrayMerged[mergedIndex] = right[rightIndex];
        mergedIndex++;
        rightIndex++;

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

int partition(int* array, int low, int high){

    int pivot = array[high];
    int left = low - 1;

    for(int i = low; i < high; i++){

        if(array[i] <= pivot){
            left++;
            swap(array[left],array[i]);
        }

    }

    swap(array[left + 1], array[high]);

    return left + 1;

}



void quickSort(int* array, int low, int high){

    if(low < high){

        int index = partition(array, low, high);

        quickSort(array,low, index - 1);
        quickSort(array,index + 1, high);


    }

}


void heapify(int* array, int size, int index){


    int largest = index, left = 2 * index + 1, right = 2 * index + 2;

    if(left < size && array[left] > array[largest])
        largest = left;

    if(right < size && array[right] > array[largest])
        largest = right;

    if(largest != index){
        swap(array[index], array[largest]);

        heapify(array, size, largest);
    }

}




void heapSort(int* array, int size){


    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);

    for(int i = size - 1; i > 0; i--){

        swap(array[0], array[i]);
        heapify(array, i, 0);
    }

}

int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Sort an array |-|-|-|-|-|-|-|-|-|" << endl;

    int array[10] = {4, 6, 21,5,0,12, 33, 21, 13, 54};

    cout << "Original Array" << endl;

    printArray(array, sizeof(array)/sizeof(array[0]));


    cout << "-------------" << endl;
    cout << "Sorted Array" << endl;

    //selectionSort(array, sizeof(array)/sizeof(array[0]));
    //bubbleSort(array, sizeof(array)/sizeof(array[0]));
    //insertionSort(array, sizeof(array)/sizeof(array[0]));
    //mergeSort(array, sizeof(array)/sizeof(array[0]));
    //quickSort(array, 0, sizeof(array)/sizeof(array[0]) - 1);
    heapSort(array, sizeof(array)/sizeof(array[0]));

    printArray(array, sizeof(array)/sizeof(array[0]));



    return 0;
}
