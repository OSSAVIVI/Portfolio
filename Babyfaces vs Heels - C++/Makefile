output: main.o inputVal.o menu.o wrestler.o
	g++ -std=c++11 main.o inputVal.o menu.o wrestler.o -o output -lm

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

wrestler.o: wrestler.cpp wrestler.hpp
	g++ -std=c++11 -c wrestler.cpp

clean:
	rm *.o output
