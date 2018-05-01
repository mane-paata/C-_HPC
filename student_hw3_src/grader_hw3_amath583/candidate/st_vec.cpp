#include <iostream>
#include <cstdlib>

#include "Vector.hpp"
#include "Timer.hpp"
#include "amath583.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 3)
  {
    cout << "Usage: " << argv[0] << " [doubleFilename] [vectorFilename]"  << endl;
    return -1;
  }

	double a = readDouble(argv[1]);
	Vector b = readVector(argv[2]);

	Vector c = a*b;

	writeVector(c, "st_vec.txt");

  return 0;
}
