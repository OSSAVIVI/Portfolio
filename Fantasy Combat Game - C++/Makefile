output: mainProject4.o inputVal.o menu.o barbarian.o blueMen.o character.o gameEngine.o lineup.o harryPotter.o medusa.o vampire.o
	g++ -std=c++11 mainProject4.o inputVal.o menu.o barbarian.o blueMen.o character.o gameEngine.o lineup.o harryPotter.o medusa.o vampire.o -o output -lm

mainProject4.o: mainProject4.cpp
	g++ -std=c++11 -c mainProject4.cpp

inputVal.o: inputVal.cpp inputVal.hpp
	g++ -std=c++11 -c inputVal.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -std=c++11 -c barbarian.cpp

blueMen.o: blueMen.cpp blueMen.hpp
	g++ -std=c++11 -c blueMen.cpp

character.o: character.cpp character.hpp
	g++ -std=c++11 -c character.cpp

gameEngine.o: gameEngine.cpp gameEngine.hpp
	g++ -std=c++11 -c gameEngine.cpp

lineup.o: lineup.cpp lineup.hpp
	g++ -std=c++11 -c lineup.cpp

harryPotter.o: harryPotter.cpp harryPotter.hpp
	g++ -std=c++11 -c harryPotter.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -std=c++11 -c medusa.cpp

vampire.o: vampire.cpp vampire.hpp
	g++ -std=c++11 -c vampire.cpp

clean:
	rm *.o output