#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Arrow.h"


class Player
{
public:
	Player();
	~Player();

	Coordonnee move(char direction);
	Coordonnee get_position();

	void set_state(char command);
	void shoot_arrow();

	void hit();
	int get_life();

	Coordonnee get_arrow_position();
	Arrow Arrow;

private:
	int life;
	char state;
	
protected:
	Coordonnee position;
};
#endif
