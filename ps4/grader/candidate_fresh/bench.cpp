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
#include <fstream>
#include <functional>
#include <iostream>

using namespace std;

double benchmark(int M, int N, int K, long numruns, function<void(const Matrix&, const Matrix&, Matrix&)>);
void   runBenchmark(function<void(const Matrix&, const Matrix&, Matrix&)> f, long maxsize);

int main(int argc, char* argv[]) {
  long maxsize = (argc == 3) ? stod(argv[2]) : 4096;

  if (string(argv[1]) == "mult")
#ifdef __TEMPLATED
    runBenchmark(multiply<Matrix>, maxsize);
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