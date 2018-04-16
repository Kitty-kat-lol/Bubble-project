


#include "CommunicationFPGA.h"
#include "Registres.h"


#include <iostream>
#include <QWidget>
#include <QString>
#include <QTextEdit>
using namespace std;




struct Phoneme
{
	int filtre_0;
	int filtre_1;
	int filtre_2;
	int filtre_3;
	int tolerance;
	int count_detected;
};


class Input_FPGA: public QWidget
{
	Q_OBJECT
public:
	Input_FPGA();
	~Input_FPGA();
	void read();
	void print_CMD();
	int get_value(Phoneme son);
	bool has_items();
	bool A_detected();
	bool U_detected();
	bool I_detected();
	bool O_detected();
	void set_debug(bool activation);
	bool button_pressed();

private:
	
	int filtre_0;
	int filtre_1;
	int filtre_2;
	int filtre_3;
	int Button_State;
	bool debug;
	int min_detect;
	void input_to_signal();
	
	CommunicationFPGA Carte;
	Registres Registres;
protected:
	
	Phoneme U;
	Phoneme A;
	Phoneme I;
	Phoneme O;

	//Ne doit pas être définiT
signals:
	

	void A_out();
	void O_out();
	void I_out();
	void U_out();
	void B_out();
	
	public slots:
	void call_read();
	
};


