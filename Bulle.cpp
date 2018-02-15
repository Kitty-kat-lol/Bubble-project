//
//

#include "Bulle.h"


Bulle :: Bulle()
{
	bulle_size = 1;
	bulle_xy.x = 15;
	bulle_xy.y = 30;
	vitesse_initiale_y = 0;
	vitesse_y = vitesse_initiale_y;
	vitesse_x = 2;
	acceleration_y = 1;
}

Bulle :: Bulle(int size, int x_start_bulle, int y_start_bulle, int vitesse_start_y, int vit_x)
{
	bulle_size = size;
	bulle_xy.x = x_start_bulle;
	bulle_xy.y = y_start_bulle;
	vitesse_initiale_y = vitesse_start_y;
	vitesse_y = vitesse_initiale_y;
	vitesse_x = vit_x;
	acceleration_y = 3;
}

Bulle :: ~Bulle(){}

void Bulle :: afficher_bulle(int largeur, int hauteur)
{
	int i = 0;
	int j = 0;
	// Clear the cout needed here
	for (i = 0;i < hauteur; i ++)
	{
		std::cout << 'I';
		for (j = 0;j < largeur; j ++)
		{
			if ((bulle_xy.x == j) && ((hauteur - bulle_xy.y) == i))
			{
				std::cout << "O";
			}
			else
			std::cout << " ";
		}
		std::cout << 'I' << std::endl;
	}
}

Coordonnee Bulle :: rebound(int temps, int step, Coordonnee reb_xy, int max_x)
{
	if (reb_xy.x + (vitesse_x * (step)) <= 1 || reb_xy.x + (vitesse_x * (step)) >= (max_x - 1))
	{
		vitesse_x = vitesse_x * (-1);	// si tu arrive aux limites du terrain change de direction.
	}
	reb_xy.x = reb_xy.x + (vitesse_x * (step));

	vitesse_y = vitesse_y - (acceleration_y * step);
	if (reb_xy.y + (vitesse_y * step) < 0)
	{
		reb_xy.y = 1;
		vitesse_y = vitesse_y * (-1); //si la bulle arrive au plancher elle rebondit
	}
	else
	{
		reb_xy.y = reb_xy.y + (vitesse_y * step);
	}
	bulle_xy = reb_xy;
	return reb_xy;
}

void Bulle :: break_bulle()
{

}

Coordonnee Bulle :: get_xy()
{
	return bulle_xy;
}
