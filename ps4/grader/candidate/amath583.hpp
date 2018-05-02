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

#include <fstream>
#include <iostream>
#include <string>

#include "COO.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"

#ifdef __TEMPLATED
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <random>

template <typename MatrixType>
void randomize(MatrixType& A) {
  std::default_random_engine             generator;
  std::uniform_real_distribution<double> distribution(2.0, 32.0);
  static auto                            dice = std::bind(distribution, generator);

  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < A.num_cols(); ++j) {
      A(i, j) = dice();
    }
  }
}

template <typename MatrixType>
void zeroize(MatrixType& C) {
  for (size_t i = 0; i < C.num_rows(); ++i) {
    for (size_t j = 0; j < C.num_cols(); ++j) {
      C(i, j) = 0.0;
    }
  }
}

#endif

Vector operator+(const Vector& x, const Vector& y);

void zeroize(Matrix &);
void zeroize(Vector &);
void randomize(Vector &);
void randomize(Matrix &);

Vector operator*(const COOMatrix& A, const Vector& x);
void matvec(const COOMatrix& A, const Vector& x, Vector& y);
void piscetize(COOMatrix& A, size_t xpoints, size_t ypoints);
