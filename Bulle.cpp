//
//

#include "Bulle.h"


Bulle :: Bulle()
{

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
	int pixel_x = 500; // à retirer dès que la connection avec display est etablie
	if (bulle_xy.x + (vitesse_x * step/1000) <= 1 || bulle_xy.x + (vitesse_x * step/1000) >= (pixel_x - 1))
	{
		vitesse_x = vitesse_x * (-1);	// si tu arrive aux limites du terrain change de direction.
	}
	bulle_xy.x = bulle_xy.x + (vitesse_x * step/1000);

	if (temps == 0)
	{
		int vitesse_y = vitesse_initiale_y;
	}
	int acceleration_y = -500; //pixel/secondes2
	int vitesse_y = vitesse_y + (acceleration_y * step/1000);
	if (bulle_xy.y + (vitesse_y * step/1000) < 0)
	{
		bulle_xy.y = 1;
		vitesse_y = vitesse_y * (-1); //si la bulle arrive au plancher elle rebondit
	}
	else
	{
		bulle_xy.y = bulle_xy.y + (vitesse_y * step/1000);
	}
	return bulle_xy;
}

void Bulle :: break_bulle()
{

}
