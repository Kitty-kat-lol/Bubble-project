#include "Input_FPGA.h"



Input_FPGA::Input_FPGA()
{
	

	debug = false;

	if (Carte.estOk())
	{
		cout << "Connection avec la carte établie" << endl;
	}
	else if(!Carte.estOk())
	{
		cout << "Probleme de connection avec la carte" << endl;
	}
	//État des filtres
	filtre_0 = 0;
	filtre_1 = 0;
	filtre_2 = 0;
	filtre_3 = 0;

	//Nombre minimum de détection pour qu'un phonemes soit renvoyé comme vrai
	min_detect = 10;

	//Filtres du phonemes U
	U.filtre_0 = 25;
	U.filtre_1 = 110;
	U.filtre_2 = 40;
	U.filtre_3 = 50;
	U.count_detected = 0;
	U.tolerance = 40;
	

	//Filtres du phonemes A
	A.filtre_0 = 20;
	A.filtre_1 = 30;
	A.filtre_2 = 130;
	A.filtre_3 = 160;
	A.count_detected = 0;
	A.tolerance = 20;
	

	//Filtres du phonemes I
	I.filtre_0 = 45;
	I.filtre_1 = 20;
	I.filtre_2 = 0;
	I.filtre_3 = 5;
	I.count_detected = 0;
	I.tolerance = 15;
	

	//Filtres du phonemes O
	O.filtre_0 = 25;
	O.filtre_1 = 35;
	O.filtre_2 = 50;
	O.filtre_3 = 130;
	O.count_detected = 0;
	O.tolerance = 0;
	

}


Input_FPGA::~Input_FPGA()
{
}

void Input_FPGA::read()
{

	Carte.lireRegistre(Registres.nreg_lect_can0, filtre_0);
	Carte.lireRegistre(Registres.nreg_lect_can1, filtre_1);
	Carte.lireRegistre(Registres.nreg_lect_can2, filtre_2);
	Carte.lireRegistre(Registres.nreg_lect_can3, filtre_3);

	

	//Phoneme: U
	if ((filtre_0 - U.tolerance >= U.filtre_0 && filtre_0 + U.tolerance <= U.filtre_0) &&
		(filtre_1 - U.tolerance >= filtre_1 && filtre_1 + U.tolerance <= filtre_1) &&
		(filtre_2 - U.tolerance >= filtre_2 && filtre_2 + U.tolerance <= filtre_2) &&
		(filtre_3 - U.tolerance >= filtre_3 && filtre_3 + U.tolerance <= filtre_3) )
	{
		U.count_detected++;
		cout << "U detected!" << endl;
	}
	if (!(filtre_0 - U.tolerance >= U.filtre_0 && filtre_0 + U.tolerance <= U.filtre_0) &&
		(filtre_1 - U.tolerance >= filtre_1 && filtre_1 + U.tolerance <= filtre_1) &&
		(filtre_2 - U.tolerance >= filtre_2 && filtre_2 + U.tolerance <= filtre_2) &&
		(filtre_3 - U.tolerance >= filtre_3 && filtre_3 + U.tolerance <= filtre_3))
	{
		U.count_detected--;
		cout << "U lost..." << endl;
	}

	//Phoneme: A
	if ((filtre_0 - A.tolerance >= A.filtre_0 && filtre_0 + A.tolerance <= A.filtre_0) &&
		(filtre_1 - A.tolerance >= A.filtre_1 && filtre_1 + A.tolerance <= A.filtre_1) &&
		(filtre_2 - A.tolerance >= A.filtre_2 && filtre_2 + A.tolerance <= A.filtre_2) &&
		(filtre_3 - A.tolerance >= A.filtre_3 && filtre_3 + A.tolerance <= A.filtre_3))
	{
		A.count_detected++;
		cout << "A detected!" << endl;
	}
	if (!(filtre_0 - A.tolerance >= A.filtre_0 && filtre_0 + A.tolerance <= A.filtre_0) &&
		(filtre_1 - A.tolerance >= A.filtre_1 && filtre_1 + A.tolerance <= A.filtre_1) &&
		(filtre_2 - A.tolerance >= A.filtre_2 && filtre_2 + A.tolerance <= A.filtre_2) &&
		(filtre_3 - A.tolerance >= A.filtre_3 && filtre_3 + A.tolerance <= A.filtre_3))
	{
		A.count_detected--;
		cout << "A lost..." << endl;
	}

	//Phoneme: I
	if ((filtre_0 - I.tolerance >= I.filtre_0 && filtre_0 + I.tolerance <= I.filtre_0) &&
		(filtre_1 - I.tolerance >= I.filtre_1 && filtre_1 + I.tolerance <= I.filtre_1) &&
		(filtre_2 - I.tolerance >= I.filtre_2 && filtre_2 + I.tolerance <= I.filtre_2) &&
		(filtre_3 - I.tolerance >= I.filtre_3 && filtre_3 + I.tolerance <= I.filtre_3))
	{
		I.count_detected++;
		cout << "I detected!" << endl;
	}
	if (!(filtre_0 - I.tolerance >= I.filtre_0 && filtre_0 + I.tolerance <= I.filtre_0) &&
		(filtre_1 - I.tolerance >= I.filtre_1 && filtre_1 + I.tolerance <= I.filtre_1) &&
		(filtre_2 - I.tolerance >= I.filtre_2 && filtre_2 + I.tolerance <= I.filtre_2) &&
		(filtre_3 - I.tolerance >= I.filtre_3 && filtre_3 + I.tolerance <= I.filtre_3))
	{
		I.count_detected--;
		cout << "I lost..." << endl;
	}

	//Phoneme: O
	if ((filtre_0 - O.tolerance >= O.filtre_0 && filtre_0 + O.tolerance <= O.filtre_0) &&
		(filtre_1 - O.tolerance >= O.filtre_1 && filtre_1 + O.tolerance <= O.filtre_1) &&
		(filtre_2 - O.tolerance >= O.filtre_2 && filtre_2 + O.tolerance <= O.filtre_2) &&
		(filtre_3 - O.tolerance >= O.filtre_3 && filtre_3 + O.tolerance <= O.filtre_3))
	{
		O.count_detected++;
		cout << "O detected!" << endl;
	}
	if (!(filtre_0 - O.tolerance >= O.filtre_0 && filtre_0 + O.tolerance <= O.filtre_0) &&
		(filtre_1 - O.tolerance >= O.filtre_1 && filtre_1 + O.tolerance <= O.filtre_1) &&
		(filtre_2 - O.tolerance >= O.filtre_2 && filtre_2 + O.tolerance <= O.filtre_2) &&
		(filtre_3 - O.tolerance >= O.filtre_3 && filtre_3 + O.tolerance <= O.filtre_3))
	{
		O.count_detected--;
		cout << "O lost..." << endl;
	}

	
	
	
	
	Sleep(66);
	//read();
	
	
	
}

