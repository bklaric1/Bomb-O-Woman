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
	}*/

	Game test;

	Console::verstecken();
	test.drawLegend();
	test.player[0] = new Player(1);
	test.player[0]->score = 20; //nur Probe, muss Player.h zurück zum protected nehmen
	test.player[1] = new Player(2);
	test.player[2] = new Player(3);
	test.player[3] = new Player(4);
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
	usleep(3000000);
	test.drawLogo();
	usleep(3000000);
	test.drawScoreboard();

	getchar();
return 0;
}
