#include "Player_custom.h"



Player_custom::Player_custom()
{
	dimensions = 70;
	deplacement_x = 10;

	Coordonnee_Player.setX(880);
	Coordonnee_Player.setY(1000);
	setPos(mapToParent(Coordonnee_Player));

	debug_position_player();
	vies = 1;
	//vies = this->parentWidget->option_wid->vies_initiales;
	score = 0;

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

	QPixmap bkgnd;
	bkgnd.load("gendar.png");
	couleur_centre.setTexture(bkgnd);
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

int Player_custom::get_vies()
{
	return vies;
}

void Player_custom::init_vie(Options * opt)
{
	if (opt->une_vie->isChecked())
	{
		vies = 1;
	}
	if (opt->deux_vies->isChecked())
	{
		vies = 2;
	}
	if (opt->trois_vies->isChecked())
	{
		vies = 3;
	}
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
	
	if (vies == 0)
	{
		//delete this; crie in pain 
	}
	
	
	return;
}

void Player_custom::debug_position_player()
{
	std::cout << "Position player x: " << Coordonnee_Player.rx() << std::endl;
	std::cout << "Position player y: " << Coordonnee_Player.ry() << std::endl << std::endl;
}

/*void Player_custom::check_death()
{
	if (vies == 0)
	{
		emmit send_death();
	}
}*/

void Player_custom::move_left()
{
	move("left");
}

void Player_custom::set_lives(int nb_vies)
{
	vies = nb_vies;
}

void Player_custom::add_score(int point)
{
	score = score + point;
}

void Player_custom::set_1vie(bool etat)
{
	if (etat == true)
	{
		vies = 1;
	}
}


void Player_custom::move_right()
{
	move("right");
}

