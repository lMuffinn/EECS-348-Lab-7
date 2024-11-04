/*
Matrix
Description: Reads and manipulates matrix data from a file
Author: Matthew Eagleman
*/
#include <iostream>
#include <fstream>
using namespace std;
class Matrix{
    private:
        int size;
        double** tdarr;
    public:
        Matrix(int s = 4){
            //Create a new matrix filled with zeroes
            size = s;
            tdarr = new double*[s];
            for (int i = 0; i < s; i++) {
                tdarr[i] = new double[s];
            }
            for (int i = 0; i<s;i++){
                for(int j=0; j<s; j++){
                    tdarr[i][j] = 0;
                }
            }
        }
        Matrix operator+(Matrix const& obj){
            //Overload the + operator to perform matrix addition
            Matrix res = Matrix(size);
            for (int row = 0; row<size;row++){
                for (int col = 0; col < size; col++){
                    int value = tdarr[row][col] + obj.tdarr[row][col];
                    res.Append(value,row,col);
                }
            }
            return res;
        }
        Matrix operator*(Matrix const& obj){
            //Overload the * operator to perform matrix multiplication
            Matrix res = Matrix(size);
            for (int row = 0; row < size; row++){
                for (int col = 0; col < size; col++){
                    int value = 0;
                    for (int i = 0; i < size; i++){
                        value += tdarr[row][i] * obj.tdarr[i][col];
                    }
                    res.Append(value,row,col);
                }
            }
            return res;
        }
        int getDiagonalSum(){
            //Return the sum of all the diagonal elements in the matrix
            int sum = 0;
            for (int row = 0; row<size;row++){
                sum += tdarr[row][row] + tdarr[row][size-1-row];
            }
            return sum;
        }
        void SwapRows(int r1,int r2){
            //Swap two rows of the matrix
            double* temp = tdarr[r1];
            tdarr[r1] = tdarr[r2];
            tdarr[r2] = temp;
        }
        void Print(){
            //Print the matrix
            for (int i = 0; i<size;i++){
                cout << "\n";
                for (int j = 0; j<size;j++){
                    cout << tdarr[i][j] << " ";
                }
            }
        }
        void Append(double value, int row, int col){
            //Change a value in the matrix
            tdarr[row][col] = value;
        }
};

Matrix getMatrixFromFile(char mode = '1'){
    //Get a matrix from a file
    //'1' will get the first matrix, '2' will get the second
    ifstream inputFile ("matrix-data-file.txt"); 
    Matrix mat;
    if (inputFile.is_open()){
        if (inputFile.good()) {
            int size;
            inputFile >> size;
            mat = Matrix(size);
            if (mode == '2'){
                for (int i = 0; i< size*size;i++){
                    string dummy;
                    inputFile >> dummy;
                }
            }
            for (int i = 0; i < size;i++){
                for (int j = 0; j<size; j++){
                    int value;
                    inputFile >> value;
                    mat.Append(value,i,j);
                }
            }
        }
    }
    inputFile.close();
    return mat;
}

int main(){
    //Getting input from the inputFile
    Matrix m1_ = getMatrixFromFile();
    Matrix m2_ = getMatrixFromFile('2');
    //Performing and printing different operations
    cout << "Matrix 1 (M1):";
    m1_.Print();
    cout << "\n\nMatrix 2 (M2):";
    m2_.Print();
    cout << "\n\nM1 + M2:";
    (m1_+m2_).Print();
    cout << "\n\nM1 * M2:";
    (m1_*m2_).Print();
    cout << "\n\nM1 Diagonal Sum:\n" << m1_.getDiagonalSum();
    cout << "\n\nM2 Diagonal Sum:\n" << m2_.getDiagonalSum();
    cout << "\n\nResult of swapping rows 1 and 2 of M1";
    m1_.SwapRows(0,1);
    m1_.Print();
    cout << "\n\nResult of swappoing rows 2 and 3 of M2";
    m2_.SwapRows(1,2);
    m2_.Print();
    //Exiting
    char exit;
    cout << "\n\nType anything and press enter to exit: ";
    cin >> exit;
}