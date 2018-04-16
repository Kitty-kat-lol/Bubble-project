#include "Jeu.h"




Bubble_Trouble::Bubble_Trouble() 
{
	int rayon_bulle = 70;
	this->setWindowState(Qt::WindowFullScreen);
	Frame = new QGraphicsScene(geometry().x(), geometry().y(), 1900, 1070);
	temps = new QTimer;
	temps->start(25);
	connect(temps, SIGNAL(timeout()), Frame, SLOT(advance()));
	

	Bulle = new Bulle_Custom;
	Bulle_Custom *Bulle2 = new Bulle_Custom;
	Frame->addItem(Bulle);
	Frame->addItem(Bulle2);
	Bulle2->setActive(false);
	
	//Ajout de lignes
	QPen borders(Qt::black);
	//borders.setWidth(10);
	

	Line_Top.setPoints(Frame->sceneRect().topLeft(), Frame->sceneRect().topRight());
	Line_Left.setPoints(Frame->sceneRect().topLeft(), Frame->sceneRect().bottomLeft());
	Line_Right.setPoints(Frame->sceneRect().topRight(), Frame->sceneRect().bottomRight());
	Line_Bottom.setPoints(Frame->sceneRect().bottomLeft(), Frame->sceneRect().bottomRight());

	Line_Top_Item = new QGraphicsLineItem;
	Line_Right_Item = new QGraphicsLineItem;
	Line_Left_Item = new QGraphicsLineItem;
	Line_Bottom_Item = new QGraphicsLineItem;

	Line_Top_Item->setLine(Line_Top);
	Line_Right_Item->setLine(Line_Right);
	Line_Left_Item->setLine(Line_Left);
	Line_Bottom_Item->setLine(Line_Bottom);

	Bulle->Line_Top_Item = Line_Top_Item;
	Bulle->Line_Right_Item = Line_Right_Item;
	Bulle->Line_Left_Item = Line_Left_Item;
	Bulle->Line_Bottom_Item = Line_Bottom_Item;

	Bulle2->Line_Top_Item = Line_Top_Item;
	Bulle2->Line_Right_Item = Line_Right_Item;
	Bulle2->Line_Left_Item = Line_Left_Item;
	Bulle2->Line_Bottom_Item = Line_Bottom_Item;

	Bulle->vitesse_x = 3;
	Bulle->vitesse_x = -3;


	Frame->addItem(Line_Top_Item);
	Frame->addItem(Line_Right_Item);
	Frame->addItem(Line_Left_Item);
	Frame->addItem(Line_Bottom_Item);
	

	//Set up du plan
	Plan.horizontal_min = -1940;
	Plan.horizontal_min *= 0.5;
	Plan.horizontal_max = 1940;
	Plan.horizontal_max *= 0.5;

	Plan.vertical_min = 1090;
	Plan.vertical_min *= 0.5;
	Plan.vertical_max = -1090;
	Plan.vertical_max *= 0.5;

	/*Note:
	Le top est négatif et on a un plan cartésien centré dans la fenêtre pour les positions
	*/

	//Bulle->setPos(Plan.horizontal_min, Plan.vertical_max);
	
	
		
	
	setScene(Frame);
	setRenderHints(QPainter::Antialiasing);

	std::cout << "Max x: " << Plan.horizontal_max << std::endl;
	std::cout << "Max y: " << Plan.vertical_max  << std::endl << std::endl;

	//Bulle->setPos()
	std::cout << "Bulle x: " << Bulle->scenePos().x() << std::endl;
	std::cout << "Bulle y: " << Bulle->scenePos().y() << std::endl;
	

}


Bubble_Trouble::~Bubble_Trouble()
{
	
}

void Bubble_Trouble::move_bubble()
{
	

	qreal mouvement_x = 5;
	qreal mouvement_y = 5;
	QPointF coordonne_bulle = Bulle->scenePos();

	
	
	
	
	for(int i=0; i < 200; i++)
	{
		
		/*if (Bulle->pos().x() >= Plan.horizontal_max || Bulle->pos().x() <= Plan.horizontal_min)
		{
			mouvement_x = -mouvement_x;
		}
		if (Bulle->pos().y() >= Plan.vertical_min || Bulle->pos().y() <= Plan.vertical_max) 
		{
			mouvement_y = -mouvement_y;
		}*/
		
		

		std::cout << "Pos x: " << Bulle->scenePos().rx() << std::endl;
		std::cout << "Pos y: " << Bulle->scenePos().ry() << std::endl << std::endl;
		//std::sleep
	}

	

}

QGraphicsScene* Bubble_Trouble::get_Frame()
{
	return Frame;
}

Bulle_Custom* Bubble_Trouble::get_Bulle()
{
	return Bulle;
}

QTimer* Bubble_Trouble::get_temps()
{
	return temps;
}

QGraphicsItemAnimation* Bubble_Trouble::get_Trajectoire_Bulle()
{
	return Trajectoire_Bulle;
}

void Bubble_Trouble::collision_bulle()
{
	if (Frame->collidingItems(Bulle).contains(Line_Bottom_Item) || Frame->collidingItems(Bulle).contains(Line_Top_Item))
	{
		Bulle->vitesse_y *= -1;
	}
	else if (Frame->collidingItems(Bulle).contains(Line_Left_Item) || Frame->collidingItems(Bulle).contains(Line_Right_Item))
	{
		Bulle->vitesse_x *= -1;
	}
}
