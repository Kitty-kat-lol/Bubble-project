#include "Bulle_custom.h"
#include "Play.h"
#include <cstdlib>

Bulle_Custom::Bulle_Custom()
{

	//Couleur de départ
	
	//Part avec un angle aléatoire
	angle = (rand() % 360);
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
	power = 0;
	baby = 1;
	layers = -1;
}

Bulle_Custom::Bulle_Custom(qreal posx, qreal posy)
{

	angle = (rand() % 360);

	//Commence dans le coin en haut à droite
	Coordonnee_Bulle.setX(posx);//posx
	Coordonnee_Bulle.setY(posy);//posy
	setPos(mapToParent(Coordonnee_Bulle));

	//Vitesses de départ
	vitesse_x = -7;
	vitesse_y = -7;
	rayon = 80;

	power = 1;
	layers = 1;

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
	bkgnd1.load("player.png");
	bkgnd2.load("Prof.png");
	bkgnd3.load("Denis.png");
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
	}
	else if (scene()->collidingItems(this).contains(Player))
	{
		//Pour éviter que la bulle traverse le player et le tue big time
		vitesse_x *= -1;
		vitesse_y *= -1;
		std::cout << "La vitesse x est de: " << vitesse_x << std::endl;
		std::cout << "La vitesse y est de: " << vitesse_y << std::endl;
		Player->vies--;
	}
	else if (scene()->collidingItems(this).contains(Arrow))
	{
		//Bulle hit
		layers--;
		cout << layers;
		
		int point = 100; // * nbre de boules présentes
		Player->add_score(point);
		baby = 1;
		/*if (power != 0)
		{
			delete this;
		}*/
		if (layers == 0)
		{
			delete this;
		}
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
