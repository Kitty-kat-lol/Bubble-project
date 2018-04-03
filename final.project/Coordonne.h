#ifndef COORDONNE_H
#define COORDONNE_H

#include <math.h>




struct Coordonnee{
	int x;
	int y;

	//friend bool& operator == (Coordonnee compare1, Coordonnee compare2);//Tentative d'overload d'operator, ne marche pas :(
	/*{
		bool hitbox = false;

		if ((abs(this->x - compare.x)) <= 5 && (abs(this->y - compare.y)) <= 5)
		{
			hitbox = true;
		}
		return hitbox;
	}*/
};

/*bool& operator == (Coordonnee compare1, Coordonnee compare2)//Tentative d'overload d'operator, ne marche pas :(
	{
	bool hitbox = false;

	if ((abs(compare1.x - compare2.x)) <= 5 && (abs(compare1.y - compare2.y)) <= 5)
		{
		hitbox = true;
		}
	return hitbox;
	}*/
#endif
