#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Position.h"

class Player : public GameObject
{
protected:
	bool ghost;
	bool trap;
	bool explosive;
	bool superbomb;

	int player_number;
	int lives;
	int score;
	int timer;

	GameObject* bomb_ptr = NULL;

public:

	//Initialisiert alle Attribute
	Player(int player_number);

	//Funktion wertet aus ob eine Bewegung in die Richtung m�glich ist
	//und f�r diese mit alle AKtionen aus.
	bool move(int direction);

	//Routine zur Ausf�hrung der Spieleraktion
	bool action();

	//Dekrementiert die Anzahl der Leben
	void decreaseLives();

	//Gibt zur�ck ob eine Bewegung in diese Richtung m�glich ist
	bool isMoveValid(int direction);

	//Ver�ndert den Spieler in Abh�ngigkeit des Zustands, z.B. timer-Dekrement
	void proceed();

	//Gibt die String repr�sentation des Spieler zur�ck.
	std::string to_string();

	//Gibt die Spielernummer zur�ck
	int getPlayerNumber();

	//Ausgabe der Animation mit angegebenen Radius auf der Konsole
	void explosionAnimation(int radius);

	//Funktion zur Bearbeitung eines eingesammelten PickUps
	void processPickup();

	//Gibt das Attribut lives zur�ck
	int getLives();

	//Gibt das Attribut score zur�ck (Optional)
	int getScore();

	//�berschreibt die Funktion der Basisklasse 
	void draw(bool offset){};
};
#endif
