#include "Arrow.h"

Arrow::Arrow()
{
	state = 'i';//�tat inactif au d�but
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
	leave();//regarde si la fl�che quitte le tableau
}

void Arrow::leave()
{
	if (position.y >= 40)
	{
		state = 'i';//Met l'�tait de la fl�che a inactive si en dehors du tableau
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


