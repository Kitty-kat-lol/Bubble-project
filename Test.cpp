#include <iostream>

#include "Arrow.h"
#include "Player.h"
#include "Coord.h"
#include "Frame.h"

using namespace std;

int main()
{
	int status = 0;//Utilisé pour contrôler quelle fonction d'affichage utilisée

	Frame Frame1;//Création du frame du jeu
	//Début des tests
	cout << "Console test" << endl;
	//Entrez 1 pour débuter chaîne de test
	cout << "Resize window..." << endl << "If ready enter 1";

	while (1)
	{
		cin >> status;//Demande la valeur du test
		//Test de la fenêtre blanche
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