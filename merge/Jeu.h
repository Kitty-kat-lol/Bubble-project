#ifndef JEU_H
#define JEU_H
#include "Bulle_custom.h"

#include <QMAINWINDOW>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QPolygonF>
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <iostream>
#include <QTimer>
#include <QPainter>

struct Plan_Frame
{
	int horizontal_min;
	int horizontal_max;
	int vertical_min;
	int vertical_max;
};

class Bubble_Trouble : public QGraphicsView
{
	
public:
	Bubble_Trouble();
	~Bubble_Trouble();

	void move_bubble();

	QGraphicsScene* get_Frame();
	Bulle_Custom* get_Bulle();
	QTimer* get_temps();
	QGraphicsItemAnimation* get_Trajectoire_Bulle();

	void collision_bulle();
//private:
	QLineF Line_Top;
	QLineF Line_Left;
	QLineF Line_Right;
	QLineF Line_Bottom;

	QGraphicsLineItem *Line_Top_Item;
	QGraphicsLineItem *Line_Left_Item;
	QGraphicsLineItem *Line_Right_Item;
	QGraphicsLineItem *Line_Bottom_Item;


	QGraphicsScene *Frame;
	Bulle_Custom *Bulle;
	QTimer *temps;
	QGraphicsItemAnimation *Trajectoire_Bulle;
	Plan_Frame Plan;

};




#endif // !ACCEUIL_H