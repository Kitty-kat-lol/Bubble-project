#ifndef PLAYER_CUSTOM_H
#define PLAYER_CUSTOM_H



#include <QPainter>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QThread>
#include <iostream>
#include <QKeyEvent>
#include "Options.h"



class Player_custom: public QObject, public QGraphicsItem
{
	
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
public:
	Player_custom();
	~Player_custom();

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
	int get_vies();
	void init_vie(Options *opt);

	//private:
	
	QGraphicsLineItem *Line_Left_Item;
	QGraphicsLineItem *Line_Right_Item;
	

	QPointF Coordonnee_Player;
	
	qreal deplacement_x;
	int dimensions;

	int vies;
	int score;
	

	bool check_borders(QString side="both");//options: left, right, both(default)
	void move(QString direction);
	void advance(int phase);
	void debug_position_player();
	//void check_death();
	
	

	
public slots :
	void move_right();
	void move_left();
	void set_lives(int nb_vies);
	void add_score(int point);
	void set_1vie(int etat);
	void set_2vies(int etat);
	void set_3vies(int etat);
	


};


#endif