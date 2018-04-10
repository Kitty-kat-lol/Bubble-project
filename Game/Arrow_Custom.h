#ifndef ARROW_CUSTOM_H
#define ARROW_CUSTOM_H

#include <QPainter>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QThread>
#include <iostream>

class Arrow_Custom: public QGraphicsItem
{
public:
	Arrow_Custom();
	Arrow_Custom(QPointF Start_position);
	~Arrow_Custom();


	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
	//private:
	QGraphicsLineItem *Line_Top_Item;
	

	QPointF Coordonnee_Arrow;
	
	
	qreal vitesse_y;
	int rayon_x;
	int rayon_y;
	void collision();
protected:
	void advance(int phase);
	public slots :
};

#endif