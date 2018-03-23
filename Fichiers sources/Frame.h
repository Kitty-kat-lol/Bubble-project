#ifndef FRAME_H
#define FRAME_H

#include <iostream>

#include "Player.h"
#include "Bulle.h"
#include <string>


using namespace std;



class Frame
{
public:
	Frame();
	~Frame();
	void refresh();//Appele les autres fonctions d'affichage et de mouvement des objets
	
	//Fonctions d'affichage de test, plus utilisé
	void print_test_blank();
	void print_test_dot();

	//Affiche les différents objets
	void print_test_table();//Affiche les caractères du table dans le terminale

	//Assigne les différents objets à leur position dans le tableau
	void print_test_player();
	void print_test_arrow();
	void print_test_bulle();
	void print_test_count();
	void reset_frame();

	//Permet de toucher la bulle
	void collision_bulle();

	//Permet de toucher le player
	void collision_player();
	
	//Retourne les différents attributs
	int get_x();
	int get_y();
	bool get_win();

	//Change la valeur des attributs
	void set_win(bool command);


	Player player;
	Bulle bulle;
	string print;
private:
	char table[62][237];//à modifier selon l'ordi utilisé!
	bool win;
protected:
	Coordonnee dimension;

};
#endif
