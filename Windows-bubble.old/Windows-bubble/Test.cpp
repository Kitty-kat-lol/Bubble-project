#include <iostream>

#include "Arrow.h"
#include "Player.h"
#include "Coordonne.h"
#include "Frame.h"
#include "Bulle.h"
#include <unistd.h>

using namespace std;

int main()
{
	int status = 0;//Utilis� pour contr�ler quelle fonction d'affichage utilis�e

	Frame Frame1;//Cr�ation du frame du jeu
	//D�but des tests
	cout << "Console test" << endl;
	//Entrez 1 pour d�buter cha�ne de test
	cout << "Resize window..." << endl << "If ready enter 1";

	while (1)
	{
		cin >> status;//Demande la valeur du test
		//Test de la fen�tre blanche
		/*if(status == 1)
		{
			Frame1.print_test_blank();
		}

		if (status == 2)
		{
			Frame1.print_test_dot();
		}

		if (status == 3)
		{
			Frame1.print_test_table();
		}*/

		if(status==4)
		{
			Frame1.Player.move('l');
			Frame1.print_test_player();
		}

		if (status == 6)
		{
			Frame1.Player.move('r');
			Frame1.print_test_player();
		}

		if (status == 5)
		{
			Frame1.print_test_player();
		}
		//Permet de quitter le programme
		if (status == 9)
		{
			return 0;
		}
		status = 0;
	}
}
