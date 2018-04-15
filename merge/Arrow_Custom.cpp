#include "Arrow_Custom.h"



Arrow_Custom::Arrow_Custom()
{
	rayon_x = 10;
	rayon_y = 60;

	vitesse_y = -10;

	Coordonnee_Arrow.setX(100);
	Coordonnee_Arrow.setY(70);
	setPos(mapToParent(Coordonnee_Arrow));
}

Arrow_Custom::Arrow_Custom(QPointF Start_position)
{
	rayon_x = 10;
	rayon_y = 60;

	vitesse_y = -10;

	
	setPos(mapToParent(Start_position));
	std::cout << "Feu" << std::endl;
}



Arrow_Custom::~Arrow_Custom()
{
}

QRectF Arrow_Custom::boundingRect() const
{
	return QRectF(0,0,rayon_x,rayon_y);
}

void Arrow_Custom::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QRectF hitbox = boundingRect();
	QBrush couleur_centre(Qt::black);


	if (!scene()->collidingItems(this).isEmpty())
	{
		//Collsion!
		couleur_centre.setColor(Qt::red);
		collision();
	}
	else
	{


	}
	painter->setBrush(couleur_centre);

	//painter->fillRect(hitbox,couleur_centre);
	//painter->drawRect(hitbox);
	painter->drawEllipse(hitbox.x(), hitbox.y(), rayon_x, rayon_y);
	QThread::msleep(5);
}

void Arrow_Custom::collision()
{
	delete this;
}

void Arrow_Custom::advance(int phase)
{
	if (!phase)
	{
		return;
	}

	Coordonnee_Arrow = this->pos();

	this->setPos(mapToParent(0, vitesse_y));
	return;
}
