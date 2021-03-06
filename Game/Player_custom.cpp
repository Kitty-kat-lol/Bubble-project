#include "Player_custom.h"



Player_custom::Player_custom()
{
	dimensions = 70;
	deplacement_x = 10;

	Coordonnee_Player.setX(880);
	Coordonnee_Player.setY(1000);
	setPos(mapToParent(Coordonnee_Player));

	debug_position_player();
	
}


Player_custom::~Player_custom()
{
}

QRectF Player_custom::boundingRect() const
{
	return QRectF(0,0,dimensions,dimensions);
}

void Player_custom::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QRectF hitbox = boundingRect();
	QBrush couleur_centre(Qt::blue);
	if (!scene()->collidingItems(this).isEmpty())
	{
		
		if (scene()->collidingItems(this).contains(Line_Left_Item))
		{
			couleur_centre.setColor(Qt::black);
		}
		else if (scene()->collidingItems(this).contains(Line_Right_Item))
		{
			couleur_centre.setColor(Qt::yellow);
		}
	}

	

	painter->setBrush(couleur_centre);
	painter->drawRect(hitbox);
}

bool Player_custom::check_borders(QString side)
{
	if (side == "right")
	{
		if (scene()->collidingItems(this).contains(Line_Right_Item))
		{
			return false;
		}		
	}

	else if (side == "left")
	{
		if (scene()->collidingItems(this).contains(Line_Left_Item))
		{
			return false;
		}
	}

	else if (side == "both")
	{
		if (scene()->collidingItems(this).contains(Line_Right_Item) || scene()->collidingItems(this).contains(Line_Left_Item))
		{
			return false;
		}
	}

	return true;
}

void Player_custom::move(QString direction)
{

	if (direction == "left" && check_borders("left"))
	{
		this->setPos(mapToParent(-(deplacement_x), 0));
		Coordonnee_Player = scenePos();
		std::cout << "Mouvement!" << std::endl;
		debug_position_player();
		std::cout << std::endl;
		
	}
	else if (direction == "right" && check_borders("right"))
	{
		this->setPos(mapToParent(deplacement_x, 0));
		Coordonnee_Player = scenePos();
		std::cout << "Mouvement!" << std::endl;
		debug_position_player();
		std::cout << std::endl;
	}
	return;
}

void Player_custom::advance(int phase)
{
	/*if (!phase)
	{
		return;
	}

	Coordonnee_Player = this->pos();

	this->setPos(mapToParent(Coordonnee_Player));
	return;*/

	/*QThread::msleep(200);
	//move_left();
	QThread::msleep(200);
	this->setPos(mapToParent(deplacement_x, 0));
	QThread::msleep(200);*/
	//move("right");
	

	
	
	return;
}

void Player_custom::debug_position_player()
{
	std::cout << "Position player x: " << Coordonnee_Player.rx() << std::endl;
	std::cout << "Position player y: " << Coordonnee_Player.ry() << std::endl << std::endl;
}

void Player_custom::move_left()
{
	move("left");
}


void Player_custom::move_right()
{
	move("right");
}

