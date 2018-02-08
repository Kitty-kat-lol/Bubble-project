#Makefile de test de Buble Trouble


#Executable

Logic_test: Logic_test.o Bulle.o
	g++ -o Bubble Logic_test.o Bulle.o

#Objets

logic_test.o: Logic_test.cpp Bulle.h Coordonne.h
	g++ Logic_test.cpp -g -c

Bulle.o: Bulle.cpp Bulle.h Coordonne.h
	g++ Bulle.cpp -g -c


#Clean

clean:
	rm *.o

#Fin du Makefil
