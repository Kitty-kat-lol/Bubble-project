//
//

#include "Bulle.h"


Bulle :: Bulle()
{
	Coordonnee bulle_xy;
	int bulle_size = 1;
	int x_start_bulle = 300;
	bulle_xy.x = 300;
	int y_start_bulle = 300;
	bulle_xy.y = 300;
	int vitesse_initiale_y = 0;
	int vitesse_x = 3;
	int acceleration_y = -1;
}

Bulle :: Bulle(int size, int x_start_bulle, int y_start_bulle, int vitesse_initiale_y, int vitesse_x)
{

}

Bulle :: ~Bulle(){}

void Bulle :: afficher_bulle()
{

}

Coordonnee Bulle :: rebound(int temps, int step, int vitesse_initiale_y, Coordonnee bulle_xy)
{
	vitesse_initiale_y = 0;
	int vitesse_x = 3;
	bulle_xy.x = 300;
	bulle_xy.y = 300;
	int pixel_x = 500; // à retirer dès que la connection avec display est etablie
	if (bulle_xy.x + (vitesse_x * (step)) <= 1 || bulle_xy.x + (vitesse_x * (step)) >= (pixel_x - 1))
	{
		vitesse_x = vitesse_x * (-1);	// si tu arrive aux limites du terrain change de direction.
	}
	bulle_xy.x = bulle_xy.x + (vitesse_x * (step));

	if (temps == 0)
	{
		int vitesse_y = vitesse_initiale_y;
	}
	int acceleration_y = -1; //pixel/secondes2
	int vitesse_y = vitesse_y + (acceleration_y * step);
	if (bulle_xy.y + (vitesse_y * step) < 0)
	{
		bulle_xy.y = 1;
		vitesse_y = vitesse_y * (-1); //si la bulle arrive au plancher elle rebondit
	}
	else
	{
		bulle_xy.y = bulle_xy.y + (vitesse_y * step);
	}
	return bulle_xy;
}

void Bulle :: break_bulle()
{

}
