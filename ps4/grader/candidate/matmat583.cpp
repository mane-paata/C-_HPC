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

#include "Matrix.hpp"
#include "matmat583.hpp"
#include <algorithm>
#include <cassert>

#ifndef __TEMPLATED

void multiply(const Matrix &A, const Matrix &B, Matrix &C) {
  basicMultiply(A, B, C);
}

void basicMultiply(const Matrix &A, const Matrix &B, Matrix &C) {
  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < B.num_cols(); ++j) {
      for (size_t k = 0; k < A.num_cols(); ++k) {
        C(i, j) += A(i, k) * B(k, j);
      }
    }
  }
}

void hoistedMultiply(const Matrix &A, const Matrix &B, Matrix &C) {
  for (size_t i = 0; i < A.num_rows(); ++i) {
    for (size_t j = 0; j < B.num_cols(); ++j) {
      double t = C(i, j);
      for (size_t k = 0; k < A.num_cols(); ++k) {
        t += A(i, k) * B(k, j);
      }
      C(i, j) = t;
    }
  }
}

void tiledMultiply2x2(const Matrix &A, const Matrix &B, Matrix &C) {
  for (size_t i = 0; i < A.num_rows(); i += 2) {
    for (size_t j = 0; j < B.num_cols(); j += 2) {
      for (size_t k = 0; k < A.num_cols(); ++k) {
        C(i    , j    ) += A(i    , k) * B(k, j    );
        C(i    , j + 1) += A(i    , k) * B(k, j + 1);
        C(i + 1, j    ) += A(i + 1, k) * B(k, j    );
        C(i + 1, j + 1) += A(i + 1, k) * B(k, j + 1);
      }
    }
  }
}

void tiledMultiply2x4(const Matrix &A, const Matrix &B, Matrix &C) {
  for (size_t i = 0; i < A.num_rows(); i += 2) {
    for (size_t j = 0; j < B.num_cols(); j += 4) {
      for (size_t k = 0; k < A.num_cols(); ++k) {
        C(i    , j    ) += A(i    , k) * B(k, j    );
        C(i    , j + 1) += A(i    , k) * B(k, j + 1);
        C(i    , j + 2) += A(i    , k) * B(k, j + 2);
        C(i    , j + 3) += A(i    , k) * B(k, j + 3);
        C(i + 1, j    ) += A(i + 1, k) * B(k, j    );
        C(i + 1, j + 1) += A(i + 1, k) * B(k, j + 1);
        C(i + 1, j + 2) += A(i + 1, k) * B(k, j + 2);
        C(i + 1, j + 3) += A(i + 1, k) * B(k, j + 3);
      }
    }
  }
}

void tiledMultiply4x2(const Matrix &A, const Matrix &B, Matrix &C) {
  for (size_t i = 0; i < A.num_rows(); i += 4) {
    for (size_t j = 0; j < B.num_cols(); j += 2) {
      for (size_t k = 0; k < A.num_cols(); ++k) {
        C(i    , j    ) += A(i    , k) * B(k, j    );
        C(i    , j + 1) += A(i    , k) * B(k, j + 1);
        C(i + 1, j    ) += A(i + 1, k) * B(k, j    );
        C(i + 1, j + 1) += A(i + 1, k) * B(k, j + 1);
        C(i + 2, j    ) += A(i + 2, k) * B(k, j    );
        C(i + 2, j + 1) += A(i + 2, k) * B(k, j + 1);
        C(i + 3, j    ) += A(i + 3, k) * B(k, j    );
        C(i + 3, j + 1) += A(i + 3, k) * B(k, j + 1);
      }
    }
  }
}

void tiledMultiply4x4(const Matrix &A, const Matrix &B, Matrix &C) {
  for (size_t i = 0; i < A.num_rows(); i += 4) {
    for (size_t j = 0; j < B.num_cols(); j += 4) {
      for (size_t k = 0; k < A.num_cols(); ++k) {
        C(i    , j    ) += A(i    , k) * B(k, j    );
        C(i    , j + 1) += A(i    , k) * B(k, j + 1);
        C(i    , j + 2) += A(i    , k) * B(k, j + 2);
        C(i    , j + 3) += A(i    , k) * B(k, j + 3);
        C(i + 1, j    ) += A(i + 1, k) * B(k, j    );
        C(i + 1, j + 1) += A(i + 1, k) * B(k, j + 1);
        C(i + 1, j + 2) += A(i + 1, k) * B(k, j + 2);
        C(i + 1, j + 3) += A(i + 1, k) * B(k, j + 3);
        C(i + 2, j    ) += A(i + 2, k) * B(k, j    );
        C(i + 2, j + 1) += A(i + 2, k) * B(k, j + 1);
        C(i + 2, j + 2) += A(i + 2, k) * B(k, j + 2);
        C(i + 2, j + 3) += A(i + 2, k) * B(k, j + 3);
        C(i + 3, j    ) += A(i + 3, k) * B(k, j    );
        C(i + 3, j + 1) += A(i + 3, k) * B(k, j + 1);
        C(i + 3, j + 2) += A(i + 3, k) * B(k, j + 2);
        C(i + 3, j + 3) += A(i + 3, k) * B(k, j + 3);
      }
    }
  }
}

