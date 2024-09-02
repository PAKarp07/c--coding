#include <iostream>
#include <limits>
#include <climits>
#include <ctime>
#include <algorithm>

using namespace std;

/*void checkInput(int &input){


    while(!(cin >> input)){

        switch (input) {

            case INT_MAX:
                cout << "Error! Value inserted higher than the upper limit accepted. Please insert the value again: ";
                break;

            case INT_MIN:
                cout << "Error! Value inserted higher than the lower limit accepted. Please insert the value again: ";
                break;

            default:
                cout << "Invalid Input! Please insert a number as a value: ";
                break;

        }


        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}*/


int maxLoopMethod(const int* array, int size){



    if(!array){
        cout << "ERROR! Invalid array! Closing program...";
        exit(0);
    }

    int max = array[0];

    for (int i = 1; i < size; ++i) {

        if(max < array[i])
            max = array[i];

    }

    return max;
};


int maxStartEndIndexMethod(const int* array, int size){


    if(!array){
        cout << "ERROR! Invalid array! Closing program...";
        exit(0);
    }

    int max = array[0];
    int right = 0, left = size-1;


    while(right < left){

        if(array[right] > array[left]){
            max = array[right];
            left--;
        }else{
            max = array[left];
            right++;
        }


    }

    return max;
};


int maxRecursiveMethod(const int* array, int size, int index = 0){


    if(!array){
        cout << "ERROR! Invalid array! Closing program...";
        exit(0);
    }


    if(index == size - 1){
        return array[index];
    }

    return max(array[index], maxRecursiveMethod(array, size, index + 1));

};

int maxLibraryMethod(const int* array, int size){


    if(!array){
        cout << "ERROR! Invalid array! Closing program...";
        exit(0);
    }


    return *max_element(array, array + size);
};


int main() {

    int values[] = {1, 5 ,8, 21};

    cout << "|-|-|-|-|-|-|-|-|-|-| Find largest number |-|-|-|-|-|-|-|-|-|-|" << endl;

    cout << "Array of values: [";
    for(int i = 0; i < sizeof(values)/sizeof(values[0]); i++){

        if(i == (sizeof(values)/sizeof(values[0]))-1)
            cout << values[i] << "]" << endl;
        else
            cout << values[i] << ", ";

    };

    //int result = maxLoopMethod(values, sizeof(values)/sizeof(values[0]));
    //int result = maxStartEndIndexMethod(values, sizeof(values)/sizeof(values[0]));
    //int result = maxRecursiveMethod(values, sizeof(values)/sizeof(values[0]));
    int result = maxLibraryMethod(values, sizeof(values)/sizeof(values[0]));

    cout << "Max with normal loop method: " << result << endl;


    return 0;
}
