#include <iostream>
#include <cstdlib>
#include "amath583IO.hpp"

using namespace std;

template<typename T>
T sqrt583(T z)
{
  T x(1.0, 1.0);
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
  complex<double> input  = readComplexDouble(argv[1]);
  complex<double> output = sqrt583<complex<double>>(input);
  writeComplexDouble(output, "square_root.txt");
  return 0;
}