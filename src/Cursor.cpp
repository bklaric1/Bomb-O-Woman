#include "Cursor.h"
#include <iostream>

//Positioniere Cursor an Position x,y
void Cursor::bewegen(int x, int y)
{
	std::cout << "\33[" << y << ";" << x << "H";	//Kommandos	\033[<L>; <C>H oder \033[<L>; <C>f
}

//Bewege den cursor um n Zeilen nach oben
void Cursor::hoch(int n)
{
	std::cout << "\033[" << n << "A";
}
//Bewege den cursor um n Zeilen nach unten
void Cursor::runter(int n)
{
	std::cout << "\033[" << n << "B";
}
//Bewege Cursor um n Stellen/Spalten nach rechts:  \033[<N>C
void Cursor::rechts(int n)
{
	std::cout << "\033[" << n << "C";
}
//Bewege Cursor um n Stellen/Spalten nach links:  \033[<N>D
void Cursor::links(int n)
{
	std::cout << "\033[" << n << "D";
}
//Setze Schriftfarbe oder Hintergrundfarbe
void Cursor::setze_farbe(const char* farbe)
{
	std::cout << farbe;
}

//Speichert die aktuelle Cursor Position
void Cursor::speichere_position()
{
	std::cout << "\033[s";
}
//Stellt die gespeicherte Cursor Position wieder her
void Cursor::gehezu_letzte_gespeicherte_position()
{
	std::cout << "\033[u";
};