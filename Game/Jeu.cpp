#include "Jeu.h"




Bubble_Trouble::Bubble_Trouble() 
{
	//Cr�e la scene de jeu en plein �cran
	this->setWindowState(Qt::WindowFullScreen);
	Frame = new QGraphicsScene(geometry().x(), geometry().y(), 1900, 1070);
	
	//Cr�e un timer qui a ticker � chaque 20 msecondes et trigger la fonction advance pour les animations
	temps = new QTimer;
	temps->start(15);
	connect(temps, SIGNAL(timeout()), Frame, SLOT(advance()));

	//tentative de background
	QPixmap pim("C:\\Users\casto\\Pictures\\Wallpapers\\raven_bird_flying_smoke_black_white_92907_1920x1080.jpg");
	QGraphicsPixmapItem *back=new QGraphicsPixmapItem(pim);
	Frame->addItem(back);
	
	
	
	
	
	
	//Ajout de lignes
	QPen borders(Qt::black);
	
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

	//Ajout de la premi�re bulle
	Bulle = new Bulle_Custom;
	Frame->addItem(Bulle);
	Bulle->Line_Top_Item = Line_Top_Item;
	Bulle->Line_Right_Item = Line_Right_Item;
	Bulle->Line_Left_Item = Line_Left_Item;
	Bulle->Line_Bottom_Item = Line_Bottom_Item;

	//Ajout du player
	Player = new Player_custom;
	Frame->addItem(Player);
	Player->Line_Right_Item = Line_Right_Item;
	Player->Line_Left_Item = Line_Left_Item;
	Bulle->Player = Player;


	//Gestion de la 2e bulle. Tests � mettre en commentaire
	Bulle_Custom *Bulle2 = new Bulle_Custom;
	Frame->addItem(Bulle2);
	Bulle2->vitesse_x = -7;
	Bulle2->vitesse_y = -7;
	Bulle2->rayon = 20;
	Bulle2->Line_Top_Item = Line_Top_Item;
	Bulle2->Line_Right_Item = Line_Right_Item;
	Bulle2->Line_Left_Item = Line_Left_Item;
	Bulle2->Line_Bottom_Item = Line_Bottom_Item;
	

	//Ajout des lignes utilis�e pour la collision
	Frame->addItem(Line_Top_Item);
	Frame->addItem(Line_Right_Item);
	Frame->addItem(Line_Left_Item);
	Frame->addItem(Line_Bottom_Item);
	

	//Set up du plan,
	Plan.horizontal_min = -1940;
	Plan.horizontal_min *= 0.5;
	Plan.horizontal_max = 1940;
	Plan.horizontal_max *= 0.5;

	Plan.vertical_min = 1090;
	Plan.vertical_min *= 0.5;
	Plan.vertical_max = -1090;
	Plan.vertical_max *= 0.5;

	/*Note:
	Le top est n�gatif et on a un plan cart�sien centr� dans la fen�tre pour les positions
	*/

	//Bulle->setPos(Plan.horizontal_min, Plan.vertical_max);
	
	
		
	//Ajoute la scene dans le view et active le antialiasing (qualit� visuelle)
	setScene(Frame);
	setRenderHints(QPainter::Antialiasing);



	//Test de gamepad
	Xbox = new QGamepad;
	

	std::cout << "Max x: " << Plan.horizontal_max << std::endl;
	std::cout << "Max y: " << Plan.vertical_max  << std::endl << std::endl;

	//Bulle->setPos()
	std::cout << "Bulle x: " << Bulle->scenePos().x() << std::endl;
	std::cout << "Bulle y: " << Bulle->scenePos().y() << std::endl;
}


Bubble_Trouble::~Bubble_Trouble()
{
	
}

void Bubble_Trouble::debug_position_bulle()
{
	QPointF coordonne_bulle = Bulle->scenePos();		

	std::cout << "Pos x: " << Bulle->scenePos().rx() << std::endl;
	std::cout << "Pos y: " << Bulle->scenePos().ry() << std::endl << std::endl;
	
}

void Bubble_Trouble::shoot_arrow()
{
	if (Frame->items().contains(Arrow))
	{
		delete Arrow;
	}
	
	QPointF pos = Player->Coordonnee_Player;
	pos.setX(Player->Coordonnee_Player.rx() + 25);
	pos.setY(900);
	Arrow = new Arrow_Custom(pos);
	this->Frame->addItem(Arrow);
	Bulle->Arrow = Arrow;
	
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

void Bubble_Trouble::keyPressEvent(QKeyEvent *event)
{
	int test = (qrand() % 360);
	if (event->key() == Qt::Key_A || Xbox->buttonLeft())
	{
		Player->move("left");
	}
	if (event->key() == Qt::Key_D)
	{
		Player->move("right");
	}
	if (event->key() == Qt::Key_Space)
	{
		shoot_arrow();
		//Player->move("right");
	}

	gamepad_control();
}

void Bubble_Trouble::customEvent(QEvent * input)
{
	gamepad_control();
}



void Bubble_Trouble::gamepad_control()
{
	if (Xbox->buttonLeft() || Xbox->axisLeftX() < 0)
	{
		Player->move("left");
	}
	if (Xbox->buttonRight() || Xbox->axisLeftX() > 0)
	{
		Player->move("right");
	}
	if (Xbox->buttonR2() || Xbox->buttonR1())
	{
		shoot_arrow();
	}
	
}
