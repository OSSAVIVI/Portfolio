output: mainProject1.o menu.o langtonAnt.o langtonBoard.o inputVal.o
	g++ mainProject1.o menu.o langtonAnt.o langtonBoard.o inputVal.o -o output

mainProject1.o: mainProject1.cpp
	g++ -c mainProject1.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

langtonAnt.o: langtonAnt.cpp langtonAnt.hpp
	g++ -c langtonAnt.cpp

langtonBoard.o: langtonBoard.cpp langtonBoard.hpp
	g++ -c langtonBoard.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -c inputVal.cpp

clean:
	rm *.o output

