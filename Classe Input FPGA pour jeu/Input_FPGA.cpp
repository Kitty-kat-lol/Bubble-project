#include "Input_FPGA.h"



Input_FPGA::Input_FPGA()
{
	//Initialise les valeurs à 0
	for (int i = 0; i <= 14; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			etat_phonemes[i][j] = false;
		}		
	}

	debug = false;

	if (Carte.estOk())
	{
		cout << "Connection avec la carte établie" << endl;
	}
	else if(!Carte.estOk())
	{
		cout << "Probleme de connection avec la carte" << endl;
	}

	filtre_0 = 0;
	filtre_1 = 0;
	filtre_2 = 0;
	filtre_3 = 0;

	min_detect = 10;
	U.filtre_0 = 0;
	U.filtre_1 = 0;
	U.filtre_2 = 0;
	U.filtre_3 = 0;

	A.filtre_0 = 0;
	A.filtre_1 = 0;
	A.filtre_2 = 0;
	A.filtre_3 = 0;

	I.filtre_0 = 0;
	I.filtre_1 = 0;
	I.filtre_2 = 0;
	I.filtre_3 = 0;

	O.filtre_0 = 0;
	O.filtre_1 = 0;
	O.filtre_2 = 0;
	O.filtre_3 = 0;
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

	if (appending_index == 15)
	{
		appending_index = 0;
	}

	//Phoneme: U
	if ((filtre_0 - U.tolerance >= filtre_0 && filtre_0 + U.tolerance <= filtre_0) &&
		(filtre_1 - U.tolerance >= filtre_1 && filtre_1 + U.tolerance <= filtre_1) &&
		(filtre_2 - U.tolerance >= filtre_2 && filtre_2 + U.tolerance <= filtre_2) &&
		(filtre_3 - U.tolerance >= filtre_3 && filtre_3 + U.tolerance <= filtre_3))
	{
		etat_phonemes[appending_index][0] = true;
	}
	if (!(filtre_0 - U.tolerance >= filtre_0 && filtre_0 + U.tolerance <= filtre_0) &&
		(filtre_1 - U.tolerance >= filtre_1 && filtre_1 + U.tolerance <= filtre_1) &&
		(filtre_2 - U.tolerance >= filtre_2 && filtre_2 + U.tolerance <= filtre_2) &&
		(filtre_3 - U.tolerance >= filtre_3 && filtre_3 + U.tolerance <= filtre_3))
	{
		etat_phonemes[appending_index][0] = false;
	}

	//Phoneme: A
	if ((filtre_0 - A.tolerance >= filtre_0 && filtre_0 + A.tolerance <= filtre_0) &&
		(filtre_1 - A.tolerance >= filtre_1 && filtre_1 + A.tolerance <= filtre_1) &&
		(filtre_2 - A.tolerance >= filtre_2 && filtre_2 + A.tolerance <= filtre_2) &&
		(filtre_3 - A.tolerance >= filtre_3 && filtre_3 + A.tolerance <= filtre_3))
	{
		etat_phonemes[appending_index][1] = true;
	}
	if (!(filtre_0 - A.tolerance >= filtre_0 && filtre_0 + A.tolerance <= filtre_0) &&
		(filtre_1 - A.tolerance >= filtre_1 && filtre_1 + A.tolerance <= filtre_1) &&
		(filtre_2 - A.tolerance >= filtre_2 && filtre_2 + A.tolerance <= filtre_2) &&
		(filtre_3 - A.tolerance >= filtre_3 && filtre_3 + A.tolerance <= filtre_3))
	{
		etat_phonemes[appending_index][1] = false;
	}

	//Phoneme: I
	if ((filtre_0 - I.tolerance >= filtre_0 && filtre_0 + I.tolerance <= filtre_0) &&
		(filtre_1 - I.tolerance >= filtre_1 && filtre_1 + I.tolerance <= filtre_1) &&
		(filtre_2 - I.tolerance >= filtre_2 && filtre_2 + I.tolerance <= filtre_2) &&
		(filtre_3 - I.tolerance >= filtre_3 && filtre_3 + I.tolerance <= filtre_3))
	{
		etat_phonemes[appending_index][2] = true;
	}
	if (!(filtre_0 - I.tolerance >= filtre_0 && filtre_0 + I.tolerance <= filtre_0) &&
		(filtre_1 - I.tolerance >= filtre_1 && filtre_1 + I.tolerance <= filtre_1) &&
		(filtre_2 - I.tolerance >= filtre_2 && filtre_2 + I.tolerance <= filtre_2) &&
		(filtre_3 - I.tolerance >= filtre_3 && filtre_3 + I.tolerance <= filtre_3))
	{
		etat_phonemes[appending_index][2] = false;
	}

	//Phoneme: O
	if ((filtre_0 - O.tolerance >= filtre_0 && filtre_0 + O.tolerance <= filtre_0) &&
		(filtre_1 - O.tolerance >= filtre_1 && filtre_1 + O.tolerance <= filtre_1) &&
		(filtre_2 - O.tolerance >= filtre_2 && filtre_2 + O.tolerance <= filtre_2) &&
		(filtre_3 - O.tolerance >= filtre_3 && filtre_3 + O.tolerance <= filtre_3))
	{
		etat_phonemes[appending_index][3] = true;
	}
	if (!(filtre_0 - O.tolerance >= filtre_0 && filtre_0 + O.tolerance <= filtre_0) &&
		(filtre_1 - O.tolerance >= filtre_1 && filtre_1 + O.tolerance <= filtre_1) &&
		(filtre_2 - O.tolerance >= filtre_2 && filtre_2 + O.tolerance <= filtre_2) &&
		(filtre_3 - O.tolerance >= filtre_3 && filtre_3 + O.tolerance <= filtre_3))
	{
		etat_phonemes[appending_index][3] = false;
	}

	
	
	appending_index++;
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
			else if (Button_State == 3)
			{
				//return;
			}
		}
	}
}

bool Input_FPGA::get_value(int index)
{
	return etat_phonemes[appending_index][index];
}

bool Input_FPGA::has_items()
{
	for (int i = 0; i <= 14; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (etat_phonemes[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

bool Input_FPGA::A_detected()
{
	int detection_counter = 0;
	for (int i = 0; i <= 14; i++)
	{
		if (etat_phonemes[i][1])
		{
			detection_counter++;
		}
	}
	if (detection_counter >= min_detect)
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
	int detection_counter = 0;
	for (int i = 0; i <= 14; i++)
	{
		if (etat_phonemes[i][0])
		{
			detection_counter++;
		}
	}
	if (detection_counter >= min_detect)
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
	int detection_counter = 0;
	for (int i = 0; i <= 14; i++)
	{
		if (etat_phonemes[i][2])
		{
			detection_counter++;
		}
	}
	if (detection_counter >= min_detect)
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
	int detection_counter = 0;
	for (int i = 0; i <= 14; i++)
	{
		if (etat_phonemes[i][3])
		{
			detection_counter++;
		}
	}
	if (detection_counter >= min_detect)
	{
		return true;
	}
	else
	{
		return false;
	}
}
