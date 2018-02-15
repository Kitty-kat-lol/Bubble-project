#include "Frame.h"

Frame::Frame()
{
	dimension.x = 168;//Max width
	dimension.y = 40;//Max height
	for (int i = 0; i < 40;i++)
	{
		for (int j = 0; j < 168; j++)
		{
			table[i][j] = ' ';
		}
	}
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

void Frame::refresh()
{
	//For final game
}

void Frame::print_test_blank()
{
	cout << "Start of frame" << endl;

	for (int i = 0; i < dimension.y; i++)
	{
		cout << "\n";
	}
	cout << "End of frame";
}

void Frame::print_test_dot()
{
	int character_count = 40 * 168;
	cout << "Start of frame" << endl;
	for (int i = 0; i < character_count; i++)
	{
		cout << ".";
	}
	cout << "End of frame";

}

void Frame::print_test_table()
{
	cout << "Start of frame" << endl;
	for (int i = 0; i < 40;i++)
	{
		for (int j = 0; j < 168; j++)
		{
			cout<<table[i][j];
		}
	}
	cout << "End of frame";
}

void Frame::print_test_player()
{
	Coordonnee actual_position = Player.get_position();
	table[39-actual_position.y][actual_position.x] = 'p';
	print_test_table();
	reset_frame();
}

void Frame::reset_frame()
{
	for (int i = 0; i < 40;i++)
	{
		for (int j = 0; j < 168; j++)
		{
			table[i][j] = ' ';
		}
	}
}
