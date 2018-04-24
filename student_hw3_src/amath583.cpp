//
// This file is part of the course materials for AMATH483/583 at the University of Washington,
// Spring 2018
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine, Tommaso Buvoli
//
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cmath> 

#include "Matrix.hpp"
#include "Vector.hpp"
#include "amath583.hpp"

Vector operator+(const Vector& x, const Vector& y) {
  Vector z(x.num_rows());
  for (size_t i = 0; i < x.num_rows(); ++i) {
    z(i) = x(i) + y(i);
  }
  return z;
}

Vector& operator+=(Vector& y, const Vector& x) {
  for (size_t i = 0; i < x.num_rows(); ++i) {
    y(i) = y(i) +  x(i);
  }
  return y;
}

Vector operator*(const double a, const Vector& x)
{
  Vector y(x.num_rows());
  for(size_t i=0; i < x.num_rows(); i++){
    y(i) = a * x(i);
  }
  return y;
}


// == Vector IO Functions  ===========================================================================
Vector readVector()
{
  return readVector(std::cin);
}

Vector readVector(std::string filename)
{
  std::ifstream inputFile(filename);
  return readVector(inputFile);
}

Vector readVector(std::istream &inputStream)
{
  std::string string_input;

  getline(inputStream, string_input);
  if (string_input.compare("AMATH 583 VECTOR") != 0) {
    std::cout << "Error: vector file does not contain a header.";
    throw;
  }

  getline(inputStream, string_input);
  if (string_input.compare("THIS IS THE END") == 0)
    return Vector(0);

  long lN = stol(string_input);
  if (lN < 0)
  {
    std::cout << "Error: vector file contains invalid vector length.";
    throw;
  }

  size_t N = lN;
  Vector v(N);

  for (size_t i = 0; i < N; i++) {
    getline(inputStream, string_input);
    v(i) = stod(string_input);
  }
  getline(inputStream, string_input);
  if (string_input.compare("THIS IS THE END") != 0)
  {
    std::cout << "Error: vector file does not contain proper footer.";
    throw;
  }
  return v;
}

void streamVector(const Vector &x)
{
    streamVector(x, std::cout);
}

void streamVector(const Vector &x, std::ostream &outputFile)
{
  outputFile << "AMATH 583 VECTOR" << std::endl; // Write header
  outputFile << x.num_rows() << std::endl;

  for (size_t i = 0; i < x.num_rows(); ++i) { // Write data
    outputFile << std::setprecision(15) << std::scientific << x(i) << std::endl;
  }

  outputFile << "THIS IS THE END" << std::endl; // Write tailer
}

void writeVector(const Vector &x, std::string filename)
{
  std::ofstream outputFile(filename);
  streamVector(x, outputFile);
}


// == Number IO Functions  ===========================================================================
double readDouble()
{
    return readDouble(std::cin);
}

double readDouble(std::istream& input_stream)
{
    std::string line;
    if(getline(input_stream, line))
    {
        return stod(line);
    }
    else
    {
        throw;
    }
}

double readDouble(std::string path)
{
    std::ifstream in_file (path);
    return readDouble(in_file);
}