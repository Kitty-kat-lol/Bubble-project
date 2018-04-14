#include "Registres.h"
#include"CommunicationFPGA.h"
#include "Input_FPGA.h"

#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int main(void)
{
	
	Input_FPGA test;
	test.set_debug(true);
	while (true)
	{
		test.read();
		test.print_CMD();
		

		char breaking = ' ';

		if (_kbhit())
		{
			breaking = _getch();
			if (breaking == '#')
			{
				break;
			}
		}
		
	}
	
	return 0;
}