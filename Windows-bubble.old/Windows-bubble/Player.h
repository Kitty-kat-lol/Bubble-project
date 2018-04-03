#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "stdafx.h"
#include "Arrow.h"


class Player
{
	public:
		Player();
		~Player();
		Arrow shoot_arrow();
		Coordonnee move(char direction);
		Coordonnee get_position();
		void set_state(char command);
	private:
		char state;
		Arrow Arrow;
	protected:
		Coordonnee position;
};
#endif