void hoistedTiledMultiply2x2(const Matrix &A, const Matrix &B, Matrix &C) {
  for (size_t i = 0; i < A.num_rows(); i += 2) {
    for (size_t j = 0; j < B.num_cols(); j += 2) {
      double t00 = C(i    , j    );
      double t01 = C(i    , j + 1);
      double t10 = C(i + 1, j    );
      double t11 = C(i + 1, j + 1);

      for (size_t k = 0; k < A.num_cols(); ++k) {
        t00 += A(i    , k) * B(k, j    );
        t01 += A(i    , k) * B(k, j + 1);
        t10 += A(i + 1, k) * B(k, j    );
        t11 += A(i + 1, k) * B(k, j + 1);
      }
      C(i    , j    ) = t00;
      C(i    , j + 1) = t01;
      C(i + 1, j    ) = t10;
      C(i + 1, j + 1) = t11;
    }
  }
}

void blockedTiledMultiply2x2(const Matrix &A, const Matrix &B, Matrix &C) {
  const size_t blocksize = std::min(A.num_rows(), 64UL);

  for (size_t ii = 0; ii < A.num_rows(); ii += blocksize) {
    for (size_t jj = 0; jj < B.num_cols(); jj += blocksize) {
      for (size_t kk = 0; kk < A.num_cols(); kk += blocksize) {

        for (size_t i = ii; i < ii + blocksize; i += 2) {
          for (size_t j = jj; j < jj + blocksize; j += 2) {
            for (size_t k = kk; k < kk + blocksize; ++k) {
              C(i    , j    ) += A(i    , k) * B(k, j    );
              C(i    , j + 1) += A(i    , k) * B(k, j + 1);
              C(i + 1, j    ) += A(i + 1, k) * B(k, j    );
              C(i + 1, j + 1) += A(i + 1, k) * B(k, j + 1);
            }
          }
        }
      }
    }
  }
}

void hoistedBlockedTiledMultiply2x2(const Matrix &A, const Matrix &B,
                                    Matrix &C) {
  const size_t blocksize = std::min(A.num_rows(), 64UL);

  for (size_t ii = 0; ii < A.num_rows(); ii += blocksize) {
    for (size_t jj = 0; jj < B.num_cols(); jj += blocksize) {
      for (size_t kk = 0; kk < A.num_cols(); kk += blocksize) {

        for (size_t i = ii; i < ii + blocksize; i += 2) {
          for (size_t j = jj; j < jj + blocksize; j += 2) {

            double t00 = C(i    , j    );
            double t01 = C(i    , j + 1);
            double t10 = C(i + 1, j    );
            double t11 = C(i + 1, j + 1);

            for (size_t k = kk; k < kk + blocksize; ++k) {
              t00 += A(i    , k) * B(k, j    );
              t01 += A(i    , k) * B(k, j + 1);
              t10 += A(i + 1, k) * B(k, j    );
              t11 += A(i + 1, k) * B(k, j + 1);
            }

            C(i    , j    ) = t00;
            C(i    , j + 1) = t01;
            C(i + 1, j    ) = t10;
            C(i + 1, j + 1) = t11;
          }
        }
      }
    }
  }
}

void copyBlockedTiledMultiply2x2(const Matrix &A, const Matrix &B, Matrix &C) {
  const size_t blocksize = std::min(A.num_rows(), 64UL);

  for (size_t ii = 0; ii < A.num_rows(); ii += blocksize) {
    for (size_t jj = 0; jj < B.num_cols(); jj += blocksize) {
      for (size_t kk = 0; kk < A.num_cols(); kk += blocksize) {

        Matrix BB(blocksize, blocksize);
        for (size_t j = jj, jb = 0; j < jj + blocksize; ++j, ++jb) {
          for (size_t k = kk, kb = 0; k < kk + blocksize; ++k, ++kb) {
            BB(jb, kb) = B(k, j);
          }
        }

        for (size_t i = ii; i < ii + blocksize; i += 2) {
          for (size_t j = jj, jb = 0; j < jj + blocksize; j += 2, jb += 2) {
            for (size_t k = kk, kb = 0; k < kk + blocksize; ++k, ++kb) {

              C(i    , j    ) += A(i    , k) * BB(jb    , kb);
              C(i    , j + 1) += A(i    , k) * BB(jb + 1, kb);
              C(i + 1, j    ) += A(i + 1, k) * BB(jb    , kb);
              C(i + 1, j + 1) += A(i + 1, k) * BB(jb + 1, kb);
            }
          }
        }
      }
    }
  }
}

