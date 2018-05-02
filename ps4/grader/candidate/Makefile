
#
# This file is part of the course materials for AMATH483/583 at the University of Washington,
# Spring 2018
#
# Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
# https://creativecommons.org/licenses/by-nc-sa/4.0/
#
# Author: Andrew Lumsdaine
#

OPT_FLAGS	= -O3		# Also try -Ofast -march=native ; -O0 for no optimization
STD_FLAGS 	= -std=c++11
DBG_FLAGS	= 
PICKY		= -Wall
TEMPLATED	= -D__TEMPLATED  # uncomment this to turn on templates
CXX_FLAGS	= $(OPT_FLAGS) $(DBG_FLAGS) $(PICKY) $(STD_FLAGS) $(TEMPLATED)
CXX		= c++

<<<<<<< Updated upstream
mat_vec.exe: mat_vec.cpp Matrix.o Vector.o amath583IO.o matvec583.o
	c++ $(CXX_FLAGS) mat_vec.cpp Matrix.o Vector.o amath583IO.o matvec583.o -o add_vec.exe
=======
all: square_root.exe mat_vec.exe smat_T_vec.exe

mat_vec.exe:	mat_vec.cpp amath583.hpp amath583IO.o
	$(CXX) $(CXX_FLAGS) mat_vec.cpp amath583IO.o -o mat_vec.exe

smat_T_vec.exe:	smat_T_vec.cpp amath583.hpp amath583IO.o
	$(CXX) $(CXX_FLAGS) smat_T_vec.cpp amath583IO.o -o smat_T_vec.exe

square_root.exe:	square_root.cpp amath583IO.o
	$(CXX) $(CXX_FLAGS) square_root.cpp amath583IO.o -o square_root.exe
>>>>>>> Stashed changes

bench:	bench.o Matrix.o Vector.o amath583.o matmat583.o amath583IO.o
	$(CXX) $(CXX_FLAGS) bench.o Matrix.o Vector.o amath583.o amath583IO.o matmat583.o -o bench

bench.o: bench.cpp amath583.hpp Vector.hpp Matrix.hpp matmat583.hpp amath583IO.o
	$(CXX) $(CXX_FLAGS) -c bench.cpp

sparsebench:	sparsebench.o COO.o Vector.o amath583.o amath583IO.o 
	$(CXX) $(CXX_FLAGS) sparsebench.o COO.o Vector.o amath583.o amath583IO.o -o sparsebench

sparsebench.o	: sparsebench.cpp amath583.hpp Vector.hpp COO.hpp
	$(CXX) $(CXX_FLAGS) -c sparsebench.cpp

amath583IO.o: amath583IO.cpp amath583IO.hpp Vector.hpp Matrix.hpp COO.hpp
	$(CXX) $(CXX_FLAGS) -c amath583IO.cpp

amath583.o: amath583.cpp amath583.hpp Vector.hpp Matrix.hpp matmat583.hpp
	$(CXX) $(CXX_FLAGS) -c amath583.cpp

Matrix.o: Matrix.cpp Matrix.hpp
	$(CXX) $(CXX_FLAGS) -c Matrix.cpp

Vector.o: Vector.cpp Vector.hpp
	$(CXX) $(CXX_FLAGS) -c Vector.cpp

matmat583.o: matmat583.cpp amath583.hpp Vector.hpp Matrix.hpp matmat583.hpp
	$(CXX) $(CXX_FLAGS) -c matmat583.cpp


clean:
	/bin/rm -f sparsebench sparsebench.o bench bench.o \
		Matrix.o Vector.o matmat583.o matvec583.o amath583.o amath583IO.o\
		COO.o \
		*.gch *~ \
		*.exe *.o
