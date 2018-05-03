//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2018
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include "Matrix.hpp"
#include "Timer.hpp"
#include "amath583.hpp"
#include "matmat583.hpp"
#include "matvec583.hpp"
#include <fstream>
#include <functional>
#include <iostream>

using namespace std;

#ifdef __TEMPLATED
template <typename MatrixType>
double benchmark(int M, int N, int K, long numruns, function<void(const MatrixType&, const MatrixType&, MatrixType&)> f) {
  MatrixType A(M, K), B(K, N), C(M, N);
  randomize(A);
  randomize(B);
  randomize(C);

  Timer T;
  T.start();
  for (int i = 0; i < numruns; ++i) {
    f(A, B, C);
  }
  T.stop();

  zeroize(C);
  return T.elapsed();
}

void runBenchmark(function<void(const ColMatrix&, const ColMatrix&, ColMatrix&)> f, long maxsize) {
  cout << "N\tN*N\tTime\tFlops" << endl;
  for (long i = 2; i <= maxsize; i *= 2) {
    long   numruns = 8L * 1048L * 1048L * 1048L / (i * i * i) + 2;
    double t       = benchmark(i, i, i, numruns, f);
    cout << i << "\t" << i * i << "\t" << t << "\t" << 2.0 * 1.e3 * numruns * i * i * i / t << endl;
  }
}

void runBenchmark(function<void(const RowMatrix&, const RowMatrix&, RowMatrix&)> f, long maxsize) {
  cout << "N\tN*N\tTime\tFlops" << endl;
  for (long i = 2; i <= maxsize; i *= 2) {
    long   numruns = 8L * 1048L * 1048L * 1048L / (i * i * i) + 2;
    double t       = benchmark(i, i, i, numruns, f);
    cout << i << "\t" << i * i << "\t" << t << "\t" << 2.0 * 1.e3 * numruns * i * i * i / t << endl;
  }
}
#endif

/* For Matrix x Matrix */
double benchmark(int M, int N, int K, long numruns, function<void(const Matrix&, const Matrix&, Matrix&)>);
void   runBenchmark(function<void(const Matrix&, const Matrix&, Matrix&)> f, long maxsize);

/* For Matrix x vector */
double benchmark(int M, int N, long numruns, function<void (const Matrix&, const Vector&, Vector&)> f);
void runBenchmark(function<void (const Matrix&, const Vector&, Vector&)> f, long maxsize);

int main(int argc, char* argv[]) {
  long maxsize = (argc >= 3) ? stod(argv[2]) : 4096;
  bool col_mat = (argc == 4) && stod(argv[3]);

  if (string(argv[1]) == "mult")
#ifdef __TEMPLATED
    col_mat ? runBenchmark(multiply<ColMatrix>, maxsize) : runBenchmark(multiply<RowMatrix>, maxsize);
   else if (string(argv[1]) == "mult_ijk")
    col_mat ? runBenchmark(multiply_ijk<ColMatrix>, maxsize) : runBenchmark(multiply_ijk<RowMatrix>, maxsize);
  else if (string(argv[1]) == "mult_ikj")
    col_mat ? runBenchmark(multiply_ikj<ColMatrix>, maxsize) : runBenchmark(multiply_ikj<RowMatrix>, maxsize);
  else if (string(argv[1]) == "mult_jki")
    col_mat ? runBenchmark(multiply_jki<ColMatrix>, maxsize) : runBenchmark(multiply_jki<RowMatrix>, maxsize);
  else if (string(argv[1]) == "mult_matvec_ij")
    runBenchmark(matvec_ij<Matrix, Vector>, maxsize);
  else if (string(argv[1]) == "mult_matvec_ji")
    runBenchmark(matvec_ji<Matrix, Vector>, maxsize);
#else
    runBenchmark(multiply, maxsize);
#endif
  else if (string(argv[1]) == "hoistedmult")
    runBenchmark(hoistedMultiply, maxsize);
  else if (string(argv[1]) == "2x2")
    runBenchmark(tiledMultiply2x2, maxsize);
  else if (string(argv[1]) == "2x4")
    runBenchmark(tiledMultiply2x4, maxsize);
  else if (string(argv[1]) == "4x2")
    runBenchmark(tiledMultiply4x2, maxsize);
  else if (string(argv[1]) == "4x4")
    runBenchmark(tiledMultiply4x4, maxsize);
  else if (string(argv[1]) == "blocked")
    runBenchmark(blockedTiledMultiply2x2, maxsize);
  else if (string(argv[1]) == "copyblocked")
    runBenchmark(copyBlockedTiledMultiply2x2, maxsize);
  else if (string(argv[1]) == "hoisted")
    runBenchmark(hoistedTiledMultiply2x2, maxsize);
  else if (string(argv[1]) == "blockhoisted")
    runBenchmark(hoistedBlockedTiledMultiply2x2, maxsize);
  else if (string(argv[1]) == "copyblockhoisted")
    runBenchmark(hoistedCopyBlockedTiledMultiply2x2, maxsize);
  else if (string(argv[1]) == "copyblockhoisted4x4")
    runBenchmark(hoistedCopyBlockedTiledMultiply4x4, maxsize);
  else
    return -1;

  return 0;
}


/* For Matrix x Matrix */
void runBenchmark(function<void(const Matrix&, const Matrix&, Matrix&)> f, long maxsize) {
  cout << "N\tN*N\tTime\tFlops" << endl;
  for (long i = 8; i <= maxsize; i *= 2) {
    long   numruns = 8L * 1048L * 1048L * 1048L / (i * i * i) + 2;
    double t       = benchmark(i, i, i, numruns, f);
    cout << i << "\t" << i * i << "\t" << t << "\t" << 2.0 * 1.e3 * numruns * i * i * i / t << endl;
  }
}

double benchmark(int M, int N, int K, long numruns, function<void(const Matrix&, const Matrix&, Matrix&)> f) {
  Matrix A(M, K), B(K, N), C(M, N);
  randomize(A);
  randomize(B);
  randomize(C);

  Timer T;
  T.start();
  for (int i = 0; i < numruns; ++i) {
    f(A, B, C);
  }
  T.stop();

  zeroize(C);

  return T.elapsed();
}

/***************** For Matrix x Vector      ***************/
void runBenchmark(function<void (const Matrix&, const Vector&, Vector&)> f, long maxsize){
  cout << "N\tN*N\tTime\tFlops" << endl;
  for (long i = 2; i <= maxsize; i *= 2) {
    long   numruns = 8L * 1048L * 1048L * 1048L / (i * i ) + 2;
    double t       = benchmark(i, i, numruns, f);
    cout << i << "\t" << i * i << "\t" << t << "\t" << 2.0 * 1.e3 * numruns * i * i / t << endl;
  }
}

double benchmark(int M, int N, long numruns, function<void (const Matrix&, const Vector&, Vector&)> f){
  Matrix A(M, N);
  Vector B(N), C(M);

  randomize(A);
  randomize(B);
  randomize(C);

  Timer T;
  T.start();
  for (int i = 0; i < numruns; ++i) {
    f(A, B, C);
  }
  T.stop();

  zeroize(C);

  return T.elapsed();
}