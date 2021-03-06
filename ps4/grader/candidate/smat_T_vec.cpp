#include <iostream>

#include "COO.hpp"
#include "amath583IO.hpp"


using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 3)
  {
    cout << "Usage: " << argv[0] << "[COO_MatrixFile] [VectorFile]"  << endl;
    return -1;
  }

	COOMatrix A = readCOOMatrix(argv[1]);
	Vector x = readVector(argv[2]);
  Vector y(x.num_rows());

	A.trMatvec(x, y);

	writeVector(y, "smat_T_vec.txt");

  return 0;
}
