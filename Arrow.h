#ifndef ARROW_H
#define ARROW_H

#include "Coordonne.h"
#include <string>

class Arrow
{
public:
	Arrow();
	~Arrow();
private:
	int y_speed;
	char state;
protected:
	Coordonnee position;
};

#endif