void hoistedCopyBlockedTiledMultiply2x2(const Matrix &A, const Matrix &B,
                                        Matrix &C) {
  const size_t blocksize = std::min(A.num_rows(), 64UL);

  for (size_t ii = 0; ii < A.num_rows(); ii += blocksize) {
    for (size_t jj = 0; jj < B.num_cols(); jj += blocksize) {
      for (size_t kk = 0; kk < A.num_cols(); kk += blocksize) {

        Matrix BB(blocksize, blocksize);
        for (size_t j = jj, jb = 0; j < jj + blocksize; ++j, ++jb) {
          for (size_t k = kk, kb = 0; k < kk + blocksize; ++k, ++kb) {
            BB(jb, kb) = B(k, j);
          }
        }

        for (size_t i = ii; i < ii + blocksize; i += 2) {
          for (size_t j = jj, jb = 0; j < jj + blocksize; j += 2, jb += 2) {

            double t00 = C(i    , j    );
            double t01 = C(i    , j + 1);
            double t10 = C(i + 1, j    );
            double t11 = C(i + 1, j + 1);

            for (size_t k = kk, kb = 0; k < kk + blocksize; ++k, ++kb) {
              t00 += A(i    , k) * BB(jb    , kb);
              t01 += A(i    , k) * BB(jb + 1, kb);
              t10 += A(i + 1, k) * BB(jb    , kb);
              t11 += A(i + 1, k) * BB(jb + 1, kb);
            }

            C(i    , j    ) = t00;
            C(i    , j + 1) = t01;
            C(i + 1, j    ) = t10;
            C(i + 1, j + 1) = t11;
          }
        }
      }
    }
  }
}

void hoistedCopyBlockedTiledMultiply4x4(const Matrix &A, const Matrix &B,
                                        Matrix &C) {
  const size_t blocksize = std::min(A.num_rows(), 64UL);

  for (size_t ii = 0; ii < A.num_rows(); ii += blocksize) {
    for (size_t jj = 0; jj < B.num_cols(); jj += blocksize) {
      for (size_t kk = 0; kk < A.num_cols(); kk += blocksize) {

        Matrix BB(blocksize, blocksize);
        for (size_t j = jj, jb = 0; j < jj + blocksize; ++j, ++jb) {
          for (size_t k = kk, kb = 0; k < kk + blocksize; ++k, ++kb) {
            BB(jb, kb) = B(k, j);
          }
        }

        for (size_t i = ii; i < ii + blocksize; i += 4) {
          for (size_t j = jj, jb = 0; j < jj + blocksize; j += 4, jb += 4) {

            double t00 = C(i    , j    );
            double t01 = C(i    , j + 1);
            double t10 = C(i + 1, j    );
            double t11 = C(i + 1, j + 1);
            double t20 = C(i + 2, j    );
            double t21 = C(i + 2, j + 1);
            double t30 = C(i + 3, j    );
            double t31 = C(i + 3, j + 1);
            double t02 = C(i    , j + 2);
            double t03 = C(i    , j + 3);
            double t12 = C(i + 1, j + 2);
            double t13 = C(i + 1, j + 3);
            double t22 = C(i + 2, j + 2);
            double t23 = C(i + 2, j + 3);
            double t32 = C(i + 3, j + 2);
            double t33 = C(i + 3, j + 3);

            for (size_t k = kk, kb = 0; k < kk + blocksize; ++k, ++kb) {
              t00 += A(i    , k) * BB(jb    , kb);
              t10 += A(i + 1, k) * BB(jb    , kb);
              t20 += A(i + 2, k) * BB(jb    , kb);
              t30 += A(i + 3, k) * BB(jb    , kb);

              t01 += A(i    , k) * BB(jb + 1, kb);
              t11 += A(i + 1, k) * BB(jb + 1, kb);
              t21 += A(i + 2, k) * BB(jb + 1, kb);
              t31 += A(i + 3, k) * BB(jb + 1, kb);

              t02 += A(i    , k) * BB(jb + 2, kb);
              t12 += A(i + 1, k) * BB(jb + 2, kb);
              t22 += A(i + 2, k) * BB(jb + 2, kb);
              t32 += A(i + 3, k) * BB(jb + 2, kb);

              t03 += A(i    , k) * BB(jb + 3, kb);
              t13 += A(i + 1, k) * BB(jb + 3, kb);
              t23 += A(i + 2, k) * BB(jb + 3, kb);
              t33 += A(i + 3, k) * BB(jb + 3, kb);
            }

            C(i    , j    ) = t00;
            C(i    , j + 1) = t01;
            C(i + 1, j    ) = t10;
            C(i + 1, j + 1) = t11;
            C(i + 2, j    ) = t20;
            C(i + 2, j + 1) = t21;
            C(i + 3, j    ) = t30;
            C(i + 3, j + 1) = t31;
            C(i    , j + 2) = t02;
            C(i    , j + 3) = t03;
            C(i + 1, j + 2) = t12;
            C(i + 1, j + 3) = t13;
            C(i + 2, j + 2) = t22;
            C(i + 2, j + 3) = t23;
            C(i + 3, j + 2) = t32;
            C(i + 3, j + 3) = t33;
          }
        }
      }
    }
  }
}

Matrix operator*(const Matrix &A, const Matrix &B) {
  assert(A.num_cols() == B.num_rows());

  Matrix C(A.num_rows(), B.num_cols());

  basicMultiply(A, B, C); // or any multiply of your choosing 

  return C;
}

#endif