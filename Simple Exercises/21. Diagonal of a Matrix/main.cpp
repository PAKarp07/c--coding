#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;


void checkMatrixDims(string& input, int* dims){


    while(getline(cin, input)){

        if(input.find('x') == string::npos && input.find('X') == string::npos)

            cerr << "ERROR! Missing the \"x\" in the input. The input format is [NUMBER_OF_ROWS]x[NUMBER_OF_COLUMNS]. Please insert the dimensions again."<< endl;

        else{


            if(count(input.begin(), input.end(), 'x') > 1 || count(input.begin(), input.end(), 'X') > 1 || count(input.begin(), input.end(), 'X') + count(input.begin(), input.end(), 'x') > 1){
                cerr << "ERROR! Multiple \"x\" detected in the input. The input format is [NUMBER_OF_ROWS]x[NUMBER_OF_COLUMNS]. Please insert the dimensions again."<< endl;

            }else{

                input.erase(remove(input.begin(), input.end(), ' '), input.end());

                stringstream string_dim(input);
                string dim;
                char dim_separator =  (input.find('x') != string::npos) ? 'x' : 'X';
                int index = 0;

                while(getline(string_dim,dim,dim_separator)){

                    if(dim.find_first_not_of("0123456789") == string::npos){

                        try{


                            if(stoi(dim) <= 0){
                                cerr << "ERROR! Dimensions for rows and columns must be 1 or higher. Please insert the dimensions again."<< endl;
                                index = 0;
                                break;
                            }

                            dims[index] = stoi(dim);


                            index++;

                        }catch(...){

                            cerr << "ERROR! One of the dimensions is higher than the upper limit accepted. Please insert the dimensions again." << endl;
                            index = 0;
                            break;

                        }



                    }else{
                        cerr << "ERROR! Detected an invalid value in for the number of rows or/and columns. Make sure the dimensions are integer numbers separated with a \"x\". Please insert the dimensions again."<< endl;
                        index = 0;
                        break;
                    }

                }


                if(index != 0){
                    break;
                }

            }

        }


    }


}

void checkMatrixValues(string& input, const int* dims, double* matrix){

    for(int i = 0; i < dims[0]; i++){


        cout << "Insert values for the row number #" << i + 1 << endl;
        cout << R"((The decimal separator are considered equal. Do not insert both "." and "," in the same value.))" << endl;

        while(getline(cin, input)){


            stringstream string_val(input);
            string val;
            int count_val = 0;

            while(getline(string_val, val, ' ')){

                if(val.length()==0)
                    continue;


                if(val.find_first_not_of("0123456789,.") == string::npos){


                    try{

                        if(count(val.begin(), val.end(), '.') > 1 || count(val.begin(), val.end(), ',') > 1 || count(val.begin(), val.end(), ',') + count(val.begin(), val.end(), '.') > 1){

                            cerr << "ERROR! A value inserted has multiple '.' and/or ','. Each value in the matrix must be a valid numeric value." << endl;
                            break;
                        }

                        replace(val.begin(), val.end(), ',', '.');
                        matrix[i*dims[1] + count_val] = stod(val);
                        count_val++;


                    }catch(...){
                        cerr << "ERROR! A value inserted was not valid. Each value in the matrix must be a valid numeric value." << endl;
                        break;
                    }




                }else{
                    cerr << "ERROR! A value inserted was not valid. Each value in the matrix must be a valid numeric value." << endl;
                    break;
                }



            }

            if(count_val == dims[1]){
                break;

            }else{
                count_val = 0;
                cerr << "ERROR! The number of values must correspond to the columns of the matrix. (columns = " << dims[1] << "). Please insert the values of the row #"<< i+1 << " again." << endl;

            }


        }

    }





}



int main() {

    cout << "|-|-|-|-|-|-|-|-|-|-| Main diagonal of a matrix |-|-|-|-|-|-|-|-|-|-|" << endl;

    string input;
    int dims[] = {0, 0};



    cout << "First, insert the dimensions of the matrix." << endl;
    cout << "(insert in the following format -> [NUMBER_OF_ROWS]x[NUMBER_OF_COLUMNS])" << endl;

    checkMatrixDims(input, dims);

    cout << "Inserted dimensions: { " << dims[0] << ", " << dims[1] << " }" << endl;

    double matrix[dims[0]*dims[1]];

    cout << "Now, insert the values of the matrix for each row." << endl;
    cout << "Insert the values in the row separated by a space. Example: 1 2 4 5" << endl;

    checkMatrixValues(input, dims, matrix);


    cout << "Inserted matrix: " << endl;

    for(int i = 0; i < sizeof(matrix)/sizeof(matrix[0]) ; i++)
    {

        cout << matrix[i] << " ";

        if((i+1) % dims[1] == 0)
            cout << endl;
    }


    double p_diagonal = 0, s_diagonal = 0;

    for(int i = 0; i < (dims[0] >= dims[1]) ? dims[1] : dims[0]; i++){

        p_diagonal += matrix[i*(dims[1] + 1)];
        s_diagonal += matrix[(dims[1]-1) + i*(dims[1]-1)];

    }

    cout << "Principal Diagonal: " << p_diagonal << endl;
    cout << "Secondary Diagonal: " << s_diagonal << endl;

    return 0;
}
