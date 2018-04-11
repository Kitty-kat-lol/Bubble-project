#pragma once


#include "CommunicationFPGA.h"
#include "Registres.h"
#include <conio.h>

#include <iostream>

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


class Input_FPGA
{
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

private:
	
	int filtre_0;
	int filtre_1;
	int filtre_2;
	int filtre_3;
	int Button_State;
	bool debug;
	int min_detect;
protected:
	
	Phoneme U;
	Phoneme A;
	Phoneme I;
	Phoneme O;

	
	
	CommunicationFPGA Carte;
	Registres Registres;
};

