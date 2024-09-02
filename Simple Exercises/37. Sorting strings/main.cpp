#include <iostream>
#include <string>


using namespace std;



void printArray(string* array, int size){

    cout << "[ ";

    for(int i = 0; i < size; i++){

        if(i != size - 1){

            cout << array[i] << ", ";
        }else{
            cout << array[i];
        }
    }

    cout << " ]" << endl;

}


void insertionSort(string* array, int size){



    for(int i = 1; i < size; i++){

        int index = i - 1;

        for(int j = i - 1; j >= 0; j--){


            if(array[index].compare(array[j]) < 0){
                swap(array[index], array[j]);
                index = j;
            }


        }

    }
}


int main() {

    cout << "|-|-|-|-|-|-|-|-|-| Sorting array of strings |-|-|-|-|-|-|-|-|-|" << endl;

    string array_names[] = {"Manuel", "João", "Paulo", "Marco", "António", "Bernardo", "Cristiano", "Ricardo", "Samuel", "Pedro","Sara", "Gabriela", "Ana", "Diana", "Sofia"};

    cout << "Original order:" << endl;

    printArray(array_names, sizeof(array_names)/sizeof(array_names[0]));

    cout << "Alphabetic order:" << endl;

    insertionSort(array_names, sizeof(array_names)/sizeof(array_names[0]));

    printArray(array_names, sizeof(array_names)/sizeof(array_names[0]));
    return 0;
}
