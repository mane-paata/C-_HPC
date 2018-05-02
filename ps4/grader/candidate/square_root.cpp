#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2)
  {
    cout << "Usage: " << argv[0] << "[ComplexDoubleObjectFile]"  << endl;
    return -1;
  }

	complex<double> z = readComplexDouble(argv[1]);

	writeComplexDouble(sqr_root, "square_root.txt");

  return 0;
}