#ifndef JEU_H
#define JEU_H
#include "Bulle_custom.h"
#include "Player_custom.h"
#include "Arrow_Custom.h"

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
#include <QKeyboardHandler>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGamepad>

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

	void debug_position_bulle();
	void shoot_arrow();
	void keyPressEvent(QKeyEvent *event);
	void customEvent(QEvent *input);
	void gamepad_control();

	QGraphicsScene* get_Frame();
	Bulle_Custom* get_Bulle();
	
	QTimer* get_temps();
	

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
	Player_custom *Player;
	QTimer *temps;
	Arrow_Custom *Arrow;
	Plan_Frame Plan;

	QGamepad *Xbox;

};




#endif // !ACCEUIL_H