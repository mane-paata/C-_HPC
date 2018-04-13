#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
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

  Vector rand_vector = randomVector(10);
  for (int i =0; i< rand_vector.num_rows(); i++)
  {
    cout << rand_vector(i) << " ";
  }
  cout << endl;

  size_t ind = infNormIndex(rand_vector);
  cout << ind << endl;
  return 0;
}

Vector readVector(string filename)
{

  ifstream infile ("foo.in", ios::in);
  int i = 0;
  string line;
  string start_string = "AMATH 583 VECTOR";
  string end_string = "THIS IS THE END";
  bool begin = false;
  Vector temp(100);    // Temporary store

  while (getline(infile, line))
  {
    cout << line << endl;
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

/*
* Function to generate random vector
* input N : vector length
* output Vector object
*/
Vector randomVector(int length)
{
  Vector rand_vector(length);
  for(int i=0; i < length; i++)
  {
    rand_vector(i) = rand();
  }
  return rand_vector;
}

/*
* Function to return index of the maximum absolute value of the vector
* input : Vector
* output : index of the maximum absolute value
*/
size_t infNormIndex(const Vector& x)
{
  double greatest = 0;
  int i = 0, index = 0;
  int length = x.num_rows();
  while(i <= length)
  {
    if(greatest < abs(x(i)))
    {
      greatest = abs(x(i));
      index += 1;
    }
    i += 1;
  }
  return index;
}

/*
* Function to return infinity norm
* input : Vector
* output : maximum absolute value
*/

double infNorm(const Vector& x)
{
  size_t ind = infNormIndex(x);
  return abs(x(ind));
}

/*
Function to find the inner product of two vectors
input : two vectors
output: inner product
*/
double dot583(const Vector& x, const Vector& y)
{
  double innerprod = 0;
  for(int i =0; i < x.num_rows(); i++)
  {
    innerprod += x(i)*y(i);
  }
  return innerprod;
}