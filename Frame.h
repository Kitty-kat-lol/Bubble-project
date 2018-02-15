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
	Player Player;
private:
	
	char table[41][169];
protected:
	Coord dimension;

};
#endif