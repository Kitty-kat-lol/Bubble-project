//
//

#include "Bulle.h"


Bulle :: Bulle()
{
	bulle_size = 1;
	bulle_xy.x = 300;
	bulle_xy.y = 300;
	vitesse_initiale_y = 0;
	vitesse_y = vitesse_initiale_y;
	vitesse_x = 10;
	acceleration_y = 3;
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

void Bulle :: afficher_bulle()
{
	int pixel_x = 500; // à retirer dès que la connection avec display est etablie
	int pixel_y = 500; // à retirer dès que la connection avec display est etablie
	int i = 0;
	int j = 0;
	for (i = 0;i < 500; i ++)
	{
		for (j = 0;j < 500; i ++)
		{
			if (bulle_xy.x == i && bulle_xy.y == j)
			{
				std::cout << "O";
			}
			else
			std::cout << " ";
		}
	}
}

Coordonnee Bulle :: rebound(int temps, int step, Coordonnee reb_xy)
{
	int pixel_x = 500; // à retirer dès que la connection avec display est etablie
	if (reb_xy.x + (vitesse_x * (step)) <= 1 || reb_xy.x + (vitesse_x * (step)) >= (pixel_x - 1))
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
