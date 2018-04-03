#ifndef ARROW_H
#define ARROW_H

#include "Coordonne.h"
#include <string>
#include "stdafx.h"


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
