#include "Registres.h"
#include"CommunicationFPGA.h"
#include "Input_FPGA.h"

#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>

//#include <conio.h>




int main(int argc, char *argv[])
{

	QApplication WIND(argc, argv);
	QMainWindow window;
	Input_FPGA *test = new Input_FPGA;
	log_out *texte = new log_out(test);

	window.setCentralWidget(texte);
	
	
	
	window.show();
	test->set_debug(true);
	/*while (true)
	{
		test->read();
		test->print_CMD();
		

		char breaking = ' ';

		/*if (_kbhit())
		{
			breaking = _getch();
			if (breaking == '#')
			{
				break;
			}
		}*/
		
	//}
	
	return WIND.exec();
}


log_out::log_out()
{
	setReadOnly(true);
	setMaximumHeight(200);
	setMaximumWidth(600);

	
}

log_out::log_out(Input_FPGA * card_to_add)
{
	//setReadOnly(true);
	setMaximumHeight(200);
	setMaximumWidth(600);

	connect(card_to_add, SIGNAL(B_out()), this, SLOT(print_test()));
}

log_out::~log_out()
{

}

void log_out::print_test()
{
	
	this->insertPlainText("Button pressed !");
	
}