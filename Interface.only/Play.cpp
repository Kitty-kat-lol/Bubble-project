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

	/*QPixmap bkgnd;
	QSize Dimension(500, 200);
	bkgnd.load("bubbletrouble.png");
	setBrush(QPalette::Background, bkgnd);
	/*Start->setStyleSheet("font: bold;background-image: Red;font-size: 36px;height: 48px;width: 120px;");
	Quit->setStyleSheet("font: bold;background-image: Blue;font-size: 36px;height: 48px;width: 120px;");
	setStyleSheet("background-image:url(bubbletrouble.png)");*/

	
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
	/*if(reply == QMessageBox::Yes) {
		QApplication::quit();
	}
	else {
	}*/
}
