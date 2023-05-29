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
#include "Game.h"
#include "Player.h"
#include "GameObject.h"
#include <unistd.h>


int main()
{
	//irgendwas
	/*
	Console::leeren();
	Cursor::setze_farbe(CURSOR_BLAU);
	for (int x = 5; x < 20; x++)
	{
		for (int y = 5; y < 10; y++)
		{
			Console::zeichne_punkt(x, y, '#');
		}
	}
	*/
	Player player1(1);
	Player player2(2);
	Player player3(3);
	Player player4(4);
	Game test;

	Console::verstecken();
	test.drawLegend();
	test.player[0] =  &player1;
	test.player[1] =  &player2;
	test.player[2] =  &player3;
	test.player[3] =  &player4;
	test.drawPlayerStats(1);
	test.drawPlayerStats(2);
	test.drawPlayerStats(3);
	test.drawPlayerStats(4);
	test.drawLogo();
	usleep(3000000);
	//or
	//#include <chrono>
	//#include <thread>
	//std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	test.deleteLogo();

	getchar();
return 0;
}
