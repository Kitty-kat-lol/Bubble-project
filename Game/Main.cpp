//#include "Options.h"
#include "Jeu.h"

#include <QApplication>
#include <QMAINWINDOW>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>

#include <iostream>


int main(int argc, char *argv[])
{

	QApplication WIND(argc, argv);
		
	//Décommenter la partie à débogger
	
	//Menu d'options
	QMainWindow App;
	//Options *menu_option = new Options;
	
	//App.setCentralWidget(menu_option);
	
		
	
	//Avancement du jeu
	Bubble_Trouble *test = new Bubble_Trouble;
	App.setCentralWidget(test);
	
	
	
	//test->Bulle->moveBy(200,-200);
	
	
	
	//App.show();
	App.showFullScreen();
	
	
	
	return WIND.exec();
}