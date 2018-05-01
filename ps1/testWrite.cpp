#include <iostream>
#include "amath583.hpp"

using namespace std;

void print_usage()
{
  cout << "Usage: ./testWrite n [ filename ]" << endl;
  exit(0);
}

int main(int argc, char *argv[])
{
  if (argc > 3 || argc < 2)
    print_usage();

  int length = stoi(argv[1]);
  
  if (length < 0)
    exit(-2);

  Vector a = randomVector(length);
  string out = "cout";

  if (argc == 3)
    out = argv[2];
  
  if (out.compare("cout") == 0)
    writeVector(a, cout);
  else
    writeVector(a, out);
  
  return 0;
}