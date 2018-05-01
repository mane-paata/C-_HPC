
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

all: add_vec.exe timed_add_vec.exe st_vec.exe 

add_vec.exe: add_vec.cpp Vector.o amath583.o
	c++ $(CXX_FLAGS) add_vec.cpp Vector.o amath583.o -o add_vec.exe 

timed_add_vec.exe: timed_add_vec.cpp Timer.hpp Vector.o amath583.o
	c++ $(CXX_FLAGS) timed_add_vec.cpp Vector.o amath583.o -o timed_add_vec.exe

st_vec.exe: st_vec.cpp Vector.o amath583.o
	c++ $(CXX_FLAGS) st_vec.cpp Vector.o amath583.o -o st_vec.exe 

amath583.o: amath583.cpp amath583.hpp 
	c++ $(CXX_FLAGS) -c amath583.cpp -o amath583.o

bench: bench.o Matrix.o
	c++ $(CXX_FLAGS) bench.o Matrix.o -o bench

bench.o: bench.cpp Matrix.hpp
	c++ $(CXX_FLAGS) -c bench.cpp -o bench.o

Matrix.o: Matrix.cpp Matrix.hpp
	c++ $(CXX_FLAGS) -c Matrix.cpp -o Matrix.o

Vector.o: Vector.cpp Vector.hpp
	c++ $(CXX_FLAGS) -c Vector.cpp -o Vector.o

clean:
	/bin/rm -f bench bench.o Matrix.o Vector.o amath583.o add_vec.exe timed_add_vec.exe st_vec.exe 
