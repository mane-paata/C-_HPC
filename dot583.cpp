#include <iostream>
#include "amath583.hpp"

using namespace std;

void print_usage()
{
  cout << "Usage: ./dot583 <vector_file_1> <vector_file_2>" << endl;
  exit(0);
}

int main(int argc, char *argv[])
{
  if (argc > 3 || argc < 3)
    print_usage();

  Vector x = readVector(argv[1]); 
  Vector y = readVector(argv[2]);

  if(x.num_rows() != y.num_rows())
  {
    cout << "ERROR: Vectors length do not match." << endl;
    exit(-1);
  }

  double n1 = dot583(x, y);
  cout << n1 << endl; 
  
  return 0;
}