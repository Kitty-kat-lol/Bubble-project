#pragma once
#include "Bulle_Custom.h"
class Bebe_Bulle :
	public Bulle_Custom
{
public:
	Bebe_Bulle::Bebe_Bulle(qreal posx, qreal posy);
	Bebe_Bulle();
	~Bebe_Bulle();

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};