void Input_FPGA::print_CMD()
{
	
	if (debug)
	{
		Carte.lireRegistre(Registres.nreg_lect_stat_btn, Button_State);
		//cout << "Bouton: " << Button_State << endl;
		if (Button_State)
		{
			if (Button_State == 1)
			{
				cout << "Filtre 0: " << filtre_0 << endl;
			}
			else if (Button_State == 2)
			{
				cout << "Filtre 1: " << filtre_1 << endl;
			}
			else if (Button_State == 4)
			{
				cout << "Filtre 2: " << filtre_2 << endl;
			}
			else if (Button_State == 8)
			{
				cout << "Filtre 3: " << filtre_3 << endl;
			}
			else  if (Button_State == 9)
			{
				cout << "Filtre 0: " << filtre_0 << endl;
				cout << "Filtre 1: " << filtre_1 << endl;
				cout << "Filtre 2: " << filtre_2 << endl;
				cout << "Filtre 3: " << filtre_3 << endl;
			}
			else  if (Button_State == 6)
			{
				cout << "Détections phoneme A: " << get_value(A) << endl;
				cout << "Détections phoneme O: " << get_value(O) << endl;
				cout << "Détections phoneme I: " << get_value(I) << endl;
				cout << "Détections phoneme U: " << get_value(U) << endl;
			}
			else if (Button_State == 3)
			{
				//return;
			}
			Sleep(100);
		}
	}
}

int Input_FPGA::get_value(Phoneme son)
{
	return son.count_detected;
}

bool Input_FPGA::has_items()
{
	if (A.count_detected || U.count_detected || I.count_detected || O.count_detected)
	{
		return true;
	}
	return false;
}

bool Input_FPGA::A_detected()
{
	
	if (A.count_detected >= min_detect)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_FPGA::U_detected()
{
	
	if (U.count_detected >= min_detect)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_FPGA::I_detected()
{
	
	if (I.count_detected >= min_detect)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Input_FPGA::O_detected()
{
	
	if (O.count_detected >= min_detect)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Input_FPGA::set_debug(bool activation)
{
	debug = activation;
}
