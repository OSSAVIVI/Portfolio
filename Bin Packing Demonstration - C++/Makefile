output: main.o inputVal.o menu.o binpacking.o mergesort.o
	g++ -std=c++11 main.o inputVal.o menu.o binpacking.o mergesort.o -o output -lm

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

binpacking.o: binpacking.cpp binpacking.hpp
	g++ -std=c++11 -c binpacking.cpp

mergesort.o: mergesort.cpp mergesort.hpp
	g++ -std=c++11 -c mergesort.cpp

clean:
	rm *.o output
