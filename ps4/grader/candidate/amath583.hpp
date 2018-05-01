//
// This file is part of the course materials for AMATH483/583 at the University
// of Washington,
// Spring 2018
//
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0
// International License
// https://creativecommons.org/licenses/by-nc-sa/4.0/
//
// Author: Andrew Lumsdaine
//

#include <fstream>
#include <iostream>
#include <string>

#include "COO.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"

Vector operator+(const Vector& x, const Vector& y);

void zeroize(Matrix &);
void zeroize(Vector &);
void randomize(Vector &);
void randomize(Matrix &);

Vector operator*(const COOMatrix& A, const Vector& x);
void matvec(const COOMatrix& A, const Vector& x, Vector& y);
void piscetize(COOMatrix& A, size_t xpoints, size_t ypoints);