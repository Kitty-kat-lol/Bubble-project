
#ifndef BULLE_H
#define BULLE_H

#include <iostream>
#include "Coordonne.h"

using namespace std;

class Bulle
{
	public:
		Bulle();
		Bulle(int size, int x_start_bulle, int y_start_bulle, int vitesse_initiale_y, int vitesse_x);
		~Bulle();

		void afficher_bulle(int hauteur, int largeur);
		Coordonnee rebound(int temps, int step, Coordonnee bulle_xy, int max_x);
		void break_bulle();
		Coordonnee get_xy();

		void pop_layer();
		int get_layers();
		

	private:
		int bulle_size;
		int x_start_bulle;
		int y_start_bulle;
		int vitesse_initiale_y;
		int vitesse_x;
		int acceleration_y;
		int vitesse_y;
		int layers;

	protected:
		Coordonnee bulle_xy;

};

#endif