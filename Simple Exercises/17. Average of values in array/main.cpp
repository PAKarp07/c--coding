#include <iostream>
#include <limits>
#include <climits>


using namespace std;


double averageLoop(const int *array, int size){


    double avg = 0;

    for(int i = 0; i < size; i++)
        avg += array[i];

    return avg/size;

}


int main() {

    int array[] = {1, 15, 6, 4, 51, 63,75, 8, 9, 10};

    cout << "Array: {";

    for(int value: array)
        cout << " " << value << " ";

    cout << "}" << endl;



    cout << "Average: " << averageLoop(array, sizeof(array)/sizeof(array[0])) << endl;

    return 0;


}
