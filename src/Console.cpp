#include <iostream>
#include "Console.h"
#include "Cursor.h"


//Leere Bildschirm, verstecke Cursor, Position 0,0
void Console::init()
{
	Console::leeren();
	Console::verstecken();
}
//Leere Terminal
void Console::leeren()
{
	std::cout << "\33[2J";
}
//Verstecke Cursor
void Console::verstecken()
{
	std::cout << "\33[?25l";
}
//Zeigt den Cursor
void Console::zeigen()
{
	std::cout << "\33[?25h";
}

//Gebe Zeichen c an Position x, y aus.
void Console::zeichne_punkt(int x, int y, char c)
{
	//printf("\33[%d;%dH%c", y, x, c);
	Cursor::bewegen(x, y);
	std::cout << c;
}


