#include "Player.h"

Player::Player()
{
	position.x = 113;//Initialise sa position au centre du terminal
	position.y = 0;
	state = 'a';
	life = 3;
}

Player::~Player()
{
}


Coordonnee Player::move(char direction)
{
	int displacement = 5;//Nombre de cases déplacées
	if (direction == 'l')
	{
		if(position.x - displacement>=0)
		position.x=position.x- displacement;
	}
	if (direction == 'r')
	{
		if(position.x + displacement<168)
		position.x = position.x+ displacement;
	}
	return position;
}

Coordonnee Player::get_position()
{
	return position;
}

void Player::set_state(char command)
{
	state = command;
}

void Player::shoot_arrow()
{
	Arrow.set_state('a');
	Coordonnee change = position;
	change.y++;
	Arrow.set_position(change);
}

void Player::hit()
{
	life--;
}

int Player::get_life()
{
	return life;
}

Coordonnee Player::get_arrow_position()
{
	Coordonnee out;
	out = Arrow.get_position();
	return out;
}


