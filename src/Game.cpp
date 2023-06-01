#include "Cursor.h"
#include "Game.h"
#include "Console.h"
#include <string>
#include <sstream>
#include <fstream>
#include "SimpleInput.h"
#include <unistd.h>
#include "Playground.h"
#include "Position.h"

void Game::drawSmallLogo()
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
void Game::deleteSmallLogo()
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

void Game::drawBigLogo()
{
	Console::init();

	Cursor::bewegen(17, 1);
	std::cout<<"                        .-."<<std::endl;
	Cursor::bewegen(17, 2);
	std::cout<<"                        '-'"<<std::endl;
	Cursor::bewegen(17, 3);
	std::cout<<"                       //"<<std::endl;
	Cursor::bewegen(17, 4);
	std::cout<<"               _..---._/|"<<std::endl;
	Cursor::bewegen(17, 5);
	std::cout<<"             .' .\"     '-."<<std::endl;
	Cursor::bewegen(17, 6);
	std::cout<<"            /__/   BW     \\      *"<<std::endl;
	Cursor::bewegen(17, 7);
	std::cout<<"           ====_____     __|     :"<<std::endl;
	Cursor::bewegen(17, 8);
	std::cout<<"          /#   #\"\"\" |   /()\\    :    ..* "<<std::endl;
	Cursor::bewegen(17, 9);
	std::cout<<"          |#   #    |   \\__/    : .''"<<std::endl;
	Cursor::bewegen(17, 10);
	std::cout<<"          \\#___#____|      /   :::.. ."<<std::endl;
	Cursor::bewegen(17, 11);
	std::cout<<"           \\______________|_...‰_: .. '*"<<std::endl;
	Cursor::bewegen(17, 12);
	std::cout<<"  ()       // /\\||||)))))))      '   . ."<<std::endl;
	Cursor::bewegen(17, 13);
	std::cout<<" .( \\_     \\_\\//   _-'.'/        |   * .."<<std::endl;
	Cursor::bewegen(17, 14);
	std::cout<<"( )  |^|^|^|ooo/  _#\\.//\"\"\"_      |   . . ."<<std::endl;
	Cursor::bewegen(17, 15);
	std::cout<<"(_)_.'v|v|v|     / \\#  \\_ / '_  _'    . ."<<std::endl;
	Cursor::bewegen(17, 16);
	std::cout<<"           | _ _/_/     /'./_-|\"         . ."<<std::endl;
	Cursor::bewegen(17, 17);
	std::cout<<"           /#_#__\"\"\"-._ /#  \\__)       .  ."<<std::endl;
	Cursor::bewegen(17, 18);
	std::cout<<"           |__   ""-._ |##               . . ."<<std::endl;
	Cursor::bewegen(17, 19);
	std::cout<<"           |  \"\"|-\"\"\"-_/##              . ."<<std::endl;
	Cursor::bewegen(17, 20);
	std::cout<<"           /""--\\__.-|                       ."<<std::endl;
	Cursor::bewegen(17, 21);
	std::cout<<"           \\-_.-<__ /                   .   ."<<std::endl;
	Cursor::bewegen(17, 22);
	std::cout<<"           /-_| /  \\\\"<<std::endl;
	Cursor::bewegen(17, 23);
	std::cout<<"           \\-_| \\_-<.                        .  ."<<std::endl;
	Cursor::bewegen(17, 24);
	std::cout<<"           <_-/ <_.-\\                    ."<<std::endl;
	Cursor::bewegen(17, 25);
	std::cout<<"           <_-|  |_.-|                        ."<<std::endl;
	Cursor::bewegen(17, 26);
	std::cout<<"      .----|   \\__\\  |                 ."<<std::endl;
	Cursor::bewegen(17, 27);
	std::cout<<"     |     .\"\"\"   '.  |                       ."<<std::endl;
	Cursor::bewegen(17, 28);
	std::cout<<"      .___|        |__|"<<std::endl;
	Cursor::bewegen(17, 29);
	std::cout<<"          '.__...\"\"\""<<std::endl;
	Cursor::bewegen(17, 30);
	std::cout<<"------------------------------------------------"<<std::endl;

	usleep(1000000);
	Console::leeren();
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
		int x = 2;
		int y = 16;

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
		int y = 16;

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
		int y = 24;

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
		int y = 23;

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
	//deleteLogo();
	Console::leeren();

	Cursor::bewegen(35, 11);
	std::cout<<"~Scoreboard~"<<std::endl;
	Cursor::bewegen(35, 12);
	std::cout<<"------------"<<std::endl;
	//int zaehler = 0; //nur wenn wir wollen, dass kein Player2 gibts oder was ähnliches

	for(int i = 0; i < 3; i++)
	{
		if(player[i]->getScore() > 0)
		{
			Cursor::bewegen(35, 15 + i);//- zaehler
			std::cout<<"Player "<< i + 1 << ": "<<player[i]->getScore()<<std::endl;
	//		zaehler++;
		}
	}

}

