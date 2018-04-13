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
void writeVector(const Vector& in_vector, std::string filename)
{
  
  bool use_cout = (filename.compare("cout") == 0);
  ofstream output;
  int length = in_vector.num_rows();
  
  // Write header first
  if(!use_cout)
  {
    output.open(filename);
    output << HEADER << endl;
  }
  else
  {
    cout << HEADER << endl;
  }

  if (length > 0)
  {
    // Write number of rows
    if (!use_cout)
      output << length << endl;
    else
      cout << length << endl;

    // Write all numbers
    for (int i=0; i < length; i++)
    {
      if (!use_cout)
        output << in_vector(i) << endl;
      else
        cout << in_vector(i) << endl;
    }
  }

  // Write trailer
  if(!use_cout)
  {
    output << TRAILER << endl;
    output.close();
  }
  else
  {
    cout << TRAILER << endl;
  }
}


/* Function to generate random vector
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