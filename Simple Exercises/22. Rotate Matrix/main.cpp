#include <iostream>


using namespace std;


void rotateMatrix(int nRow, int nCol, int *matrix){


    int offset_row = 0, offset_col = 0;


    while(offset_row < nRow && offset_col < nCol){

        if(offset_row + 1 == nRow || offset_col + 1 == nCol)
            break;

        int prev = *((matrix + (offset_row + 1)*nCol) + offset_col), curr;

        //1st row
        for(int i = offset_col; i < nCol - offset_col; i++){

            curr = *((matrix + i) + offset_row * nCol);
            *((matrix + i) + offset_row * nCol) = prev;
            prev = curr;

        }


        //last column
        for(int i = offset_row + 1; i < nRow - offset_col; i++){

            curr = *((matrix + i * nCol) + nCol - 1 - offset_col);
            *((matrix + i * nCol) + nCol - 1 - offset_col) = prev;
            prev = curr;

        }


        //last row
        for(int i = offset_col + 1; i < nCol - offset_col; i++){

            curr = *((matrix + nRow * nCol - offset_row * nCol) - 1 - i);
            *((matrix + nRow * nCol - offset_row * nCol) - 1 - i) = prev;
            prev = curr;

        }


        //1st column
        for(int i = nRow - 2 - offset_row; i >= offset_row; i--){

            curr = *((matrix + i*nCol) + offset_col);
            *((matrix + i*nCol) + offset_col) = prev;
            prev = curr;

        }

        offset_row++;
        offset_col++;

    }

}

int main() {

    cout << "|-|-|-|-|-|-|-|-|-|-| Rotate a matrix |-|-|-|-|-|-|-|-|-|-|" << endl;

    const int nRow = 4, nCol = 4;

    int matrix[nRow][nCol] = {{12, 34, 2, 42},
                            {24, 11, 4, 21},
                            {25, 13, 9, 16},
                              {29, 45, 256, 98}};



    cout << "Main matrix: " << endl;


    for(int i = 0; i < nRow; i++){
        for(int j = 0; j < nCol; j++)
            cout << matrix[i][j] << " ";

        cout << endl;

    }

    cout << "------" << endl;
    cout << "------" << endl;

    rotateMatrix(nRow, nCol, (int *)matrix);


    cout << "Rotated matrix: " << endl;
    for(int i = 0; i < nRow; i++){
        for(int j = 0; j < nCol; j++)
            cout << matrix[i][j] << " ";

        cout << endl;

    }


    return 0;
}
