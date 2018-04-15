#include "Play.h"




//Play
Play::Play()
{
	QPushButton *Start = new QPushButton("Start");
	QPushButton *Quit = new QPushButton("Quit");
	QLabel *RandD = new QLabel("Production de l'équipe P9!");

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
	reply = QMessageBox::question(this, "Start", "Prêt ?", QMessageBox::Yes | QMessageBox::No);
	if(reply == QMessageBox::Yes) {

		Bubble_Trouble *test = new Bubble_Trouble;
		/*// Test ajout de boite de texte pour voir les trucs
		QWidget *contain = new QWidget;
		QVBoxLayout *vert = new QVBoxLayout;
		vert->addWidget(test);

		QHBoxLayout *hori = new QHBoxLayout;
		QWidget *hori_contain = new QWidget;

		//QLabel *live = new QLabel("Vies : " );
		//QLabel *score = new QLabel("Score : " );
		//QLabel *comment = new QLabel("");
		
		Out_text *live = new Out_text("Vies : ");
		Out_text *score = new Out_text("Score : ");
		Out_text *comment = new Out_text("");

		hori->addWidget(live);
		hori->addWidget(comment);
		hori->addWidget(score);
		hori_contain->setLayout(hori);
		vert->addWidget(hori_contain);

		contain->setLayout(vert);
		App.setCentralWidget(contain);*/

		App.setCentralWidget(test);
		//App.showMaximized();
		App.showFullScreen();
	}
	else {
	}
}







Bubble_Trouble::Bubble_Trouble()
{
	//Crée la scene de jeu en plein écran
	this->setWindowState(Qt::WindowFullScreen);
	Frame = new QGraphicsScene(geometry().x(), geometry().y(), 1900, 1070);//1900 1070

	//Crée un timer qui a ticker à chaque 20 msecondes et trigger la fonction advance pour les animations
	temps = new QTimer;
	temps->start(15);
	connect(temps, SIGNAL(timeout()), Frame, SLOT(advance()));

	//tentative de background
/*	QPixmap pim("C:\\Users\casto\\Pictures\\Wallpapers\\raven_bird_flying_smoke_black_white_92907_1920x1080.jpg");
	QGraphicsPixmapItem *back = new QGraphicsPixmapItem(pim);*/
	
	setStyleSheet("background-image:url(plain.png)");
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

	//Ajout de la première bulle
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


	//Gestion de la 2e bulle. Tests à mettre en commentaire
	Bulle_Custom *Bulle2 = new Bulle_Custom;
	Frame->addItem(Bulle2);
	Bulle2->vitesse_x = -7;
	Bulle2->vitesse_y = -7;
	Bulle2->rayon = 20;
	Bulle2->Line_Top_Item = Line_Top_Item;
	Bulle2->Line_Right_Item = Line_Right_Item;
	Bulle2->Line_Left_Item = Line_Left_Item;
	Bulle2->Line_Bottom_Item = Line_Bottom_Item;


	//Ajout des lignes utilisée pour la collision
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
	Le top est négatif et on a un plan cartésien centré dans la fenêtre pour les positions
	*/

	//Bulle->setPos(Plan.horizontal_min, Plan.vertical_max);



	//Ajoute la scene dans le view et active le antialiasing (qualité visuelle)
	setScene(Frame);
	setRenderHints(QPainter::Antialiasing);



	//Test de gamepad
	Xbox = new QGamepad;


	std::cout << "Max x: " << Plan.horizontal_max << std::endl;
	std::cout << "Max y: " << Plan.vertical_max << std::endl << std::endl;

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
			pause = QMessageBox::question(this, "Pause", "Quitter ?", QMessageBox::Yes | QMessageBox::No);
			if (pause == QMessageBox::No) {
				temps->start(15);
			}
			else if (pause == QMessageBox::Yes)
			{
				window()->close();
			}
		}
		
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

void Bubble_Trouble::death()
{
	if (Player->vies == 0)
	{
		//Gérer la fin du jeu
	}
}

  // test afficher vies et autres infos
Out_text::Out_text(QString text)
{
	setReadOnly(true);
	setMaximumHeight(15);
	append(text);
}

Out_text::~Out_text()
{

}

void Out_text::Print_Vies(int vies)
{
	QString info_vie = QString::number(vies);
	setPlainText(info_vie);
}

void Out_text::Print_score(int score)
{
	QString info_score = QString::number(score);
	setPlainText(info_score);
}

void Out_text::Print_buff(QString buff)
{
	setPlainText(buff);
}

