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
