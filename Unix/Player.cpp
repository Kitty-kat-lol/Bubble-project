#include "Player.h"

Player::Player()
{
	position.x = 84;
	position.y = 0;
	state = 'a';
}

Player::~Player()
{
}

Arrow Player::shoot_arrow()
{
	return Arrow;
}

Coordonnee Player::move(char direction)
{
	int displacement = 5;
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
