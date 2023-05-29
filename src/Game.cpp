#include "Cursor.h"
#include "Game.h"
#include "Console.h"
#include <string>
#include <sstream>

void Game::drawLogo()
{
	Cursor::bewegen(5, 3);
	std::cout<<" ____ ™"<<std::endl;
	Cursor::bewegen(5, 4);
	std::cout<<"|  _ \\"<<std::endl;
	Cursor::bewegen(5, 5);
	std::cout<<"| |_) )"<<std::endl;
	Cursor::bewegen(5, 6);
	std::cout<<"|  _ ( "<<std::endl;
	Cursor::bewegen(5, 7);
	std::cout<<"| |_) )"<<std::endl;
	Cursor::bewegen(5, 8);
	std::cout<<"|____/ "<<std::endl;
}
void Game::deleteLogo()
{
	Cursor::bewegen(5, 3);
	std::cout<<"         "<<std::endl;
	Cursor::bewegen(5, 4);
	std::cout<<"         "<<std::endl;
	Cursor::bewegen(5, 5);
	std::cout<<"         "<<std::endl;
	Cursor::bewegen(5, 6);
	std::cout<<"         "<<std::endl;
	Cursor::bewegen(5, 7);
	std::cout<<"         "<<std::endl;
	Cursor::bewegen(5, 8);
	std::cout<<"         "<<std::endl;
	Cursor::bewegen(5, 9);
	std::cout<<"         "<<std::endl;
	Cursor::bewegen(5, 10);
	std::cout<<"         "<<std::endl;
	Cursor::bewegen(5, 11);
}

void Game::drawLegend()
{
	Cursor::bewegen(18, 2);
	std::cout<<Configuration::GAMEOBJECT_PLAYER_1<<" - Player 1 "<<std::endl;
	Cursor::bewegen(18, 3);
	std::cout<<Configuration::GAMEOBJECT_PLAYER_2<<" - Player 2 "<<std::endl;
	Cursor::bewegen(18, 4);
	std::cout<<Configuration::GAMEOBJECT_PLAYER_3<<" - Player 3 "<<std::endl;
	Cursor::bewegen(18, 5);
	std::cout<<Configuration::GAMEOBJECT_PLAYER_4<<" - Player 4 "<<std::endl;
	Cursor::bewegen(18, 6);
	std::cout<<Configuration::GAMEOBJECT_MONSTER<<" - Monster"<<std::endl;
	Cursor::bewegen(18, 7);
	std::cout<<Configuration::GAMEOBJECT_GHOST<<" - Ghost (Pickup)"<<std::endl;
	Cursor::bewegen(18, 8);
	std::cout<<Configuration::GAMEOBJECT_BOMB<<" - Bomb (Pickup)"<<std::endl;
	Cursor::bewegen(18, 9);
	std::cout<<Configuration::GAMEOBJECT_SUPERBOMB<<" - Superbomb (Pickup)"<<std::endl;
	Cursor::bewegen(18, 10);
	std::cout<<Configuration::GAMEOBJECT_PORTAL<<" - Portal (Pickup)"<<std::endl;
	Cursor::bewegen(18, 11);
	std::cout<<Configuration::GAMEOBJECT_TRAP<<" - Trap (Pickup)"<<std::endl;
	Cursor::bewegen(18, 12);
	std::cout<<Configuration::GAMEOBJECT_ROCK<<" - Rock"<<std::endl;
	Cursor::bewegen(18, 13);
	std::cout<<Configuration::GAMEOBJECT_WALL<<" - Wall"<<std::endl;
}

void Game::drawPlayerStats(int player_number)
{
	if(player_number == 1)
	{
		Cursor::bewegen(0, 0);
		std::string player1 = player[player_number - 1]->to_string();
		std::istringstream iss(player1);
		std::string line;
		int x = 3;
		int y = 15;

		while(std::getline(iss, line))
		{
			Cursor::bewegen(x, y);
			std::cout<< line << std::endl;
			y++;
		}
	}
	else if(player_number == 2)
	{
		Cursor::bewegen(0, 0);
		std::string player2 = player[player_number - 1]->to_string();
		std::istringstream iss(player2);
		std::string line;
		int x = 27;
		int y = 15;

		while(std::getline(iss, line))
		{
			Cursor::bewegen(x, y);
			std::cout<< line << std::endl;
			y++;
		}
	}
	else if(player_number == 3)
	{
		Cursor::bewegen(0, 0);
		std::string player3 = player[player_number - 1]->to_string();
		std::istringstream iss(player3);
		std::string line;
		int x = 3;
		int y = 23;

		while(std::getline(iss, line))
		{
			Cursor::bewegen(x, y);
			std::cout<< line << std::endl;
			y++;
		}
	}
	else if(player_number == 4)
	{
		Cursor::bewegen(0, 0);
		std::string player4 = player[player_number - 1]->to_string();
		std::istringstream iss(player4);
		std::string line;
		int x = 27;
		int y = 22;

		while(std::getline(iss, line))
		{
			Cursor::bewegen(x, y);
			std::cout<< line << std::endl;
			y++;
		}
	}

}

void Game::drawScoreboard()
{

}

void Game::init(std::string filename)
{

}

bool Game::allPlayersAlive()
{
	int lebendigeSpieler;

	for(int i = 0; i < 4; i++)
	{
		if(player[i]->getLives() > 0)
		{
			lebendigeSpieler++;
		}
	}

	if(lebendigeSpieler > 0)
	{
		return true;
	}
	else{
		return false;
	}
}

void Game::run()
{

}

Game::Game()
{

}
