#include "Vector.hpp"

#ifndef __AMATH583_HPP__
#define __AMATH583_HPP__ 1

Vector readVector(std::string filename);
void writeVector(const Vector& in_vector, std::string filename);
Vector randomVector(int length);
size_t infNormIndex(const Vector& x);
double infNorm(const Vector& x);
double dot583(const Vector& x, const Vector& y);

#endif // __AMATH583_HPP__
