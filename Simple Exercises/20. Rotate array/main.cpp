#include <iostream>
#include <limits>
#include <climits>


using namespace std;


void checkInput(int &input){

    while(!(cin >> input)){

        switch (input) {

            case INT_MAX:
                cout << "Error! Value inserted higher than the upper limit accepted. Please insert the value again: " << endl;
                break;
            case INT_MIN:
                cout << "Error! Value inserted higher than the lower limit accepted. Please insert the value again: " << endl;
                break;
            default:
                cout << "Invalid Input! Please insert an integer number as a value: " << endl;
                break;


        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


void rotateArray(int* array, int size, int ktimes){

    if(ktimes >= size){

        if(ktimes % size == 0)
            return;

        ktimes = ktimes % size;
    }else if(size == 0 || size == 1){
        return;
    }

    int temp_value = array[ktimes], index = ktimes;
    array[ktimes] = array[0];


    while(index != 0){

        index = (index + ktimes >= size) ? index + ktimes - size : index + ktimes;

        array[index] = array[index] ^ temp_value;
        temp_value = array[index] ^ temp_value;
        array[index] = array[index] ^ temp_value;

    }


}



int main() {

    int k;

    cout << "|-|-|-|-|-|-|-|-|-|-| Rotate array |-|-|-|-|-|-|-|-|-|-|" << endl;

    int array[] = {10, 24, 12, 64, 23};


    cout << "Existing Array: {";

    for(int value: array)
        cout << " " << value << " ";

    cout << "}" << endl;


    cout << "Times to rotate the array: ";


    checkInput(k);

    rotateArray(array, sizeof(array)/sizeof(array[0]),k);


    cout << "Rotated array: {";
    for(int value: array)
        cout << " " << value << " ";

    cout << "}" << endl;


    return 0;
}
