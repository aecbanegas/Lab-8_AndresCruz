Main: Main.o Rey.o Peon.o WRFile.o Partido.o
	g++ Main.o Rey.o Peon.o WRFile.o Partido.o -o Ejecutable
Main.o: Main.cpp
	g++ -c Main.cpp
Rey.o: Rey.cpp Rey.h Pieza.h
	g++ -c Rey.cpp
Peon.o: Peon.cpp Peon.h Pieza.h
	g++ -c Peon.cpp
WRFile.o: WRFile.cpp WRFile.h
	g++ -c WRFile.cpp
Partido.o: Partido.cpp Partido.h
	g++ -c Partido.o