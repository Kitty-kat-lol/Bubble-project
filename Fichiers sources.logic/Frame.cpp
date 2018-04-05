#include "Frame.h"



Frame::Frame()
{
	//A modifier pour cahque écran
	//Gab tour:		237 et 62
	//Gab laptop:	168 et 43
	//Kate:			x et y
	//P-A:			x et y

	dimension.x = 237;//Max width
	dimension.y = 62;//Max height
	for (int i = 0; i < dimension.y;i++)
	{
		for (int j = 0; j < dimension.x; j++)
		{
			table[i][j] = ' ';//Initalise le tableau a des caractères vides
		}
	}
	print = " ";
	score = 0;
}

Frame::~Frame()
{
}

int Frame::get_x()
{
	return dimension.x;
}

int Frame::get_y()
{
	return dimension.y;
}

bool Frame::get_win()
{
	return win;
}

int Frame::get_score()
{
	return score;
}

void Frame::set_win(bool command)
{
	win = command;
}

void Frame::calculate_score()
{
	score += 25;
}



void Frame::refresh()
{
	system("CLS");//Efface le contenu du terminal

	//Assigne les différents éléments
	print_test_arrow();
	print_test_player();
	print_test_bulle();

	//Incrémente le score
	calculate_score();

	//Affiche le tableau
	print_test_table();
}


void Frame::print_test_blank()//Test
{
	cout << "Start of frame" << endl;

	for (int i = 0; i < dimension.y; i++)
	{
		cout << "\n";
	}
	cout << "End of frame";
}

void Frame::print_test_dot()//Test, à utiliser pour trouver la dimension en x, copie-colle la première ligne dans word pour conter les charactères et les lignes
{
	system("CLS");
	int character_count = dimension.x * dimension.y;
	//cout << "Start of frame" << endl;
	for (int i = 0; i < character_count; i++)
	{
		cout << ".";
	}
	//cout << "End of frame";

}

void Frame::print_test_table()//Affiche le tableau
{
	//cout << "Start of frame" << endl;
	for (int i = 0; i < dimension.y;i++)
	{
		for (int j = 0; j < dimension.x; j++)
		{
			//cout<<table[i][j];
			print += table[i][j];
		}
	}
	cout << print;// On eécrit le string d'une shot à la place de char par char, ca aide un peu!
	//cout << "End of frame";
	reset_frame();//Efface le contenu du table apres l'avoir afficher
}

void Frame::print_test_player()//Assigne la lettre p à la position du player
{
	collision_player();
	Coordonnee actual_position = player.get_position();
	table[dimension.y-actual_position.y-1][actual_position.x] = 'p';
}

void Frame::print_test_arrow()//Assigne la lettre A à la posotion de la flèche
{
	if(player.Arrow.get_state()=='a')//Vérifie que le flèche est active
	{
		Coordonnee actual_position = player.get_arrow_position();
		table[dimension.y - actual_position.y-1][actual_position.x] = 'A';
		player.Arrow.move();
	}	
}

void Frame::print_test_bulle()//Assigne l'épaisseur de la bulle à sa position
{
	collision_bulle();//Vérifie s'il y a contact avec la flèche et la bulle

	//Converti l'épaisser de la bulle en un char pour l'affichage
	char layers;
	if (bulle.get_layers() == 3)
		layers = '3';
	else if (bulle.get_layers() == 2)
		layers = '2';
	else if (bulle.get_layers() == 1)
		layers = '1';
	else
		layers = 'O';



	Coordonnee actual_position = bulle.get_xy();
	table[dimension.y - actual_position.y][actual_position.x] = layers;

	table[(dimension.y - actual_position.y)-2][(actual_position.x)] = '#';
	table[(dimension.y - actual_position.y) + 2][(actual_position.x)] = '#';
	table[(dimension.y - actual_position.y) ][(actual_position.x)-2] = '#';
	table[(dimension.y - actual_position.y) ][(actual_position.x)+2] = '#';
	table[(dimension.y - actual_position.y) - 1][(actual_position.x) - 1] = '#';
	table[(dimension.y - actual_position.y) - 1][(actual_position.x) + 1] = '#';
	table[(dimension.y - actual_position.y) + 1][(actual_position.x) + 1] = '#';
	table[(dimension.y - actual_position.y) + 1][(actual_position.x) - 1] = '#';
}

void Frame::print_test_count()
{
	
	cout << "Start of frame" << endl;
	for (int i = 0; i <100; i++)
	{
		cout << i<<'\n';
	}
}


void Frame::reset_frame()//Efface le contenu du tableau
{
	for (int i = 0; i < dimension.y;i++)
	{
		for (int j = 0; j < dimension.x; j++)
		{
			table[i][j] = ' ';
		}
	}
	print = "";
}

void Frame::collision_bulle()//Impact entre la bulle et la flèche
{
	bool hitbox = false;

	if ((player.Arrow.get_state()=='a') && (abs(player.Arrow.get_position().x - bulle.get_xy().x) <=2) && (abs(player.Arrow.get_position().y - bulle.get_xy().y) <=2))
	{
		hitbox = true;
	}
	
	if (hitbox)
	{
		bulle.pop_layer();
		player.Arrow.set_state('i');
		score += 1000;
		//cout << "Bulle touchee";
	}
}

void Frame::collision_player()//Impact entre la bulle et la flèche
{
	int hitbox = 5;
	bool hit = false;

	if ((abs(player.get_position().x - bulle.get_xy().x) <= hitbox) && (abs(player.get_position().y - bulle.get_xy().y) <= hitbox))
	{
		hit = true;
	}

	if (hit)
	{
		player.hit();
		//cout << "Player touche";
	}
}


