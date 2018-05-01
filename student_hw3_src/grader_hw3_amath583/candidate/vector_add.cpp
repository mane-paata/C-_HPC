#include <iostream>
#include <cstdlib>

#include "Vector.hpp"
#include "Timer.hpp"
#include "amath583.hpp"

using namespace std;


// Low performance loop for vector addition, to be written into timed_add_vec_ppe.txt

void time_add_vec_ppe(int dim, int loop_number)
{
	Timer t1, t2; 
	Vector x(dim), y(dim);
	for(int j = 0; j < dim; j++)
	{
		x(j) = random();
		y(j) = random();
	}

/* * Timing using "+" operator */
	t1.start(); 
	for(int i=0; i < loop_number; i++){
		//for(int k=0; k < dim; k++)
			y = y + x;
  }	
	t1.stop(); 
	std::cout << "Time taken to run vector addition using overloaded + operator: " << t1.elapsed() << std::endl;
 
/* Timing using "+=" operator */
	t2.start(); 
	for(int i=0; i < loop_number; i++){
		//for(int k=0; k < dim; k++)
			y += x;
  }	
	t2.stop(); 
 	std::cout << "Time taken to run vector addition using overloaded += operator: " << t2.elapsed() << std::endl;
  
	cout << " Ratio of time taken for vector addition with low performance= " << t1.elapsed()/t2.elapsed()  << endl;
}

// High Performance Loop for vector addition, tobe written into timed_add_vec_hpe.txt

void time_add_vec_hpe(int dim, int loop_number)
{
	Timer t1, t2; 
	Vector x(dim), y(dim);
	for(int j = 0; j < dim; j++)
	{
		x(j) = random();
		y(j) = random();
	}

/* * Timing using "+" operator */
	t1.start(); 
	for(int i=0; i < loop_number; i++){
		for(int k=0; k < dim; k++)
			y(k) = y(k) + x(k);
  }	
	t1.stop(); 
	std::cout << "Time taken to run vector addition using overloaded + operator: " << t1.elapsed() << std::endl;
 
/* Timing using "+=" operator */
	t2.start(); 
	for(int i=0; i < loop_number; i++){
		//for(int k=0; k < dim; k++)
			y += x;
  }	
	t2.stop(); 
 	std::cout << "Time taken to run vector addition using overloaded += operator: " << t2.elapsed() << std::endl;

	cout << " Ratio of time taken for vector addition with high performance = " << t1.elapsed()/t2.elapsed()  << endl;
}

// Low performance loop for scalar multiplication, to be written into timed_add_vec_ppe.txt

void time_mul_vec_ppe(int dim, int loop_number)
{
	Timer t1, t2; 
	Vector x(dim), y(dim);
	for(int j = 0; j < dim; j++)
	{
		x(j) = random();
		y(j) = random();
	}
	double a = random();

/* * Timing using "+" operator */
	t1.start(); 
	for(int i=0; i < loop_number; i++){
		//for(int k=0; k < dim; k++)
			y = y + a*x;
  }	
	t1.stop(); 
	std::cout << "Time taken to run scalar multiplication using overloaded + operator: " << t1.elapsed() << std::endl;
 
/* Timing using "+=" operator */
	t2.start(); 
	for(int i=0; i < loop_number; i++){
		//for(int k=0; k < dim; k++)
			y += a*x;
  }	
	t2.stop(); 
 	std::cout << "Time taken to run scalar multiplication using overloaded += operator: " << t2.elapsed() << std::endl;
  
	cout << " Ratio of scalar multiplication low performance= " << t1.elapsed()/t2.elapsed() << endl;
}

// High Performance Loop for scalar multiplication, tobe written into timed_add_vec_hpe.txt

void time_mul_vec_hpe(int dim, int loop_number)
{
	Timer t1, t2; 
	Vector x(dim), y(dim);
	for(int j = 0; j < dim; j++)
	{
		x(j) = random();
		y(j) = random();
	}
	double a = random();

/* * Timing using "+" operator */
	t1.start(); 
	for(int i=0; i < loop_number; i++){
		for(int k=0; k < dim; k++)
			y(k) = y(k) + a*x(k);
  }	
	t1.stop(); 
	std::cout << "Time taken to run scalar multiplication using overloaded + operator: " << t1.elapsed() << std::endl;
 
/* Timing using "+=" operator */
	t2.start(); 
	for(int i=0; i < loop_number; i++){
		//for(int k=0; k < dim; k++)
			y += a*x;
  }	
	t2.stop(); 
 	std::cout << "Time taken to run scalar multiplication using overloaded += operator: " << t2.elapsed() << std::endl;

	cout << " Ratio of time taken scalar multiplication high performance = " << t1.elapsed()/t2.elapsed()  << endl;
}






int main(int argc, char* argv[])
{
	if(argc != 3)
    {
        cout << "Usage: " << argv[0] << " dimension" <<  " loop_number " << endl;
        return -1;
    }
	else{

		int dimension = atoi(argv[1]);
		int loop_number = atoi(argv[2]);

		time_add_vec_ppe(dimension, loop_number);
		time_add_vec_hpe(dimension, loop_number);
		time_mul_vec_ppe(dimension,loop_number);
		time_mul_vec_hpe(dimension,loop_number);
	}
	
	return 0;
}