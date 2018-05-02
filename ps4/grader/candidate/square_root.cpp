#include <iostream>
<<<<<<< HEAD
#include "amath583IO.hpp"

using namespace std;

template<typename T> T sqrt583(T z)
{
  T x = 1.0;
  for(size_t i=0; i < 32; ++i) 
  {
    T dx=-(x*x-z)/(2.0*x);
    x+=dx;
    if(abs(dx)<1.e-9)
      break;
  }
  return x;
}

int main(int argc, char *argv[])
{
  if (argc != 2){
    cout << "Usage:" << argv[0] << "<input_complex.txt>" << endl;
    return -1;
  }

  complex<double> in = readComplexDouble(argv[1]);

  writeComplexDouble(sqrt583(in), "square_root.txt");
=======
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
>>>>>>> bffead89637db5c6f65f6c136a78af0de2e8dc88

  return 0;
}