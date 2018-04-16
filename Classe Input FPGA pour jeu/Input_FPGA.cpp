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
	min_detect = 5;

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
	O.tolerance = 35;
	

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
<<<<<<< HEAD:Classe Input FPGA pour jeu/Input FPGA/Input_FPGA.cpp
	if (filtre_0 <=25 && 
		filtre_1 >= 50 && filtre_1 <= 140 
		&& filtre_2<=60)
	{
		if (U.count_detected <= 16)
		{
			U.count_detected++;
		}
=======
	if (filtre_0 <= 25 &&
		filtre_1 >= 50 && filtre_1 <=14 &&
		filtre_3 <= 60)
	{
		if (U.count_detected <= min_detect)
		{
			U.count_detected++;
		}
		else
		{
			U.count_detected = 0;
		}
>>>>>>> 3f2e6d530a4290a7c93f39db56f9d5f1c3563a2d:Classe Input FPGA pour jeu/Input_FPGA.cpp
		
		cout << "U detected!" << endl;
	}
	else
	{
		if (U.count_detected != 0)
		{
			U.count_detected--;
			cout << "U lost..." << endl;
		}
	}

	//Phoneme: A
<<<<<<< HEAD:Classe Input FPGA pour jeu/Input FPGA/Input_FPGA.cpp
	if (filtre_0 >=10 &&
		filtre_2 >=60 &&
		filtre_3 >= 150)
	{
		if (A.count_detected <= 16)
		{
			A.count_detected++;
		}
		
=======
	if (filtre_0 >= 10 &&
		filtre_2 >= 60 &&
		filtre_3 >= 150)
	{
		if (A.count_detected <= min_detect)
		{
			A.count_detected++;
		}
		else
		{
			A.count_detected = 0;
		}

>>>>>>> 3f2e6d530a4290a7c93f39db56f9d5f1c3563a2d:Classe Input FPGA pour jeu/Input_FPGA.cpp
		cout << "A detected!" << endl;
	}
	else
	{
		if (A.count_detected != 0)
		{
			A.count_detected--;
			cout << "A lost..." << endl;
		}		
	}

	//Phoneme: I
	if (filtre_0 >= 4 && filtre_0 <= 60 &&
<<<<<<< HEAD:Classe Input FPGA pour jeu/Input FPGA/Input_FPGA.cpp
		filtre_1 >= 4 && filtre_1 <= 60 && 
		/*filtre_2 >= 2 && filtre_2 <= 60 &&*/ 
=======
		filtre_1 >= 4 && filtre_1 <= 60 &&
>>>>>>> 3f2e6d530a4290a7c93f39db56f9d5f1c3563a2d:Classe Input FPGA pour jeu/Input_FPGA.cpp
		filtre_3 >= 4 && filtre_3 <= 60)
	{
		if (I.count_detected <= min_detect)
		{
			I.count_detected++;
		}
		else
		{
			I.count_detected = 0;
		}

		cout << "I detected!" << endl;
	}
	else 
	{
		if (I.count_detected != 0)
		{
			I.count_detected--;
			cout << "I lost..." << endl;
		}		
	}

	//Phoneme: O
<<<<<<< HEAD:Classe Input FPGA pour jeu/Input FPGA/Input_FPGA.cpp
	if (filtre_0<=50 && filtre_1 <= 50 && filtre_2 <= 60 &&  filtre_3 >= 100)
=======
	if (filtre_0 <= 50 &&
		filtre_1 <= 50 &&
		filtre_2 <= 60 && 
		filtre_3 >= 100)
>>>>>>> 3f2e6d530a4290a7c93f39db56f9d5f1c3563a2d:Classe Input FPGA pour jeu/Input_FPGA.cpp
	{
		if (O.count_detected <= min_detect)
		{
			O.count_detected++;
		}
		else
		{
			O.count_detected = 0;
		}

		cout << "O detected!" << endl;
	}
	else 
	{
		if (O.count_detected != 0)
		{
			O.count_detected--;
			//cout << "O lost..." << endl;
		}		
	}

	
	
	
	
	Sleep(66);
	//read();
	
	input_to_signal();
	
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

void Input_FPGA::input_to_signal()
{
	
	if (O_detected())
	{
		emit this->O_out();
	}
	else if (A_detected())
	{
		emit this->A_out();
	}
	else if (U_detected())
	{
		emit this->U_out();
	}
	else if (I_detected())
	{
		emit this->O_out();
	}
	else if (this->Button_State != 0)
	{
		emit this->B_out();
	}
	
}


