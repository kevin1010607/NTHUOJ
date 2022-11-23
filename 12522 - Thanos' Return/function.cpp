#include "function.h"
Matrix::Matrix(int r, int c):row(r), col(c){
    memset(mat, 0, sizeof(mat));
}
int* Matrix::operator[](const int &x){
    return mat[x];
}
Matrix Matrix::operator+(const Matrix &x) const{
    Matrix res(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            res.mat[i][j] = ((mat[i][j]+x[i][j])%MOD+MOD)%MOD;
    return res;
}
Matrix operator*(const Matrix &x, const Matrix &y){
    int r = x.row, c = y.col, t = x.col;
    Matrix res(r, c);
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            for(int k = 0; k < t; k++)
                res[i][j] = ((res[i][j]+x[i][k]*y[k][j])%MOD+MOD)%MOD;
    return res;
}