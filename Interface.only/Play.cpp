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
	/*if(reply == QMessageBox::Yes) {
		QApplication::quit();
	}
	else {
	}*/
}
