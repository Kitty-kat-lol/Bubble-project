#ifndef BULLE_CUSTOM_H
#define BULLE_CUSTOM_H

#include <QPainter>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <iostream>

class Bulle_Custom : public QGraphicsItem
{
	//Q_OBJECT
public:
	Bulle_Custom();
	~Bulle_Custom();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
//private:
	QGraphicsLineItem *Line_Top_Item;
	QGraphicsLineItem *Line_Left_Item;
	QGraphicsLineItem *Line_Right_Item;
	QGraphicsLineItem *Line_Bottom_Item;

	QPointF Coordonnee_Bulle;
	qreal angle;
	qreal vitesse_x;
	qreal vitesse_y;
	int rayon;
	void collision();
protected:
	void advance(int phase);
public slots :


};




#endif
