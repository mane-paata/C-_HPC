#include <vector>

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__ 1
using namespace std;

class Vector{
public:
    Vector(size_t M): num_rows_(M), storage_(num_rows_){}

    double& operator()(size_t i);
    const double& operator() (size_t i) const;
    
    size_t num_rows() const;

private:
    size_t num_rows_;
    std::vector<double> storage_; 

};

#endif // __VECTOR_HPP__
