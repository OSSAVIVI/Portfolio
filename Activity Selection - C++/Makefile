output: main.o inputVal.o menu.o mergesort.o activitySelection.o
	g++ -std=c++11 main.o inputVal.o menu.o mergesort.o activitySelection.o -o output -lm

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

mergesort.o: mergesort.cpp mergesort.hpp
	g++ -std=c++11 -c mergesort.cpp

activitySelection.o: activitySelection.cpp activitySelection.hpp
	g++ -std=c++11 -c activitySelection.cpp

clean:
	rm *.o output
