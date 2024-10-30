#include <iostream>

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
};

Matrix getMatrixFromFile(){
    return Matrix(4);
}

int main(){
    Matrix myMat = Matrix(4);
    myMat.Print();
    char exit;
    cin >> exit;
}