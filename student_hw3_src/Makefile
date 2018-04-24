
#
# This file is part of the course materials for AMATH483/583 at the University of Washington,
# Spring 2018
#
# Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
# https://creativecommons.org/licenses/by-nc-sa/4.0/
#
# Author: Andrew Lumsdaine
#

OPT_FLAGS	= -O3		# Also try -Ofast -march=native
STD_FLAGS 	= -std=c++11
DBG_FLAGS	= 
PICKY		= -Wall
CXX_FLAGS	= $(OPT_FLAGS) $(DBG_FLAGS) $(PICKY) $(STD_FLAGS)

bench: bench.o Matrix.o
	c++ $(CXX_FLAGS) bench.o Matrix.o -o bench

bench.o: bench.cpp Matrix.hpp
	c++ $(CXX_FLAGS) -c bench.cpp -o bench.o

Matrix.o: Matrix.cpp Matrix.hpp
	c++ $(CXX_FLAGS) -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp
	c++ $(CXX_FLAGS) -c Vector.cpp -o Vector.o

clean:
	/bin/rm -f bench bench.o Matrix.o Vector.o 
