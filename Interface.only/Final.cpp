#include "interface.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QTabWidget>


int main(int argc, char *argv[])
{
	
	QApplication WIND(argc, argv);

	QWidget fond;// = new QWidget;

	//QWidget *central = new QWidget(full);
	//QTabWidget *tabs = new QTabWidget(central);
	
	//QWidget *fond = new QWidget;
	//tabs->addTab(fond, "Play");
	//tabs->addTab(new QWidget(), "Scores");
	
		QVBoxLayout *list = new QVBoxLayout;
			QHBoxLayout *top = new QHBoxLayout;
				QPushButton *bouton1 = new QPushButton("Le boutton test", &fond);
				QPushButton *bouton2 = new QPushButton("Le bon boutton", &fond);
				QPushButton *bouton3 = new QPushButton("Le bouton test", &fond);

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

			fond.setLayout(list);
			
	fond.show();


	return WIND.exec();
}