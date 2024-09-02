//
// Created by paulo on 29/08/2024.
//




#include <iostream>
#include <algorithm>


using namespace std;

void selectionSort(int* array, int size){

    if(size <= 1)
        return;

    for(int i = 0; i < size - 1; i++){

        int min = i;

        for(int j = i + 1; j < size; j++){

            if(array[min] > array[j]){
                min = j;
            }

        }

        swap(array[i], array[min]);
    }

}


void bubbleSort(int* array, int size){

    bool swap_flag;

    if(size <= 1)
        return;

    for(int i = 0; i < size - 1; i++){

        swap_flag = false;

        for(int j = 0; j < size - i - 1; j++){

            if(array[j] > array[j+1]){
                swap_flag = true;
                swap(array[j], array[j+1]);
            }
        }

        if(!swap_flag)
            break;
    }
}


void insertionSort(int* array, int size){

    if(size <= 1)
        return;

    for(int i = 1; i < size; i++){

        int index = i;

        for(int j = i - 1; j >= 0; j--){

            if(array[j] > array[index]){
                swap(array[j], array[index]);
                index = j;
            }


        }


    }


}

void merge(int* array, int* arr_left, int leftSize, int* arr_right, int rightSize){

    int left = 0, right = 0, indexMerged = 0;

    while(left < leftSize && right < rightSize){

        if(arr_left[left] <= arr_right[right]){

            array[indexMerged] = arr_left[left];
            left++;
        }else{
            array[indexMerged] = arr_right[right];
            right++;
        }
        indexMerged++;

    }


    while(left < leftSize){
        array[indexMerged] = arr_left[left];
        left++;
        indexMerged++;
    }

    while(right < rightSize){
        array[indexMerged] = arr_right[right];
        right++;
        indexMerged++;
    }

}


void mergeSort(int* array, int size){

    if(size <= 1)
        return;

    int mid = size / 2 ;

    int left[mid];
    int right[size - mid];

    for(int i = 0; i < mid; i++){
        left[i] = array[i];
    }

    for(int i = mid; i < size; i++){
        right[i - mid] = array[i];
    }

    mergeSort(left,mid);
    mergeSort(right,size - mid );

    merge(array, left, mid, right, size - mid);

}


