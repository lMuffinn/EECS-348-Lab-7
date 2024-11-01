#include <iostream>
#include <fstream>

using namespace std;

class Matrix{
    private:
        int size;
        double** tdarr;
    public:
        Matrix(int s = 4){
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
        void Print(){
            for (int i = 0; i<size;i++){
                cout << "\n";
                for (int j = 0; j<size;j++){
                    cout << tdarr[i][j] << " ";
                }
            }
        }
        void Append(double value, int row, int col){
            tdarr[row][col] = value;
        }
};

Matrix getMatrixFromFile(char mode = '1'){
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
    Matrix m1_ = getMatrixFromFile();
    Matrix m2_ = getMatrixFromFile('2');
    m1_.Print();
    m2_.Print();
    char exit;
    cout << "\nType anything and press enter to exit: ";
    cin >> exit;
}