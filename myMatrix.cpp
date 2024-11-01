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

Matrix getMatrixFromFile(){
    ifstream inputFile ("matrix-data-file.txt"); 
    Matrix mat;
    if (inputFile.is_open()){
        int size;
        if (inputFile.good()) {
            inputFile >> size;
            for (int i = 0; i < size;i++){
                for (int j = 0; j<size; j++){
                    
                }
            }
            string line;
            inputFile >> line;
            cout << line;
        }
    }
    inputFile.close();
    return mat;
}

int main(){
    Matrix myMat = getMatrixFromFile();
    //Matrix myMat = Matrix(4);
    //myMat.Print();
    char exit;
    cout << "Enter any character to exit: ";
    cin >> exit;
}