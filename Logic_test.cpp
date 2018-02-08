#include <math.h>
#include <iostream>
#include "Bulle.h"
#include "Coordonne.h"

int main()
{
	//Display()	grid;
	int pixel_x = 500;
	int pixel_y = 500;
	double temps = 0;
	double step = 0.02; // step en secondes
	Bulle bulle1;
	Coordonnee position;
	int x_depart_bulle = 50;	//position de départ de bulle
	int y_depart_bulle = 300;
	int vitesse_initiale_y = 0;
	while (temps != -1)		// quand la boule est detruite alors temps = -1
	{
		position = bulle1.rebound(temps, step, vitesse_initiale_y, position);
		bulle1.afficher_bulle();
		temps = temps + step;
		std::cout << position.x << position.y << std::endl;
		// system.sleep(step);
	}
	return 0;
}
