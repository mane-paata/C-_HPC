#include "Vector.hpp"

double& Vector::operator()(size_t i)
{
  return storage_[i];
}
  
const double& Vector::operator()(size_t i)
const
{
  return storage_[i];
}

size_t Vector::num_rows()
const
{
  return num_rows_;
}