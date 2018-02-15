#ifndef FRAME_H
#define FRAME_H

#include <iostream>

#include "Player.h"


using namespace std;


class Frame
{
public:
	Frame();
	~Frame();
	void refresh();
	void print_test_blank();
	void print_test_dot();
	void print_test_table();
	void print_test_player();
	void reset_frame();
	int get_x();
	int get_y();
	Player player;
private:

	char table[41][169];
protected:
	Coordonnee dimension;

};
#endif
