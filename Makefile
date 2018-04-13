

all: testWrite infRandom dot583

vector.o: Vector.cpp Vector.hpp
	c++ -g -std=c++11 -Wall -c Vector.cpp -o Vector.o

amath583.o: amath583.cpp amath583.hpp
	c++ -g -std=c++11 -Wall -c amath583.cpp -o amath583.o

testWrite: testWrite.cpp amath583.o vector.o
	c++ -g -std=c++11 -Wall testWrite.cpp amath583.o vector.o -o testWrite

infRandom: infRandom.cpp amath583.o vector.o
	c++ -g -std=c++11 -Wall infRandom.cpp amath583.o vector.o -o infRandom

dot583: dot583.cpp amath583.o vector.o
	c++ -g -std=c++11 -Wall dot583.cpp amath583.o vector.o -o dot583

clean: 
	rm -f vector.o amath583.o testWrite infRandom dot583