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
#ifndef __MATVEC583_HPP
#define __MATVEC583_HPP

#include "Vector.hpp"
#include "Matrix.hpp"

#ifdef __TEMPLATED

template <typename MatrixType, typename VectorType>
VectorType operator*(const MatrixType& A, const VectorType& x) {
  Vector b(x.num_rows());
  for (size_t i = 0; i < A.num_rows(); ++i) {
    for(size_t j = 0; j < A.num_cols(); ++j){
      b(i) +=  A(i,j) * x(j);
    }
  }
  return b;
}

template <typename MatrixType, typename VectorType>
void matvec(const MatrixType& A, const VectorType& x, VectorType& y) {
  for(size_t i = 0; i < A.num_rows(); ++i){
    for(size_t j = 0; j < A.num_cols(); ++j){
      y(i) += A(i,j) * x(j);
    }
  }
}

template <typename MatrixType, typename VectorType>
void matvec_ij(const MatrixType& A, const VectorType& x, VectorType& y) {
  for(size_t i = 0; i < A.num_rows(); ++i){
    for(size_t j = 0; j < A.num_cols(); ++j){
      y(i) += A(i,j) * x(j);
    }
  } 
}

template <typename MatrixType, typename VectorType>
void matvec_ji(const MatrixType& A, const VectorType& x, VectorType& y) {
  for(size_t j = 0; i < A.num_cols(); ++j){
    for(size_t i = 0; i < A.num_rows(); ++i){
      y(i) = A(i,j) * x(j);
    }
  }
}
   
#else

Vector operator*(const Matrix& A, const Vector& x);
void matvec(const Matrix& A, const Vector& x, Vector& y);
void matvec_ij(const Matrix& A, const Vector& x, Vector& y);
void matvec_ji(const Matrix& A, const Vector& x, Vector& y);

#endif


#endif // __MATVEC583_HPP
