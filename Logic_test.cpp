#include <math.h>
#include <iostream>
#include "Bulle.h"
#include "Coordonne.h"

int main()
{
	//Display()	grid;
	int pixel_x = 50;
	int pixel_y = 20;
	int temps = 0;
	int step = 1; // step en secondes
	Bulle bulle1;
	Coordonnee position;
	position = bulle1.get_xy();
	while (temps != -1)		// quand la boule est detruite alors temps = -1
	{
		position = bulle1.rebound(temps, step, position, pixel_x);
		bulle1.afficher_bulle(pixel_x, pixel_y);
		temps = temps + step;
		std::cout << "X" << position.x << "Y" << position.y << std::endl;
		 // system.msleep(&step);
		std::cout << temps << std::endl;
	}
	return 0;
}
