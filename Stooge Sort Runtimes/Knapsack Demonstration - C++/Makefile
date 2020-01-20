output: main.o inputVal.o menu.o shopping.o 
	g++ -std=c++11 main.o inputVal.o menu.o shopping.o -o output -lm

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

shopping.o: shopping.cpp shopping.hpp
	g++ -std=c++11 -c shopping.cpp

clean:
	rm *.o output
