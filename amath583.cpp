#include <iostream>
#include <fstream>
#include <sstream>
#include "amath583.hpp"

using namespace std;

int main()
{
  string filename = "foo.in";
  Vector a = readVector(filename);
  

  for (int i =0; i< a.num_rows(); i++)
  {
    cout << a(i) << " ";
  }
  cout << endl;

  return 0;
}

Vector readVector(string filename)
{

  Vector v(10);

  ifstream infile ("foo.in", ios::in);
  int i = 0;
  string line;
  string start_string = "AMATH 583 VECTOR";
  string end_string = "THIS IS THE END";
  bool begin = false;
  Vector temp(100);    // Temporary store

  while (getline(infile, line))
  {
    if(line.compare(start_string) == 0)
    {
      begin = true;
      continue;
    }

    if(line.compare(end_string) == 0)
    {
      break;
    }
    
    if(!begin) continue;

    temp(i) = stod(line);
    i++;
  }

  cout << "Lines: " << i << "\n";

  Vector ret_vector(i);
  for (i=0; i < ret_vector.num_rows() ; i++)
  {
    ret_vector(i) = temp(i);
  }

  return ret_vector;
}
