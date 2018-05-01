#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "amath583.hpp"

using namespace std;

#define HEADER "AMATH 583 VECTOR"
#define TRAILER "THIS IS THE END"

/*
 * Read vector from given file name
 * The input will consist of lines of text, consisting of a header, an integer n, a sequence of n numbers, and a trailer.
*/
Vector readVector(string filename)
{
  ifstream infile (filename, ios::in);
  bool read_header = false;
  bool read_trailer = false;
  string line;
  char delim = '\n';  // change as per windows/ linux
  int length = 0;

  // Look for header
  while(getline(infile, line, delim))
  {
    if (line.compare(HEADER) == 0)
    {
      read_header = true;
      break;
    }
  }

  // header not found!
  if (!read_header)
    exit(-1);

  // get length of vector
  if(getline(infile, line, delim))
  {
    // Header after trailer, no vector
    if (line.compare(TRAILER) == 0)
    {
      read_trailer = true;
      std::cout << 0 << endl;
      exit(0);
    }
    length = stoi(line);
  }

  // length is negative
  if (length < 0)
    exit(-2);
  
  // Define our return vector
  Vector ret_vector(length);

  // read till we get trailer
  int i = 0;
  while(getline(infile, line, delim))
  {
    if (line.compare(TRAILER) == 0)
    {
      read_trailer = true;
      break;
    }

    // numbers more than expected? (wrong triler may be?)
    if (i>=length)
      break;

    ret_vector(i) = stod(line);
    i++;
  }

  // trailer not found!
  if (!read_trailer)
    exit(-1);

  // length == 0, no vector read
  if (length == 0)
  {
    cout << 0 << endl;
    exit(0);
  }

  return ret_vector;
}

/*
 * Write given vector to a file
*/
void writeVector(const Vector& in_vector, string filename)
{
  
  ofstream output;
  int length = in_vector.num_rows();
  
  // Write header first
  output.open(filename);
  output << HEADER << endl;

  if (length > 0)
  {
    // Write number of rows
    output << length << endl;

    // Write all numbers
    for (int i=0; i < length; i++)
      output << in_vector(i) << endl;
  }

  // Write trailer
  output << TRAILER << endl;
  output.close();
}


void writeVector(const Vector& in_vector, std::ostream& out_stream)
{

  int length = in_vector.num_rows();
  
  // Write header first
  out_stream << HEADER << endl;

  if (length > 0)
  {
    // Write number of rows
    out_stream << length << endl;

    // Write all numbers
    for (int i=0; i < length; i++)
      out_stream << in_vector(i) << endl;
  }

  // Write trailer
  out_stream << TRAILER << endl;
}

/* Function to generate random vector
* input N : vector length
* output Vector object
*/
Vector randomVector(int length)
{
  Vector rand_vector(length);
  srand(time(0)); //use current time as seed for random generator
  for(int i=0; i < length; i++)
  {
    rand_vector(i) = (rand() % 9) + (rand() % 9) / 10.0;
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
  double max = 0;
  int index = 0;
  for (int i=0; i < x.num_rows(); i++)
  {
    double abs_x = abs(x(i));
    if (abs_x > max)
    {
      max = abs_x;
      index = i;
    }
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