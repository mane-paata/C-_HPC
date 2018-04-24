//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2017
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
// 
#if !defined(Matrix_HPP)
#define Matrix_HPP

#include <vector>

#ifndef ALTMatrix
class Matrix {
public: 
  Matrix(int M, int N) : iRows(M), jCols(N), arrayData(iRows*jCols) {}

        float &operator()(int i, int j)       { return arrayData[i*jCols + j]; }
  const float &operator()(int i, int j) const { return arrayData[i*jCols + j]; }
  
  int numRows() const { return iRows; }
  int numCols() const { return jCols; }

private:
  int iRows, jCols;
  std::vector<float> arrayData;
};
#else
class Matrix {
public: 
//----------------------------------------------------------------
// Your implemenation goes here.
// Note that you can also ifdef particular parts of the above
// You should provide all the same member functions
//----------------------------------------------------------------

private:
  int iRows, jCols;
  std::vector<vector<float> >arrayData;
};

#endif // ALTFloatingFloating


Matrix operator*(const Matrix& A, const Matrix &B);
Matrix operator+(const Matrix& A, const Matrix &B);
Matrix operator-(const Matrix& A, const Matrix &B);
float frobeniusNorm(const Matrix& A);
void multiply(const Matrix& A, const Matrix &B, Matrix& C);
void hoistedMultiply(const Matrix& A, const Matrix &B, Matrix& C);
void tiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void blockedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void tiledMultiply2x4(const Matrix& A, const Matrix&B, Matrix&C);
void tiledMultiply4x2(const Matrix& A, const Matrix&B, Matrix&C);
void tiledMultiply4x4(const Matrix& A, const Matrix&B, Matrix&C);
void copyBlockedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedBlockedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedCopyBlockedTiledMultiply2x2(const Matrix& A, const Matrix&B, Matrix&C);
void hoistedCopyBlockedTiledMultiply4x4(const Matrix& A, const Matrix&B, Matrix&C);
float oneNorm(const Matrix& A);
float infinityNorm(const Matrix& A);
float frobeniusNorm(const Matrix& A);
void zeroizeMatrix(Matrix& C);
void randomizeMatrix(Matrix &A);

#endif // Matrix_HPP
