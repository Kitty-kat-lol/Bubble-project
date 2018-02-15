#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Arrow.h"


class Player
{
public:
	Player();
	~Player();
	Arrow shoot_arrow();
	Coord move(char direction);
	Coord get_position();
	void set_state(char command);
private:
	char state;
	Arrow Arrow;
protected:
	Coord position;
};
#endif
