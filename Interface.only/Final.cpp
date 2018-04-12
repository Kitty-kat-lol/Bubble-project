#include "interface.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QTabWidget>
#include <QMainWindow>
#include "Options.h"
#include "Scores.h"


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
			
	fond->show();


	return WIND.exec();
}