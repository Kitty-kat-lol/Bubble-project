#Makefile de test de Buble Trouble


#Executable

Logic_test: Logic_test.o Bulle.o Player.o Frame.o Arrow.o
	g++ -o Bubble Logic_test.o Bulle.o Player.o Frame.o Arrow.o

#Objets

Logic_test.o: Logic_test.cpp Bulle.h Coordonne.h
	g++ Logic_test.cpp -g -c

Bulle.o: Bulle.cpp Bulle.h Coordonne.h
	g++ Bulle.cpp -g -c

Player.o: Player.cpp Player.h Coordonne.h
	g++ Player.cpp -g -c

Frame.o: Frame.cpp Frame.h Coordonne.h
	g++ Frame.cpp -g -c

Arrow.o: Arrow.cpp Arrow.h
	g++ Arrow.cpp -g -c

#Clean

clean:
	rm *.o

#Fin du Makefil
