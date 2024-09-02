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


bool searchElement(int* array,int size ,int elem){


    int left = 0, right = size - 1;

    while(left < right){

        if(array[left] == elem || array[right] == elem)
            return true;


        left++;
        right--;


    }


    return false;


}


int main() {

    cout << "|-|-|-|-|-|-|-|-|-|-| Find value in array |-|-|-|-|-|-|-|-|-|-|" << endl;

    int elem;
    int array[] = {10, 24, 12, 64, 23, 48, 19, 22};


    cout << "Existing Array: {";

    for(int value: array)
        cout << " " << value << " ";

    cout << "}" << endl;

    cout << "Element to be searched: ";

    checkInput(elem);

    cout << "The number '" << elem <<"' was" << ((searchElement(array, sizeof(array)/sizeof(array[0]), elem)) ? " found" : " not found" ) << " in the array" << endl;

    return 0;
}
