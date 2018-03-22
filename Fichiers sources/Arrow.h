#ifndef ARROW_H
#define ARROW_H

#include "Coordonne.h"
#include <string>

class Arrow
{
public:
	Arrow();
	~Arrow();
	Coordonnee get_position();
	void move();
	void leave();
	void set_state(char command);
	char get_state();
	void set_position(Coordonnee in);
private:
	int y_speed=5;//Vitesse de déplacement de la flèche
	char state;
protected:
	Coordonnee position;
};

#endif
