#include "Bebe_Bulle.h"



Bebe_Bulle::Bebe_Bulle()
{
}
Bebe_Bulle::Bebe_Bulle(qreal posx, qreal posy)
{
	angle = (qrand() % 360);
	//Commence dans le coin en haut à droite
	Coordonnee_Bulle.setX(posx);//posx
	Coordonnee_Bulle.setY(posy);//posy
	setPos(mapToParent(Coordonnee_Bulle));
	//Vitesses de départ
	vitesse_x = -7;
	vitesse_y = -7;
	rayon = 80;
	power = 0;
	layers = 1;
}

Bebe_Bulle::~Bebe_Bulle()
{
}

void Bebe_Bulle::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QRectF hitbox = boundingRect();
	QBrush couleur_centre(Qt::green);
	bkgnd1.load("player-bb.png");
	bkgnd2.load("Prof.png");
	bkgnd3.load("Denis-bb.png");
	if (Random == 0)
	{

		couleur_centre.setTexture(bkgnd1);
	}
	else if (Random == 1)
	{
		couleur_centre.setTexture(bkgnd2);
	}
	else if (Random == 2)
	{
		couleur_centre.setTexture(bkgnd3);
	}


	if (scene()->collidingItems(this).isEmpty())
	{
		//Pas de collison
	}
	else
	{
		//Collsion!
		couleur_centre.setColor(Qt::red);
		collision();

	}
	painter->setBrush(couleur_centre);

	//painter->fillRect(hitbox,couleur_centre);
	//painter->drawRect(hitbox);
	painter->drawEllipse(hitbox.x(), hitbox.y(), rayon, rayon);
}
