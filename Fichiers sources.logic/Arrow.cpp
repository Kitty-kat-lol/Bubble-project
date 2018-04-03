#include "Arrow.h"

Arrow::Arrow()
{
	state = 'i';//État inactif au début
}

Arrow::~Arrow()
{
}

Coordonnee Arrow::get_position()
{
	return position;
}

void Arrow::move()
{
	position.y += y_speed;
	leave();//regarde si la flèche quitte le tableau
}

void Arrow::leave()
{
	if (position.y >= 40)
	{
		state = 'i';//Met l'était de la flèche a inactive si en dehors du tableau
	}
}

void Arrow::set_state(char command)
{
	state = command;
}

char Arrow::get_state()
{
	return state;
}

void Arrow::set_position(Coordonnee in)
{
	position = in;
}


