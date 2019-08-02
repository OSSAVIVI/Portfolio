output: mainProject2.o zoo.o animal.o tiger.o penguin.o turtle.o inputVal.o menu.o
	g++ -std=c++11 mainProject2.o zoo.o animal.o tiger.o penguin.o turtle.o inputVal.o menu.o -o output -lm

mainProject2.o: mainProject2.cpp
	g++ -std=c++11 -c mainProject2.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -std=c++11 -c zoo.cpp

animal.o: animal.cpp animal.hpp
	g++ -std=c++11 -c animal.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -std=c++11 -c tiger.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -std=c++11 -c penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -std=c++11 -c turtle.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

clean:
	rm *.o output