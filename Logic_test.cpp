#include <math.h>
#include <iostream>

struct Coordonnee{
	int x;
	int y;
};
/*
int main()
{
	int pixel_x = 500;
	int pixel_y = 500;
	int t = 1;
	Coordonnee position;
	int x_depart_bulle = 50;//position de départ de bulle
	while (t == 1)
	{
		for(position.x = x_depart_bulle;position.x < pixel_x;position.x = position.x + 1)
		{
			position.y = rebound(position.x);
			afficher(position);
			systeme.sleep(0.02);
		}
		for(position.x = pixel_x;position.x > 0;position.x = position.x - 1)
		{
			position.y = rebound(position.x);
			afficher(position);
			systeme.sleep(0.02);
		}
	}
	return 0;
}

int rebound(int x)
{
	y = abs(a*(x*x) + b*x + c);
	return y;
}
*/
// logique d'en haut ou logique d'en bas
int main()
{
	int pixel_x = 500;
	int pixel_y = 500;
	int temps = 0;
	int step = 0.02; // step en secondes
	Coordonnee position;
	int x_depart_bulle = 50;	//position de départ de bulle
	int y_depart_bulle = 300;
	int vitesse_initiale_y = 0;
	while (temps != -1)		// quand la boule est detruite alors temps = -1
	{
		position = coords(temps, step, vitesse_initiale_y);
		afficher(position);
		temps = temps + step;
		systeme.sleep(step);
	}
	return 0;
}

Coordonnee coords(int temps, int step, int vitesse_initiale_y;)
{
	int vitesse x = 50; //pixel/secondes
	Coordonnee position;
	if (position.x + (vitesse * step) <= 1 || position.x + (vitesse * step) >= (pixel_x - 1))
	{
		vitesse = vitesse * (-1);	// si tu arrive aux limites du terrain change de direction.
	}
	position.x = position.x + (vitesse * step);
	
	if (temps == 0)
	{
		int vitesse_y = vitesse_initiale_y;
	}
	int acceleration_y = -50; //pixel/secondes2
	int vitesse_y = vitesse_y + (acceleration_y * step);
	if (position.y + (vitesse_y * temps) < 0)
	{
		position.y = 1;
		vitesse_y = vitesse_y * (-1); //si la bulle arrive au plancher elle rebondit
	}
	else
	{
		position.y = position.y + (vitesse_y * temps);
	}
	return position;
}

