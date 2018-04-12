#include <vector>

class Vector{
public:
	Vector(size_t M) : num_rows_(M), storage_(num_rows_) {};
	size_t num_rows() const;
  
private:
	size_t num_rows_;
	std::vector<double> storage_;
};