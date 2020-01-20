output: main.o inputVal.o menu.o mergesort.o insertsort.o mergeTime.o insertTime.o
	g++ -std=c++11 main.o inputVal.o menu.o mergesort.o insertsort.o mergeTime.o insertTime.o -o output -lm

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

mergesort.o: mergesort.cpp mergesort.hpp
	g++ -std=c++11 -c mergesort.cpp

insertsort.o: insertsort.cpp insertsort.hpp
	g++ -std=c++11 -c insertsort.cpp

mergeTime.o: mergeTime.cpp mergeTime.hpp
	g++ -std=c++11 -c mergeTime.cpp

insertTime.o: insertTime.cpp insertTime.hpp
	g++ -std=c++11 -c insertTime.cpp

clean:
	rm *.o output