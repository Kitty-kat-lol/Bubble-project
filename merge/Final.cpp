#include "interface.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QTabWidget>
#include <QMainWindow>
#include <Qmovie>
#include "Options.h"
#include "Scores.h"
#include "Play.h"


int main(int argc, char *argv[])
{
	
	QApplication WIND(argc, argv);

	//creation de la fenetre et des tabs
	QMainWindow *fond = new QMainWindow;
	QWidget *central = new QWidget(fond);
	QVBoxLayout *tab_lay = new QVBoxLayout(central);
	QTabWidget *tabs = new QTabWidget;
	tab_lay->addWidget(tabs);
	
	tabs->addTab(new QWidget(), "Play");
	tabs->addTab(new QWidget(), "Scores");
	tabs->addTab(new QWidget(), "Options");

	QWidget *play = tabs->widget(0);
	QWidget *scores = tabs->widget(1);
	QWidget *options = tabs->widget(2);

	fond->setCentralWidget(central);
	//tab des scores
	
		QVBoxLayout *scores_layout = new QVBoxLayout;
		Scores *scores_wid = new Scores;
		scores_layout->addWidget(scores_wid);

		scores->setLayout(scores_layout);
	
	//autres tabs
	
		QVBoxLayout *option_layout = new QVBoxLayout;
		Options *option_wid = new Options;
		option_layout->addWidget(option_wid);

		options->setLayout(option_layout);
	
	//tab de jeu
	
		QVBoxLayout *play_layout = new QVBoxLayout;
		Play *play_wid = new Play;
		//Q_OBJECT::connect(option_wid->une_vie, SIGNAL(toggled(bool)), play_wid->test->Player, SLOT(set_1vie(bool)));
		//play_wid->test->Player->init_vie(option_wid);

		play_layout->addWidget(play_wid);
		/*QMovie *movie = new QMovie();
		movie->setFileName("giphy.gif");
		movie->start();
		QLabel *label = new QLabel();

		label->setMovie(movie);
		play_layout->addWidget(label);*/
		play->setStyleSheet("background-image:url(plain.png);font: bold; color: blue;font-size: 36px;height: 48px;width: 120px;");

		play->setLayout(play_layout);
	
	
	
	fond->show();


	return WIND.exec();
}