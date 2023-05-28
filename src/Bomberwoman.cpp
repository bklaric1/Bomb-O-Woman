//============================================================================
// Name        : Bomberwoman.cpp
// Author      : Benjamin Klaric
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Position.h"
#include "Cursor.h"
#include "Console.h"
#include "SimpleInput.h"


int main()
{
	//irgendwas
	Console::leeren();
	Cursor::setze_farbe(CURSOR_BLAU);
	for (int x = 5; x < 20; x++)
	{
		for (int y = 5; y < 10; y++)
		{
			Console::zeichne_punkt(x, y, '#');
		}
	}
	getchar();
return 0;
}
