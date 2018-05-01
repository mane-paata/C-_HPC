#include <iostream>
#include <cstdlib>

#include "Vector.hpp"
#include "Timer.hpp"
#include "amath583.hpp"

using namespace std;

double time_add_vec_ppe(int dim, int loops)
{
	Timer T; 
	Vector x(dim), y(dim);
	double t1, t2;
	for(int j = 0; j < dim; j++)
	{
		x(j) = random();
		y(j) = random();
	}

	T.start(); 
	for(int i=0; i < loops; i++)
		y = y + x;
	T.stop(); 
  t1 = T.elapsed();
 
	T.start(); 
	for(int i=0; i < loops; i++)
			y += x;
	T.stop(); 
  t2 = T.elapsed();

	return t1/t2;
}

// High Performance Loop for vector addition, tobe written into timed_add_vec_hpe.txt

double time_add_vec_hpe(int dim, int loops)
{
	Timer T; 
	Vector x(dim), y(dim);
	double t1, t2;
	for(int j = 0; j < dim; j++)
	{
		x(j) = random();
		y(j) = random();
	}

	T.start(); 
	for(int i=0; i < loops; i++){
		for(int k=0; k < dim; k++)
			y(k) = y(k) + x(k);
  }	
	T.stop(); 
  t1 = T.elapsed();

	T.start(); 
	for(int i=0; i < loops; i++)
		y += x;	
	T.stop(); 
	t2 = T.elapsed();

	return t1/t2;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
  {
    cout << "Usage: " << argv[0] << "[vector size - int]  [num trials - int]"  << endl;
    return -1;
  }

	int dimension = atoi(argv[1]);
	int loops = atoi(argv[2]);

	double time_ratio_ppe = time_add_vec_ppe(dimension, loops);
	double time_ratio_hpe = time_add_vec_hpe(dimension, loops);

	writeNumber(time_ratio_ppe, "timed_add_vec_ppe.txt");
	writeNumber(time_ratio_hpe, "timed_add_vec_hpe.txt");

  return 0;
}
