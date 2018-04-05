
#include <iostream>

#include "Arrow.h"
#include "Player.h"
#include "Coordonne.h"
#include "Frame.h"
#include "Bulle.h"
#include <thread>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include "CommunicationFPGA.h"
#include "canb2usbconsolehlp.h"
#include "Registres.h"
#include <wincon.h>

void debugFPGA();
void play_game();

using namespace std;

//Varaibales
CommunicationFPGA carte;
Registres registres;

//Variables de controles
char clav = '0';
int lecture_bouton = 0;
int switch_state = 0;



int main()
{
	//Met la console en fullscreen
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	//Rend le cursor invisible
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = false;

	

	//Vérification de la communication FPGA
	if (!carte.estOk())
	{
		//cout << carte.estOk() << endl;
		cout << "No FPGA detected, make sure it is concted and loaded with the appropriate file (can_b2_cclk in PROM) and switch jumper to ROM" << endl;
	}
	if (carte.estOk())
	{
		//cout << carte.estOk() << endl;
		cout << "FPGA detected!, LD0 should be on..." << endl;
		carte.ecrireRegistre(registres.nreg_ecri_led, 1);
		Sleep(10);
	}
	
	
	system("Pause");//Fait une pause avant les options de sélection	
	


	//Choisi le mode à débogger: FPGA ou JEU
	cout << "To test game, enter 1" << endl;
	cout << "To test FPGA, enter 2" << endl;
	char input;
	input = _getch();
	switch (input){
	case '1':
		play_game();
		break;
	case '2':
		debugFPGA();
		break;
	default:
		cout << "Bad input, try again";
	};
	
	return 0;
}


void debugFPGA()
	{
	bool boucle = true;
	while (boucle)//À mettre en commentaire pour jouer au jeu
	{
		//Réponse analogique des quatres filtres de la TSA
		int can0 = 0;
		int can1 = 0;
		int can2 = 0;
		int can3 = 0;

		//Lecture
		carte.lireRegistre(registres.nreg_lect_can0, can0);
		carte.lireRegistre(registres.nreg_lect_can1, can1);
		carte.lireRegistre(registres.nreg_lect_can2, can2);
		carte.lireRegistre(registres.nreg_lect_can3, can3);

		cout << "Filtre 1: " << can0 << endl;
		cout << "Filtre 2: " << can1 << endl;
		cout << "Filtre 3: " << can2 << endl;
		cout << "Filtre 4: " << can3 << endl << endl;

		clav = _getch();

		if (clav == '#')
		{
			boucle=false;
		}
	}
}

void play_game()
{
	Frame frame1;//Creation du frame du jeu


	//Determine max x and y for frame
	int pixel_x = frame1.get_x();
	int pixel_y = frame1.get_y();

	//Commence le timer et le step time
	int temps = 0;
	int step = 1; // step en secondes

	//Nécessaire pour l'actualisation de la position de la bulle
	Coordonnee position;
	position = frame1.bulle.get_xy();
	//Début du programme
	while (1)		// quand la boule est detruite alors temps = -1
	{
		//Lit le registre des boutons
		carte.lireRegistre(registres.nreg_lect_stat_btn, lecture_bouton);

		//Réponse analogique des quatres filtres de la TSA
		int can0 = 0;
		int can1 = 0;
		int can2 = 0;
		int can3 = 0;

		//Lecture
		carte.lireRegistre(registres.nreg_lect_can0, can0);
		carte.lireRegistre(registres.nreg_lect_can1, can1);
		carte.lireRegistre(registres.nreg_lect_can2, can2);
		carte.lireRegistre(registres.nreg_lect_can3, can3);

		if (_kbhit())//Interompt la boule while si un touche au clavier est tapée
		{
			clav = _getch();//Équivalent d'un cin sans avoir à faire enter
			if (clav == 'a')
			{
				clav = 'l';
				frame1.player.move(clav);//déplace le player de 5 case à gauche
			}
			else if (clav == 'd')
			{
				clav = 'r';
				frame1.player.move(clav);//déplace le player de 5 case à droite
			}
			else if (clav == ' ')
			{
				frame1.player.shoot_arrow();//tire une flèche
			}
		}

		if (lecture_bouton > 0)//Interompt la boule while si  un bouton est appuyer sur la FPGA
		{
			if (lecture_bouton == 1)
			{
				frame1.player.move('r');
			}
			else if (lecture_bouton == 8)
			{
				frame1.player.move('l');
			}
			else if (lecture_bouton == 2 || lecture_bouton == 4)
			{
				frame1.player.shoot_arrow();
			}
		}

		if (can0 >= 0 || can1 >= 0 || can2 >= 0 || can3 >= 0)
		{
			if (can0 >= 175 || can0 >= can1 || can0 >= can2 || can0 >= can3)
			{
				frame1.player.move('l');
			}
			if (can1 >= 175 || can1 >= can0 || can1 >= can2 || can1 >= can3)
			{
				frame1.player.move('l');
			}
			if (can2 >= 175 || can2 >= can0 || can2 >= can1 || can2 >= can3)
			{
				frame1.player.shoot_arrow();
			}
		}

		position = frame1.bulle.rebound(temps, step, position, pixel_x);//actualise la position de la flèche			

		frame1.refresh();//Efface et affiche toute

		temps = temps + step;//Augment le temps d'un step défini afin d'actualiser la postion de la bulle par après

		if (frame1.player.get_life() == 0 || clav == '#')
		{
			frame1.set_win(false);
			break;
		}
		if (frame1.bulle.get_layers() == 0)
		{
			frame1.set_win(true);
			break;
		}
		
		Sleep(60);//Augmente la performance du terminal, un peu
				  //cout << temps;//Pour déboggage
	}
	system("CLS");
	//Fin de la partie
	if (!frame1.get_win())
	{
		cout << "YOU DIED" << endl;
		cout << "Score: " << frame1.get_score() << endl;
	}
	else if (frame1.get_win())
	{
		cout << "THE BUBBLE HAS BEEN DESTROYED" << endl;
		cout << "Score: " << frame1.get_score() << endl;
	}

	system("Pause");
}