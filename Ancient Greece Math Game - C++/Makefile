output: mainFinalProject.o menu.o inputVal.o spaceGrid.o space.o movementSpace.o riddleSpace.o goldenLyreSpace.o inventory.o
	g++ -std=c++11 mainFinalProject.o menu.o inputVal.o spaceGrid.o space.o movementSpace.o riddleSpace.o goldenLyreSpace.o inventory.o -o output -lm

mainFinalProject.o: mainFinalProject.cpp
	g++ -std=c++11 -c mainFinalProject.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

spaceGrid.o: spaceGrid.cpp spaceGrid.hpp
	g++ -std=c++11 -c spaceGrid.cpp

space.o: space.cpp space.hpp
	g++ -std=c++11 -c space.cpp

movementSpace.o: movementSpace.cpp movementSpace.hpp
	g++ -std=c++11 -c movementSpace.cpp

riddleSpace.o: riddleSpace.cpp riddleSpace.hpp
	g++ -std=c++11 -c riddleSpace.cpp

goldenLyreSpace.o: goldenLyreSpace.cpp goldenLyreSpace.hpp
	g++ -std=c++11 -c goldenLyreSpace.cpp

inventory.o: inventory.cpp inventory.hpp
	g++ -std=c++11 -c inventory.cpp

clean:
	rm *.o output