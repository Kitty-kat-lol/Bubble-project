#include "Play.h"




//Play
Play::Play()
{
	QPushButton *Start = new QPushButton("Start");
	QPushButton *Quit = new QPushButton("Quit");
	QLabel *RandD = new QLabel("Production de l'equipe P9!");

	QHBoxLayout *Gametop = new QHBoxLayout;
	QVBoxLayout *Gamelist = new QVBoxLayout;


	QWidget * widget = new QWidget();
	QGridLayout * layout = new QGridLayout(widget);

	Start->setFixedSize(100, 50);
	Quit->setFixedSize(100, 50);

	layout->addWidget(Start, 0, 0, 0, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(Quit, 0, 0, 1, 1, Qt::AlignVCenter | Qt::AlignLeft);
	layout->addWidget(RandD, 1, 0, 1, 1, Qt::AlignVCenter | Qt::AlignLeft);

	RandD->setStyleSheet("QLabel{background: transparent;}");
	Start->setStyleSheet("QPushButton{background: transparent;}");
	Quit->setStyleSheet("QPushButton{background: transparent;}");


	setLayout(layout);

	//connect
	QObject::connect(Start, SIGNAL(clicked()), this, SLOT(Start_play()));
	QObject::connect(Quit, SIGNAL(clicked()), this, SLOT(Quit_play()));
}

Play::Play(Options *option, Scores *scores)
{
	score = scores;
	options = option;

	QPushButton *Start = new QPushButton("Start");
	QPushButton *Quit = new QPushButton("Quit");
	QLabel *RandD = new QLabel("Production de l'�quipe P9!");

	QHBoxLayout *Gametop = new QHBoxLayout;
	QVBoxLayout *Gamelist = new QVBoxLayout;


	QWidget * widget = new QWidget();
	QGridLayout * layout = new QGridLayout(widget);

	Start->setFixedSize(100, 50);
	Quit->setFixedSize(100, 50);

	layout->addWidget(Start, 0, 0, 0, 0, Qt::AlignTop | Qt::AlignLeft);
	layout->addWidget(Quit, 0, 0, 1, 1, Qt::AlignVCenter | Qt::AlignLeft);
	layout->addWidget(RandD, 1, 0, 1, 1, Qt::AlignVCenter | Qt::AlignLeft);

	RandD->setStyleSheet("QLabel{background: transparent;}");
	Start->setStyleSheet("QPushButton{background: transparent;}");
	Quit->setStyleSheet("QPushButton{background: transparent;}");


	setLayout(layout);

	//connect
	QObject::connect(Start, SIGNAL(clicked()), this, SLOT(Start_play()));
	QObject::connect(Quit, SIGNAL(clicked()), this, SLOT(Quit_play()));
}

Play::~Play()
{

}

void Play::Quit_play()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "", "Quit?",QMessageBox::Yes | QMessageBox::No);

	if (reply == QMessageBox::Yes) {
		QApplication::quit();
	}
	else {
	}
}

void Play::Start_play()
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Start", "Ready ?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) {

		test = new Bubble_Trouble(options, score);
		App.setCentralWidget(test);
		//App.showMaximized();
		App.showFullScreen();
	}
	else {
	}
}

