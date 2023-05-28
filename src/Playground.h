#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include "Configuration.h"
#include "GameObject.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Console.h"

class GameObject;

class Playground
{
	friend class GameObject;
private:
	void init();
public:
	//Index represents coordinates within playground
	GameObject* area[(int)Configuration::PLAYGROUND_XSIZE][(int)Configuration::PLAYGROUND_YSIZE];

	Playground();

	//Fügt den Zeiger in das area - Attribut an Index [x] [y] der Position ein.
	void addGameObject(GameObject* go_ptr);

	//"Nullt" den Zeiger im area - Attribut an Index [x] [y] der Position.
	void removeGameObject(GameObject* go_ptr);

	//"Nullt" den Zeiger im area - Attribut an Index [x] [y] der Position.
	void removeGameObject(Position pos);


	GameObject* collectGameObject(Position* pos_ptr);

	GameObject* getGameObjectAtPos(int x, int y);

	bool isFree(int x, int y);
	bool isPickup(int x, int y);
	bool isWall(int x, int y);

	//Optional Aufteilung in Moveable und solid
	void draw();

	Position getRandomFreePosition();

	bool inbound(int x, int y);
	bool isLOS(Position* pos1_ptr, Position* pos2_ptr);

	std::vector <GameObject*> neighbourhood(int distance, GameObject* go_ptr);
	std::vector <Position> neighbourhood(int distance, Position* pos_ptr);

};
#endif