void Game::init(std::string filename)
{
	Console::leeren();
	std::ifstream stagefile;//("../src/stage1.txt");
	pg = new Playground();
	std::string line;


	int x = 0;
	int y = 0;

	stagefile.open("/home/bklaric01/eclipse-workspace/BomberWoman/Debug/stage1.txt");
/*
	if (stagefile.is_open()) {
		std::cout << "Yippie" << std::endl;
	} else {
		std::cout << "Buh!" << std::endl;
	}
	*/


	if(stagefile.is_open())
	{
		while(std::getline(stagefile, line))
		{
			for(int x = 0; x < line.length(); x++)
			{
				char object = line.at(x);

				//GameObject* wall_ptr = new GameObject(/*Position(x, y), object, pg*/);
				//wall_ptr->setPosition(Position());
				// std::cout << Position().to_string();
				//std::cout << wall_ptr << wall_ptr->getPosition().to_string() << std::endl;;
				//wall.push_back(wall_ptr);
				//pg->addGameObject(wall_ptr);
				//std::cout << object;

				if(object == Configuration::GAMEOBJECT_PLAYER_1)
				{
					player[0] = new Player(1, object);
					player[0]->setPosition(Position(x, y));
					player[0]->setPlayground(pg);
					pg->addGameObject(player[0]);
				}
				else if(object == Configuration::GAMEOBJECT_PLAYER_2)
				{
					player[1] = new Player(2, object);
					player[1]->setPosition(Position(x, y));
					player[1]->setPlayground(pg);
					pg->addGameObject(player[1]);
				}
				else if(object == Configuration::GAMEOBJECT_WALL)
				{
					GameObject* wall_ptr = new GameObject(Position(x, y), object, pg);
					wall.push_back(wall_ptr);
					pg->addGameObject(wall_ptr);
				}
				else if(object == Configuration::GAMEOBJECT_ROCK)
				{
					GameObject* rock_ptr = new GameObject(Position(x, y), object, pg);
					rocks.push_back(rock_ptr);
					pg->addGameObject(rock_ptr);
				}
				else if(object == Configuration::GAMEOBJECT_BOMB)
				{
					GameObject* bomb_ptr = new GameObject(Position(x, y), object, pg);
					bombs.push_back(bomb_ptr);
					pg->addGameObject(bomb_ptr);
				}

			}
			y++;
			// std::cout << std::endl;
		}
	}
	else{
		std::cout<<"Error opening"<<std::endl;
		std::cout<<" text file !"<<std::endl;
		return;
	}

	stagefile.close();
	drawLegend();
	pg->draw();
}

bool Game::allPlayersAlive()
{
	int lebendigeSpieler;

	for(int i = 0; i < 3; i++)
	{
		if(player[i]->getLives() > 0)
		{
			return true;
			//lebendigeSpieler++;
		}
	}

	return false;
/*
	if(lebendigeSpieler > 0)
	{
		return true;
	}
	else{
		return false;
	}
	*/
}

void Game::run()
{
//    drawBigLogo();

    while(allPlayersAlive())
    {
        if(player[0] != NULL)
        {
        	char i = SimpleInput::getWASD(100);
        	if(i == Configuration::GAMEOBJECT_ACTION)
        	{
        		player[0]->action();
        	}

        	else{
            player[0]->move(i);
        	}

            player[0]->proceed();
            drawPlayerStats(1);
        }

        if(player[1] != NULL)
        {
        	char i = SimpleInput::getArrow(100);
        	if(i == Configuration::GAMEOBJECT_ACTION)
        	{
        		player[1]->action();
        	}

        	else{
            player[1]->move(i);
        	}

            player[1]->proceed();
           drawPlayerStats(2);
        }

    }
    //drawScoreboard();
}

Game::Game()
{
	drawBigLogo();
	sleep(3);
	init("stage1.txt");
}


/*
		for(int y = 0 + Configuration::PLAYGROUND_OFFSETY; y < Configuration::PLAYGROUND_YSIZE + Configuration::PLAYGROUND_OFFSETY; y++)
		{
			for(int x = 0 + Configuration::PLAYGROUND_OFFSETX; y < Configuration::PLAYGROUND_XSIZE + Configuration::PLAYGROUND_OFFSETX; x++)
			{
 */
