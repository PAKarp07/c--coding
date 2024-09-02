#include <iostream>
#include <limits>
#include <climits>


using namespace std;


bool cmpArraysLoopMethod(const int* array1, const int* array2, int size1, int size2){

    if(size1 != size2)
        return false;


    for(int i = 0; i < size1; i++)
        if(array1[i] != array2[i])
            return false;

    return true;


}


bool cmpArraysRecursionMethod(const int* array1, const int* array2, int size){


    if(array1[size-1] == array2[size-1])
        if(size > 0)
           return cmpArraysRecursionMethod(array1, array2, size-1);

    if(size == 0)
        return true;


    return false;

}

bool cmpArraysRecursionInit(const int* array1, const int* array2, int size1, int size2){

    if(size1 != size2)
        return false;

    if(size1 == 0 && size2 == 0)
        return true;

    return cmpArraysRecursionMethod(array1, array2, size1);


}


int main() {

    int array1[] = {1, 4, 7, 8};
    int array2[] = {1, 4, 7, 8, 10, 23};
    int array3[] = {0, 4, 1, 82};
    int array4[] = {1};
    int array5[] = {1, 2, 3, 4, 5, 6,7, 8, 9, 10};
    int array6[] = {1, 4, 7, 8};
    int array7[] = {1};
    int array8[] = {1, 4, 7, 8, 9};
    int array9[] = {1, 2, 3, 4, 5, 6,7, 8, 9, 10};
    int array10[] = {};


    cout << "Equal array? " << cmpArraysRecursionInit(array1,array3,sizeof(array1)/sizeof(array1[0]),sizeof(array3)/sizeof(array3[0])) << endl;
    return 0;
}
