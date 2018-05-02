#include <iostream>

#include "Matrix.hpp"
#include "Vector.hpp"
#include "matvec583.hpp"
#include "amath583IO.hpp"


using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 3)
  {
    cout << "Usage: " << argv[0] << "[MatrixFilename] [VectorFilename]"  << endl;
    return -1;
  }

	Matrix A = readMatrix(argv[1]);
	Vector x = readVector(argv[2]);

	Vector b = A * x;

	writeVector(b, "mat_vec.txt");

  return 0;
}