Bubble_Trouble::Bubble_Trouble()
{
	//Cr�e la scene de jeu en plein �cran
	this->setWindowState(Qt::WindowFullScreen);
	Frame = new QGraphicsScene(geometry().x(), geometry().y(), 1900, 1070);//1900 1070

	//Cr�e un timer qui a ticker � chaque 20 msecondes et trigger la fonction advance pour les animations
	temps = new QTimer;
	temps->start(15);
	QObject::connect(temps, SIGNAL(timeout()), Frame, SLOT(advance()));

	//tentative de background
/*	QPixmap pim("C:\\Users\casto\\Pictures\\Wallpapers\\raven_bird_flying_smoke_black_white_92907_1920x1080.jpg");
	QGraphicsPixmapItem *back = new QGraphicsPixmapItem(pim);*/

	setStyleSheet("background-image:url(Stadium.png)");
	//Frame->addItem(back);


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
	/*
	Bulle_Custom *Bulle2 = new Bulle_Custom;
	Frame->addItem(Bulle2);
	Bulle2->vitesse_x = -7;
	Bulle2->vitesse_y = -7;
	Bulle2->rayon = 20;
	Bulle2->Line_Top_Item = Line_Top_Item;
	Bulle2->Line_Right_Item = Line_Right_Item;
	Bulle2->Line_Left_Item = Line_Left_Item;
	Bulle2->Line_Bottom_Item = Line_Bottom_Item;*/


	//Ajout des lignes utilis�e pour la collision
	Frame->addItem(Line_Top_Item);
	Frame->addItem(Line_Right_Item);
	Frame->addItem(Line_Left_Item);
	Frame->addItem(Line_Bottom_Item);


	//Set up du plan,
	/*Plan.horizontal_min = -1940;
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

	//Pour les phonemes:
	Carte = new Input_FPGA;
	QTimer *thread_FPGA = new QTimer;
	thread_FPGA->start(20);
	QObject::connect(thread_FPGA, SIGNAL(timeout()), Carte, SLOT(call_read()));
	//QObject::connect(Carte, SIGNAL(B_out()), this->Player, SLOT(move_right()));


	//std::cout << "Max x: " << Plan.horizontal_max << std::endl;
	//std::cout << "Max y: " << Plan.vertical_max << std::endl << std::endl;

	//Bulle->setPos()
	std::cout << "Bulle x: " << Bulle->scenePos().x() << std::endl;
	std::cout << "Bulle y: " << Bulle->scenePos().y() << std::endl;
}

Bubble_Trouble::Bubble_Trouble(Options *options, Scores *score)
{
	//connect option et score
	option = options;
	scores = score;
	//Cr�e la scene de jeu en plein �cran
	this->setWindowState(Qt::WindowFullScreen);
	Frame = new QGraphicsScene(geometry().x(), geometry().y(), 1900, 1070);//1900 1070

	//Cr�e un timer qui a ticker � chaque 20 msecondes et trigger la fonction advance pour les animations
	temps = new QTimer;
	temps->start(15);
	QObject::connect(temps, SIGNAL(timeout()), Frame, SLOT(advance()));
	
	setStyleSheet("background-image:url(Stadium.png)");

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

	//Ajout des lignes utilis�e pour la collision
	Frame->addItem(Line_Top_Item);
	Frame->addItem(Line_Right_Item);
	Frame->addItem(Line_Left_Item);
	Frame->addItem(Line_Bottom_Item);

	//Ajoute la scene dans le view et active le antialiasing (qualit� visuelle)
	setScene(Frame);
	setRenderHints(QPainter::Antialiasing);

	//Test de gamepad
	Xbox = new QGamepad;

	//Pour les phonemes:
	Carte = new Input_FPGA;
	Thread_FPGA = new QTimer;
	Thread_FPGA->start(15);
	events = new QTimer;
	events->start(15);
	
	if (Carte->isok)
	{
		QObject::connect(Thread_FPGA, SIGNAL(timeout()), Carte, SLOT(call_read()));
		QObject::connect(Carte, SIGNAL(O_out()), Player, SLOT(move_right()));
		QObject::connect(Carte, SIGNAL(A_out()), Player, SLOT(move_left()));
		QObject::connect(Carte, SIGNAL(U_out()), this, SLOT(shoot_arrow()));

		//Debug FPGA
		if (options->Debug_FPGA->isChecked())
		{
			Carte->set_debug(true);
		}
	}
	QObject::connect(events, SIGNAL(timeout()), this, SLOT(bulle_event()));
	QObject::connect(events, SIGNAL(timeout()), this, SLOT(Death()));

	Thread_Xbox = new QTimer;
	Thread_Xbox->start(15);
	QObject::connect(Thread_Xbox, SIGNAL(timeout()), this, SLOT(gamepad_control()));

	//Nb de vies
	if (options->une_vie->isChecked())
	{
		Player->vies = 1;
	}
	if (options->deux_vies->isChecked())
	{
		Player->vies = 2;
	}
	if (options->trois_vies->isChecked())
	{
		Player->vies = 3;
	}
	

	//Vitesse du joueur
	this->Player->deplacement_x = (options->Vitesse->sliderPosition());
	
	debug = false;
	if (options->Debug_CMD->isChecked())
	{
		debug = true;
	}
	
	
	//Bulle->setPos()
	if (debug)
	{
		std::cout << "Bulle x: " << Bulle->scenePos().x() << std::endl;
		std::cout << "Bulle y: " << Bulle->scenePos().y() << std::endl;
	}
	
}

Bubble_Trouble::~Bubble_Trouble()
{

}

void Bubble_Trouble::debug_position_bulle()
{
	QPointF coordonne_bulle = Bulle->scenePos();

	if (debug)
	{
		std::cout << "Pos x: " << Bulle->scenePos().rx() << std::endl;
		std::cout << "Pos y: " << Bulle->scenePos().ry() << std::endl << std::endl;
	}
	

}

void Bubble_Trouble::shoot_arrow()
{
	if (Frame->items().contains(Arrow))
	{
		if (debug)
		{
			std::cout << "Arrow deleted..." << std::endl;
		}
		delete Arrow;
	}

	QPointF pos = Player->Coordonnee_Player;
	pos.setX(Player->Coordonnee_Player.rx() + 25);
	pos.setY(900);
	Arrow = new Arrow_Custom(pos);
	this->Frame->addItem(Arrow);
	Bulle->Arrow = Arrow;
	if (Bebelist.size() > 0)
	{
		for (int i = 0; i < Bebelist.size(); i++)
		{
			Bebelist[i]->Arrow = Arrow;
			Bebelist[i]->Player = Player;
		}
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
	int count_escape = 0;
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

	}
	if (event->key() == Qt::Key_Escape)
	{
		if (count_escape % 2 == 0)
		{
			temps->stop();
			QMessageBox::StandardButton pause;
			QString bob = "Quitter ? \n ";
			bob += "Vies : ";
			bob += QString::number(Player->get_vies());
			bob += " \nScore : ";
			bob += QString::number(Player->score);
			pause = QMessageBox::question(this, "Pause", bob, QMessageBox::Yes | QMessageBox::No);
			if (pause == QMessageBox::No) {
				temps->start(15);
			}
			else if (pause == QMessageBox::Yes)
			{
				window()->close();
			}
		}
	}
	


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

void Bubble_Trouble::set_bulle_speed(int pourcent)
{
	this->Bulle->vitesse(pourcent);
	if (debug)
	{
		std::cout << "Pourcent: " << pourcent << std::endl;
	}	
}

void Bubble_Trouble::Death()
{
	

	bool ok;
	QString text;
	if (Player->vies <= 0)
	{
		if (debug)
		{
			std::cout << "Mort!" << std::endl;
		}
		events->stop();
		Thread_FPGA->stop();
		Thread_Xbox->stop();
		temps->stop();
		QMessageBox::StandardButton pause;
		QString bob = "Do you want to save your score?";
		bob += "Vies : ";
		bob += QString::number(Player->get_vies());
		bob += " \nScore : ";
		bob += QString::number(Player->score);
		pause = QMessageBox::question(this, "DEATH", bob, QMessageBox::Yes | QMessageBox::No);
		if (pause == QMessageBox::No)
		{
			window()->close();
		}
		else if (pause == QMessageBox::Yes)
		{
			
			text = QInputDialog::getText(this, "Input", "Votre nom", QLineEdit::Normal, "", &ok);
		}
    if (ok && !text.isEmpty()) {
    stru_scores act;
		act.score = Player->score;
		act.name = text;

			scores->add_scores(act);

			window()->close();
		}
	}
}

void Bubble_Trouble::bulle_event()
{
	if (Bulle->baby == 1)
	{
		if (debug)
		{
			std::cout << Bulle->baby;
		}
		
		Bulle->baby = 0;
		Bebe_Bulle *Bulle2 = new Bebe_Bulle(Bulle->Coordonnee_Bulle.x(), Bulle->Coordonnee_Bulle.y());
		Frame->addItem(Bulle2);
		Bulle2->Line_Top_Item = Line_Top_Item;
		Bulle2->Line_Right_Item = Line_Right_Item;
		Bulle2->Line_Left_Item = Line_Left_Item;
		Bulle2->Line_Bottom_Item = Line_Bottom_Item;
		Bulle2->Player = Player;
		Bulle2->Arrow = Arrow;
		Bulle2->layers = 1;
		Bebelist.append(Bulle2);
	}
}

void Bubble_Trouble::phoneme_control()
{
	if (Carte->isok == 1)
	{
		Carte->read();
		if (Carte->A_detected())
		{
			//Action
		}
		else if (Carte->O_detected())
		{
			//Action
		}
		else if (Carte->I_detected())
		{
			//Action
		}
		else if (Carte->U_detected())
		{
			//Action
		}
		else if (Carte->button_pressed())
		{
			//Test
		}
	}
}
