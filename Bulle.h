//
//
#ifndef VECTEUR
#define VECTEUR

#include <iostream>
#include <math.h>
#include "Coordonne.h"

class Bulle
{
	public:
		Bulle();
		Bulle(int size, int x_start_bulle, int y_start_bulle, int vitesse_initiale_y, int vitesse_x);
		~Bulle();

		void afficher_bulle();
		Coordonnee rebound(int temps, int step, int vitesse_initiale_y, Coordonnee bulle_xy);
		void break_bulle();

	private:
		Coordonnee bulle_xy;
		int bulle_size;
		int x_start_bulle;
		int y_start_bulle;
		int vitesse_initiale_y;
		int vitesse_x;
		int acceleration_y;
};










#endif
