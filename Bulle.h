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
		Coordonnee rebound(int temps, int step, Coordonnee bulle_xy);
		void break_bulle();
		Coordonnee get_xy();

	private:
		int bulle_size;
		int x_start_bulle;
		int y_start_bulle;
		int vitesse_initiale_y;
		int vitesse_x;
		int acceleration_y;
		int vitesse_y;

	protected:
		Coordonnee bulle_xy;

};










#endif
