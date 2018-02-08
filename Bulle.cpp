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

Coordonnee Bulle :: rebound(double temps, double step, int vitesse_initiale_y, Coordonnee bulle_xy)
{
	int pixel_x; // à retirer dès que la connection avec display est etablie
	if (bulle_xy.x + (vitesse_x * step) <= 1 || bulle_xy.x + (vitesse_x * step) >= (pixel_x - 1))
	{
		vitesse_x = vitesse_x * (-1);	// si tu arrive aux limites du terrain change de direction.
	}
	bulle_xy.x = bulle_xy.x + (vitesse_x * step);

	if (temps == 0)
	{
		int vitesse_y = vitesse_initiale_y;
	}
	int acceleration_y = -50; //pixel/secondes2
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
