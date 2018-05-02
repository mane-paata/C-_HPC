//
// This file is part of the course materials for AMATH483/583 at the University
// of Washington,
// Spring 2018
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0
// International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#ifndef __MATMAT583_HPP
#define __MATMAT583_HPP

#include "Matrix.hpp"
#ifdef __TEMPLATED
template <typename MatrixType>
void multiply(const MatrixType& A, const MatrixType& B, MatrixType& C) {
  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < B.num_cols(); ++j) {
      for (size_t k = 0; k < A.num_cols(); ++k) {
        C(i, j) += A(i, k) * B(k, j);
      }
    }
  }
}

template <typename MatrixType>
void multiply_ijk(const MatrixType& A, const MatrixType& B, MatrixType& C) {
  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < B.num_cols(); ++j) {
      for (size_t k = 0; k < A.num_cols(); ++k) {
        C(i, j) += A(i, k) * B(k, j);
      }
    }
  }
}

template <typename MatrixType>
void multiply_ikj(const MatrixType& A, const MatrixType& B, MatrixType& C) { 
  /* write me */ 
}

template <typename MatrixType>
void multiply_jki(const MatrixType& A, const MatrixType& B, MatrixType& C) {
  /* write me */ 
}
#else
void multiply(const Matrix& A, const Matrix& B, Matrix& C);
#endif

void basicMultiply(const Matrix& A, const Matrix& B, Matrix& C);
void hoistedMultiply(const Matrix& A, const Matrix& B, Matrix& C);
void tiledMultiply2x2(const Matrix& A, const Matrix& B, Matrix& C);
void tiledMultiply2x4(const Matrix& A, const Matrix& B, Matrix& C);
void tiledMultiply4x2(const Matrix& A, const Matrix& B, Matrix& C);
void tiledMultiply4x4(const Matrix& A, const Matrix& B, Matrix& C);
void hoistedTiledMultiply2x2(const Matrix& A, const Matrix& B, Matrix& C);
void blockedTiledMultiply2x2(const Matrix& A, const Matrix& B, Matrix& C);
void hoistedBlockedTiledMultiply2x2(const Matrix& A, const Matrix& B, Matrix& C);
void copyBlockedTiledMultiply2x2(const Matrix& A, const Matrix& B, Matrix& C);
void hoistedCopyBlockedTiledMultiply2x2(const Matrix& A, const Matrix& B, Matrix& C);
void hoistedCopyBlockedTiledMultiply4x4(const Matrix& A, const Matrix& B, Matrix& C);
Matrix operator*(const Matrix& A, const Matrix& B);

#endif    // __MATMAT583_HPP
