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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <random>
#include <string>

#include "COO.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "amath583.hpp"

Vector operator+(const Vector& x, const Vector& y) {
  Vector z(x.num_rows());
  for (size_t i = 0; i < x.num_rows(); ++i) {
    z(i) = x(i) + y(i);
  }
  return z;
}

void zeroize(Vector& x) {
  for (size_t i = 0; i < x.num_rows(); ++i) {
    x(i) = 0;
  }
}

void randomize(Vector& x) {
  static std::default_random_engine generator;
  static std::uniform_real_distribution<double> distribution(-1.0, 1.0);
  static auto dice = std::bind(distribution, generator);

  for (int i = 0; i < x.num_rows(); ++i) {
    x(i) = dice();
  }
}

void randomize(Matrix& A) {
  std::default_random_engine             generator;
  std::uniform_real_distribution<double> distribution(2.0, 32.0);
  static auto                            dice = std::bind(distribution, generator);

  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < A.num_cols(); ++j) {
      A(i, j) = dice();
    }
  }
}

void zeroize(Matrix& C) {
  for (size_t i = 0; i < C.num_rows(); ++i) {
    for (size_t j = 0; j < C.num_cols(); ++j) {
      C(i, j) = 0.0;
    }
  }
}

Vector operator*(const COOMatrix& A, const Vector& x) {
  assert(A.num_cols() == x.num_rows());

  Vector y(A.num_rows());
  matvec(A, x, y);

  return y;
}

void matvec(const COOMatrix& A, const Vector& x, Vector& y) { A.matvec(x, y); }

void piscetize(COOMatrix& A, size_t xpoints, size_t ypoints) {
  assert(A.num_rows() == A.num_cols());
  assert(xpoints * ypoints == A.num_rows());

  A.clear();

  for (size_t j = 0; j < xpoints; j++) {
    for (size_t k = 0; k < ypoints; k++) {
      size_t jrow = j * ypoints + k;

      if (j != 0) {
        size_t jcol = (j - 1) * ypoints + k;
        A.push_back(jrow, jcol, -1.0);
      }
      if (k != 0) {
        size_t jcol = j * ypoints + (k - 1);
        A.push_back(jrow, jcol, -1.0);
      }

      A.push_back(jrow, jrow, 4.0);

      if (k != ypoints - 1) {
        size_t jcol = j * ypoints + (k + 1);
        A.push_back(jrow, jcol, -1.0);
      }
      if (j != xpoints - 1) {
        size_t jcol = (j + 1) * ypoints + k;
        A.push_back(jrow, jcol, -1.0);
      }
    }
  }
}