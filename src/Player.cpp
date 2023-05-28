
#include "Player.h"
#include "GameObject.h"
#include "SimpleInput.h"
#include "Configuration.h"
#include "Playground.h"
#include <iostream>
#include <string>
#include <sstream>

Player::Player(int player_number) : GameObject()
{
	this->ghost = false;
	this->trap = false;
	this->explosive = false;
	this->superbomb = false;
	this->player_number = player_number;
	this->lives = 0;
	this->score = 0;
	this->timer = 0;
}

//Funktion wertet aus ob eine Bewegung in die Richtung m�glich ist
//und f�r diese mit alle AKtionen aus.
bool Player::move(int direction)
{
	if(!(isMoveValid(direction)))
	{
		//draw?
		playground->removeGameObject(this);

		if(direction == Configuration::GAMEOBJECT_MOVE_UP)
		{
			p.setX(p.getX() - 1);
		}
		else if(direction == Configuration::GAMEOBJECT_MOVE_DOWN)
		{
			p.setX(p.getX() + 1);
		}
		else if(direction == Configuration::GAMEOBJECT_MOVE_LEFT)
		{
			p.setY(p.getY() - 1);
		}
		else if(direction == Configuration::GAMEOBJECT_MOVE_RIGHT)
		{
			p.setY(p.getY() + 1);
		}

		if(playground->isPickup(p.getX(), p.getY()))
		{
			processPickup();
		}

		playground->addGameObject(this);
	}

	return false;
}

//Routine zur Ausf�hrung der Spieleraktion
bool Player::action()
{
	if(!explosive && bomb_ptr != NULL)
	{
		explosive = true;
		timer = Configuration::BOMB_TIMER;

		this->bomb_ptr->setPosition(getPosition());
		this->top_ptr->setPosition(getPosition());

		return true;
	}
	else{
	return false;
	}
}

void Player::decreaseLives()
{
	this->lives--;
}

//Gibt zur�ck ob eine Bewegung in diese Richtung m�glich ist
bool Player::isMoveValid(int direction)
{
	int newX = p.getX();
	int newY = p.getY();

	if(direction == Configuration::GAMEOBJECT_MOVE_UP)
	{
		newX--;
	}
	else if(direction == Configuration::GAMEOBJECT_MOVE_DOWN)
	{
		newX++;
	}
	else if(direction == Configuration::GAMEOBJECT_MOVE_LEFT)
	{
		newY--;
	}
	else if(direction == Configuration::GAMEOBJECT_MOVE_RIGHT)
	{
		newY++;
	}

	if((playground->isFree(newX, newY)) || (playground->isPickup(newX, newY)))
	{
		return true;
	}

	return false;
}

//Ver�ndert den Spieler in Abh�ngigkeit des ZustandsplayerString, z.B. timer-Dekrement
void Player::proceed()
{
	if(explosive)
	{
		timer--;
	}

	else{
		return;
	}

	if(timer != 0)
	{
		return;
	}

	int radius;

	if(superbomb)
	{
		radius = Configuration::SUPERBOMB_RADIUS;
	}

	else{
		radius = Configuration::BOMB_RADIUS;
	}

	Position bomb_position = bomb_ptr->getPosition();
	bomb_ptr->setPosition(playground->getRandomFreePosition());

	playground->addGameObject(bomb_ptr);
	bomb_ptr = NULL;

	explosive = false;

	std::vector<GameObject*> affectedObject = playground->neighbourhood(radius, this);
	for(int i = 0; i < affectedObject.size(); i++)
	{
		//dynamic_cast prüft ob es um einem Player händelt, wenn nicht, gibt er nullptr zurück
		Player* name = dynamic_cast<Player*>(affectedObject.at(i));

		if(name == nullptr)
		{
			if(affectedObject.at(i)->getType() == Configuration::GAMEOBJECT_ROCK)
			{
				playground->removeGameObject(affectedObject.at(i));
				score += Configuration::POINTS_BLAST_ROCK;
			}
		}
		else{
			name->decreaseLives();

			if(name != this)
			{
				score += Configuration::POINTS_BLAST_PLAYER;
			}
		}
	}
	explosionAnimation(radius);
}

//Gibt die String repr�sentation des Spieler zur�ck.
std::string Player::to_string()
{
	//wenn es nicht geht, versuch append
	std::string playerString;
	std::stringstream ss;
	std::string status;

	if(explosive == true)
	{
		status = "Explosive";
	}
	else if(ghost == true)
	{
		status = "Ghost    ";
	}
	else{
		status = "Trap     ";
	}

	ss << "***********************" << "\n";
	ss << "* Player " << player_number << " - " << symbol << "          *" << "\n";
	ss << "***********************" << "\n";
	ss << "* Status:    " << status << " *" << "\n";
	ss << "* Timer:	    " << timer << "        *" << "\n";
	ss << "* Lives:	    " << lives << "         *" << "\n";
	ss << "* Score:	    " << score << "       *" << "\n";
	ss << "***********************" << "\n";

	ss >> playerString;
	return playerString;
}

int Player::getPlayerNumber()
{
	return this->player_number;
}

//Ausgabe der Animation mit angegebenen Radius auf der Konsole
void Player::explosionAnimation(int radius)
{
	//Später
}

//Funktion zur Bearbeitung eines eingesammelten PickUps
void Player::processPickup()
{
	GameObject* pickup = playground->collectGameObject(&p);

	if(pickup->getType() == Configuration::GAMEOBJECT_BOMB)
	{
		bomb_ptr = pickup;
		playground->removeGameObject(pickup);
	}
	else if(pickup->getType() == Configuration::GAMEOBJECT_SUPERBOMB)
	{
		bomb_ptr = pickup;
		playground->removeGameObject(pickup);
		superbomb = true;
	}
	else if(pickup->getType() == Configuration::GAMEOBJECT_PORTAL)
	{
		pickup->setPosition(playground->getRandomFreePosition());
	}

	delete pickup;
	//TRAP + GHOST
}

int Player::getLives()
{
	return this->lives;
}

int Player::getScore()
{
	return this->score;
}

//�berschreibt die Funktion der Basisklasse
//void draw(bool offset);

