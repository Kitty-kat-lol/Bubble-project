#ifndef JEU_H
#define JEU_H

#include <QMAINWINDOW>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QPolygonF>
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <iostream>
//#include <QTest>

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
	QGraphicsEllipseItem* get_Bulle();
	QTimeLine* get_temps();
	QGraphicsItemAnimation* get_Trajectoire_Bulle();
private:

	QGraphicsScene *Frame;
	QGraphicsEllipseItem *Bulle;
	QTimeLine *temps;
	QGraphicsItemAnimation *Trajectoire_Bulle;
	Plan_Frame Plan;

};




#endif // !ACCEUIL_H