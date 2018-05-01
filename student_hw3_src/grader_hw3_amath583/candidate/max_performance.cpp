#include <iostream>
#include <cstdlib>

#include "Timer.hpp"

using namespace std;

int main(){

	size_t N = 1024*1024*1024;
	double num1 = random(), num2 = random(), sum = 0.0, time; 
	Timer T; 
	T.start();
	for (size_t i = 0; i < N; ++i) 
		sum += num1*num2; 
	T.stop(); 
	cout << sum << endl;
	time = T.elapsed();
	cout << "Time elapsed " << time << endl;
	cout << "Floating point rate " << N/time << endl;
}