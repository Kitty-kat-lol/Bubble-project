#ifndef PLAY_H
#define PLAY_H


#include "Bulle_custom.h"
#include "Bebe_Bulle.h"
#include "Player_Custom.h"
#include "Arrow_Custom.h"
#include "Input_FPGA.h"
#include "Scores.h"
#include "Options.h"

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <Qmessagebox>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QList>
#include <QInputDialog>


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
#include <QGraphicsObject>
#include <Qlist>
#include <QObject>




class Bubble_Trouble : public  QGraphicsView, QObject
{
	Q_OBJECT
public:
	Bubble_Trouble();
	Bubble_Trouble(Options *options, Scores *score);
	~Bubble_Trouble();

	void debug_position_bulle();
	void shoot_arrow();
	void keyPressEvent(QKeyEvent *event);
	void customEvent(QEvent *input);
	
	
	void phoneme_control();

	QList<Bebe_Bulle *> Bebelist;
	Scores *scores;
	Options *option;
	QGraphicsScene* get_Frame();
	Bulle_Custom* get_Bulle();

	QTimer* get_temps();

	bool debug;

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
	QTimer *Thread_FPGA;
	QTimer *events;
	QTimer *Thread_Xbox;
	Arrow_Custom *Arrow;
	//Plan_Frame Plan;

	QGamepad *Xbox;
	Input_FPGA *Carte;
	
	public slots:
	void gamepad_control();
	void Death();
	void bulle_event();
	void set_bulle_speed(int pourcent);
};


struct stru_play
{
	QString name;
	QString score;
};

class Play :public QWidget
{
	Q_OBJECT
public:
	Play();
	Play(Options *option, Scores *scores);
	~Play();

	QPushButton *Start;
	QPushButton *Quit;
	Bubble_Trouble *test;
	Scores *score;
	Options *options;

	public slots:

	void Quit_play();
	void Start_play();
private:
	QMainWindow App;

};



struct Plan_Frame
{
	int horizontal_min;
	int horizontal_max;
	int vertical_min;
	int vertical_max;
};

#endif
