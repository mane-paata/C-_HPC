#include <iostream>
#include <vector>
#include <cstddef>
#include "Timer.hpp"

using namespace std;


class double_vector {
public:
  double_vector(size_t M, double num) : num_rows_(M), storage_(num_rows_) {
		for(int i =0; i < M; i++)
			storage_[i] = num;
	}

        double& operator()(size_t i)       { return storage_[i]; }
  const double& operator()(size_t i) const { return storage_[i]; }

  size_t num_rows() const { return num_rows_; }

private:
  size_t num_rows_;
  std::vector<double> storage_;  
};

class float_vector {
public:
  float_vector(size_t M, float num) : num_rows_(M), storage_(num_rows_) {
		for(int i =0; i < M; i++)
			storage_[i] = num;
	}

        float& operator()(size_t i)       { return storage_[i]; }
  const float& operator()(size_t i) const { return storage_[i]; }

  size_t num_rows() const { return num_rows_; }

private:
  size_t num_rows_;
  std::vector<float> storage_;  
};

void calculate_double_precision(int dim, double num1, double num2)
{
	Timer t; 
	t.start(); 
	double_vector x(dim, num1); 
	double_vector y(dim, num2); 
	double_vector z(dim, 0.0); 
	t.stop(); 
	std::cout << "Construction time: " << t.elapsed() << std::endl;
	t.start();

  for (size_t i = 0; i < dim; ++i) 
 		z(i) = x(i) * y(i); 
		 
	t.stop(); 
 	std::cout << "Multiplication time: " << t.elapsed() << std::endl;
	cout << z(2) << endl;

}

void calculate_float_precision(int dim, float num1, float num2)
{
	Timer t; 
	t.start(); 
	float_vector x(dim, num1); 
	float_vector y(dim, num2); 
	float_vector z(dim, 0.0); 
	t.stop(); 
	std::cout << "Construction time: " << t.elapsed() << std::endl;
	t.start();

  for (size_t i = 0; i < dim; ++i) 
 		z(i) = x(i) * y(i); 
		 
	t.stop(); 
 	std::cout << "Multiplication time: " << t.elapsed() << std::endl;
	cout << z(2) << endl;

}


int main(){

	cout << "Calculating double precision with optimization" << endl;
	calculate_double_precision(10000000, 3.1423456, 27.0);

	cout << "Calculating float precision with optimization" << endl;
	calculate_float_precision(10000000, 3.1423456, 27.0);

}