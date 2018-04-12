#include <vector>
#include <stddef.h>

class Vector{
public:
    Vector(size_t M): num_rows_(M), storage_(num_rows_){}

    double& operator()(size_t i){return storage_[i];}
    const double& operator() (size_t i) const {return storage_[i];}

    size_t num_rows() const {return num_rows_;}

private:
    size_t num_rows_;
    std::vector<double> storage_; 

};
