#ifndef BULLE_CUSTOM_H
#define BULLE_CUSTOM_H

#include "Player_custom.h"
#include "Arrow_Custom.h"
#include <QPainter>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QThread>
#include <iostream>
#include <Qmessagebox>
#include <QObject>


class Bulle_Custom : public QGraphicsItem
{
	//Q_OBJECT
public:
	Bulle_Custom();
	Bulle_Custom::Bulle_Custom(qreal posx, qreal posy);
	~Bulle_Custom();

	QRectF boundingRect() const;
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
//private:
	QGraphicsLineItem *Line_Top_Item;
	QGraphicsLineItem *Line_Left_Item;
	QGraphicsLineItem *Line_Right_Item;
	QGraphicsLineItem *Line_Bottom_Item;
	
	Arrow_Custom *Arrow;
	Player_custom *Player;

	QPixmap bkgnd1;
	QPixmap bkgnd2;
	QPixmap bkgnd3;
	int Random = rand() % 3;

	QPointF Coordonnee_Bulle;
	qreal angle;
	qreal vitesse_x;
	qreal vitesse_y;
	int baby;
	int power;
	int rayon;
	int layers;
	void collision();
	
	void vitesse(int pourcent);
protected:
	void advance(int phase);
public slots :


};




#endif
