#include "Bulle_custom.h"

Bulle_Custom::Bulle_Custom()
{

	//Couleur de départ
	
	//Part avec un angle aléatoire
	angle = (qrand() % 360);
	//this->setRotation(angle);

	//Commence dans le coin en haut à droite
	Coordonnee_Bulle.setX(100);
	Coordonnee_Bulle.setY(70);
	setPos(mapToParent(Coordonnee_Bulle));

	//Vitesses de départ
	vitesse_x = 5;
	vitesse_y = -5;

	//Dimension de départ
	rayon =150;

}

Bulle_Custom::~Bulle_Custom()
{
}

QRectF Bulle_Custom::boundingRect() const
{
	return QRectF(0,0,rayon,rayon);
}

void Bulle_Custom::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	
	QRectF hitbox = boundingRect();
	QBrush couleur_centre(Qt::green);
	

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
	painter->drawEllipse(hitbox.x(),hitbox.y(),rayon,rayon);

}

void Bulle_Custom::collision()
{
	if (scene()->collidingItems(this).contains(Line_Bottom_Item) || scene()->collidingItems(this).contains(Line_Top_Item))
	{
		vitesse_y *= -1;
		std::cout << "La vitesse y est de: " << vitesse_y << std::endl;
	}
	else if (scene()->collidingItems(this).contains(Line_Left_Item) || scene()->collidingItems(this).contains(Line_Right_Item))
	{
		vitesse_x *= -1;
		std::cout << "La vitesse x est de: " << vitesse_x << std::endl;
		delete this;
		
	}
}

void Bulle_Custom::advance(int phase)
{
	if (!phase)
	{
		return;
	}

	Coordonnee_Bulle = this->pos();

	this->setPos(mapToParent(vitesse_x,vitesse_y)); 
	return;
}
