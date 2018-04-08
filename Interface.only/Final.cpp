#include "interface.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QTabWidget>
#include <QMainWindow>


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
	QVBoxLayout *list = new QVBoxLayout;
			QHBoxLayout *top = new QHBoxLayout;
				QPushButton *bouton1 = new QPushButton("Reinitialiser les Scores");
				QPushButton *bouton2 = new QPushButton("Sauvgarder les Scores");
				QPushButton *bouton3 = new QPushButton("Actualiser les Scores");

				top->addWidget(bouton1);
				top->addWidget(bouton2);
				top->addWidget(bouton3);

			QLabel *title = new QLabel("Top Scores");

			QGridLayout *box = new QGridLayout;
				QLabel *first = new QLabel("First");
				QLabel *second = new QLabel("Second");
				QLabel *third = new QLabel("Third");
				QLabel *fourth = new QLabel("Fourth");
				QLabel *fifth = new QLabel("Fift");

				QLabel *first_n = new QLabel("BOB");
				QLabel *second_n = new QLabel("JAQUE123");
				QLabel *third_n = new QLabel("Claudette");
				QLabel *fourth_n = new QLabel("PAPA");
				QLabel *fifth_n = new QLabel("GERARD-LOL-0P");

				QLabel *first_s = new QLabel("500 000");
				QLabel *second_s = new QLabel("235 000");
				QLabel *third_s = new QLabel("243 000");
				QLabel *fourth_s = new QLabel("100 100");
				QLabel *fifth_s = new QLabel("500");

				box->addWidget(title, 0, 0);

				box->addWidget(first, 1, 1);
				box->addWidget(second, 2, 1);
				box->addWidget(third, 3, 1);
				box->addWidget(fourth, 4, 1);
				box->addWidget(fifth, 5, 1);

				box->addWidget(first_n, 1, 2);
				box->addWidget(second_n, 2, 2);
				box->addWidget(third_n, 3, 2);
				box->addWidget(fourth_n, 4, 2);
				box->addWidget(fifth_n, 5, 2);

				box->addWidget(first_s, 1, 3);
				box->addWidget(second_s, 2, 3);
				box->addWidget(third_s, 3, 3);
				box->addWidget(fourth_s, 4, 3);
				box->addWidget(fifth_s, 5, 3);

			list->addLayout(top);
			list->addLayout(box);

			scores->setLayout(list);

	//autres tabs
			
			
	fond->show();


	return WIND.exec();
}