output: main.o inputVal.o menu.o stoogesort.o stoogeTime.o
	g++ -std=c++11 main.o inputVal.o menu.o stoogesort.o stoogeTime.o -o output -lm

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

stoogesort.o: stoogesort.cpp stoogesort.hpp
	g++ -std=c++11 -c stoogesort.cpp


stoogeTime.o: stoogeTime.cpp stoogeTime.hpp
	g++ -std=c++11 -c stoogeTime.cpp

clean:
	rm *.o output
