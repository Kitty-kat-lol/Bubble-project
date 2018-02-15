#include <iostream>

#include "Arrow.h"
#include "Player.h"
#include "Coordonne.h"
#include "Frame.h"
#include "Bulle.h"
#include <unistd.h>
#include <conio.h>

using namespace std;


int main()
{
	cout << "Resize window..." << endl << "If ready enter 1";
	int ready = 0;
	cin >> ready;
	Frame frame1;//Creation du frame du jeu
	Player player;
	int pixel_x = frame1.get_x();
	int pixel_y = frame1.get_y();
	int temps = 0;
	int step = 1; // step en secondes
	Bulle bulle1;
	Coordonnee position;
	position = bulle1.get_xy();
	char clav;
	while (temps != -1)		// quand la boule est detruite alors temps = -1
	{
		if (kbhit())
		{
			clav = getch();
			if (clav == 'a')
			{
				clav = 'l';
				player.move(clav);
			}
			else if (clav == 'd')
			{
				clav = 'r';
				player.move(clav);
			}
		}
		position = bulle1.rebound(temps, step, position, pixel_x);
		bulle1.afficher_bulle(pixel_x, pixel_y);
		int i = 0;
		Coordonnee play = player.get_position();
		for (i = 0;i < pixel_x;i = i + 1)
		{
			if (i == play.x)
			{
				cout << 'P';
			}
			else
			{
				cout << ' ';
			}
		}
		std::cout << std::endl;
		temps = temps + step;
		std::cout << "X" << position.x << "Y" << position.y << std::endl;
		usleep(65000);
		std::cout << temps << std::endl;
	}
	return 0;
}
