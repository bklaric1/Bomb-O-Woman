#include "Playground.h"

Playground::Playground()
{
	init();
}

void Playground::init()
{
	for(int i = 0; i < Configuration::PLAYGROUND_XSIZE; i++)
	{
		for(int j = 0; j < Configuration::PLAYGROUND_YSIZE; j++)
		{
			area[i][j] = NULL;
		}
	}
}

//memset Option gibt es auch

//Fügt den Zeiger in das area - Attribut an Index [x] [y] der Position ein.
void Playground::addGameObject(GameObject* go_ptr)
{
	if(area[go_ptr->p.getX()][go_ptr->p.getY()] == NULL)
	{
		area[go_ptr->p.getX()][go_ptr->p.getY()] = go_ptr;
		go_ptr->draw(true);
	}
	else{
		area[go_ptr->p.getX()][go_ptr->p.getY()]->top_ptr = go_ptr;
		go_ptr->draw(true);
	}
}

//"Nullt" den Zeiger im area - Attribut an Index [x] [y] der Position.
void Playground::removeGameObject(GameObject* go_ptr)
{
	removeGameObject(go_ptr->p);
}

//"Nullt" den Zeiger im area - Attribut an Index [x] [y] der Position.
void Playground::removeGameObject(Position pos)
{
	if((area[pos.getX()][pos.getY()] != NULL) && (area[pos.getX()][pos.getY()]->top_ptr == NULL))
	{
		area[pos.getX()][pos.getY()] = NULL;
		Console::zeichne_punkt(pos.getX() + Configuration::PLAYGROUND_OFFSETX, pos.getY() + Configuration::PLAYGROUND_OFFSETY, ' ');
	}
	else if((area[pos.getX()][pos.getY()] != NULL) && (area[pos.getX()][pos.getY()]->top_ptr != NULL))
	{
		area[pos.getX()][pos.getY()]->top_ptr = NULL;
		area[pos.getX()][pos.getY()]->draw(true);
	}
}


GameObject* Playground::collectGameObject(Position* pos_ptr)
{
	if(inbound(pos_ptr->getX(), pos_ptr->getY()))
	{
		if(area[pos_ptr->getX()][pos_ptr->getY()] == NULL)
		{
			return NULL;
		}
		else if((area[pos_ptr->getX()][pos_ptr->getY()] != NULL) && (area[pos_ptr->getX()][pos_ptr->getY()]->top_ptr == NULL))
		{
			GameObject* go_ptr = area[pos_ptr->getX()][pos_ptr->getY()];
			removeGameObject(area[pos_ptr->getX()][pos_ptr->getY()]->p);
			return go_ptr;
		}
		else if((area[pos_ptr->getX()][pos_ptr->getY()] != NULL) && (area[pos_ptr->getX()][pos_ptr->getY()]->top_ptr != NULL))
		{
			GameObject* go_ptr = area[pos_ptr->getX()][pos_ptr->getY()]->top_ptr;
			removeGameObject(area[pos_ptr->getX()][pos_ptr->getY()]->top_ptr);
			return go_ptr;
		}
	}

	return NULL;
}

GameObject* Playground::getGameObjectAtPos(int x, int y)
{
	if(inbound(x, y))
	{
		return area[x][y];
	}
	else{
		area[x][y] = NULL;
		return NULL;
	}
}

bool Playground::isFree(int x, int y)
{
	//nicht so verschachteln, weniger if Abfragen

	bool free;

	if(inbound(x, y))
	{
		if(area[x][y] == NULL)
		{
			free = true;
		}
	}
	else{
		free = false;
	}

	return free;
}

bool Playground::isWall(int x, int y)
{
	//nicht so verschachteln, weniger if Abfragen

	bool wall;

	if(inbound(x, y))
	{
		GameObject* go_ptr = getGameObjectAtPos(x, y);
		if((go_ptr->symbol == Configuration::GAMEOBJECT_WALL) && (go_ptr != nullptr))
		{
			wall = true;
		}
	}
	else{
		wall = false;
	}

	return wall;
}

bool Playground::isPickup(int x, int y)
{
	//nicht so verschachteln, weniger if Abfragen

	bool pickup = false;

	if(inbound(x, y))
	{
		if(area[x][y] != NULL)
		{
			if((area[x][y]->getType() == Configuration::GAMEOBJECT_GHOST) || (area[x][y]->symbol == Configuration::GAMEOBJECT_BOMB)
							|| (area[x][y]->symbol == Configuration::GAMEOBJECT_SUPERBOMB) || (area[x][y]->symbol == Configuration::GAMEOBJECT_TRAP)
							|| (area[x][y]->symbol == Configuration::GAMEOBJECT_PORTAL))
					{
						pickup = true;
					}
		}
		else{
			pickup = false;
		}
	}
	else{
		pickup = false;
	}

	return pickup;
}

//Optional Aufteilung in Moveable und solid
void Playground::draw()
{
	for(int i = 0; i < Configuration::PLAYGROUND_XSIZE; i++)
	{
		for(int j = 0; j < Configuration::PLAYGROUND_YSIZE; j++)
		{
			if(area[i][j] != NULL)
			{
				area[i][j]->draw(true);
			}

			else if(area[i][j] == NULL)
			{
				Console::zeichne_punkt(i + Configuration::PLAYGROUND_OFFSETX, j + Configuration::PLAYGROUND_OFFSETY, ' ');
			}
		}
	}
}

Position Playground::getRandomFreePosition()
{
	int x, y;

	while(1)
	{
		x = rand() % Configuration::PLAYGROUND_XSIZE;
		y = rand() % Configuration::PLAYGROUND_YSIZE;

		if(isFree(x, y))
		{
			Position random;
			random.setX(x);
			random.setY(y);
			return random;
		}
	}
}

bool Playground::inbound(int x, int y)
{
	if(((x >= 0) && (x <= Configuration::PLAYGROUND_XSIZE)) && ((y >= 0) && (y <= Configuration::PLAYGROUND_YSIZE)))
	{
		return true;
	}
	else{
		return false;
	}
}
bool Playground::isLOS(Position* pos1_ptr, Position* pos2_ptr)
{
	int zaehlerX = 0;
	int zaehlerY = 0;

	//X-Positionen sind gleich, Y-Richtung wird überprüft
	if(pos1_ptr->getX() == pos2_ptr->getX())
	{
		for(int i = 0; i < abs(pos1_ptr->getY() - pos2_ptr->getY()) + 1; ++i)
		{
			isWall(pos1_ptr->getX(), i);

			if(!(isWall(pos1_ptr->getX(), i)))
			{
				zaehlerY++;
			}
		}

		if(zaehlerY == 0)
		{
			return true;
		}
	}

	//Y-Position sind gleich, X-Richtung wird überprüft
	else if(pos1_ptr->getY() == pos2_ptr->getY())
	{
		for(int i = 0; i < abs(pos1_ptr->getX() - pos2_ptr->getX()) + 1; ++i)
		{
			isFree(pos1_ptr->getY(), i);

			if(!(isFree(pos1_ptr->getY(), i)))
			{
				zaehlerX++;
			}
		}

		if(zaehlerX == 0)
		{
			return true;
		}
	}

	return false;
}

std::vector <GameObject*> Playground::neighbourhood(int distance, GameObject* go_ptr)
{
	std::vector <GameObject*> gameobject;
	int distanzGameObject;
	bool losGameObject;

	//Durchlauf von area Attribut
	for(int i = 0; i < Configuration::PLAYGROUND_XSIZE; i++)
	{
		for(int j = 0; j < Configuration::PLAYGROUND_YSIZE; j++)
		{
			//Berechnung von Manhattan-distance
			distanzGameObject = go_ptr->p.distanceManhattan(area[i][j]->p);
			//Casting von Position zu Position*
			Position newPos = Position(i, j);
			Position gameobjectPosition = Position(go_ptr->p.getX(), go_ptr->p.getY());
			//LineOfSite Überprüfung
			losGameObject = isLOS(&newPos, &gameobjectPosition);
			//In Vector speicher
			if((distanzGameObject <= distance) && (losGameObject))
			{
				gameobject.push_back(go_ptr);
			}
		}
	}

	return gameobject;
}

std::vector <Position> Playground::neighbourhood(int distance, Position* pos_ptr)
{
	std::vector<Position> position;
	int distanzPosition;
	bool losPosition;

	//Durchlauf von area Attribut
	for(int i = 0; i < Configuration::PLAYGROUND_XSIZE; i++)
	{
		for(int j = 0; j < Configuration::PLAYGROUND_YSIZE; j++)
		{
			//Berechnung von Manhattan-distance
			distanzPosition = pos_ptr->distanceManhattan(area[i][j]->p);
			//Casting von Position zu Position*
			Position newPos = Position(i, j);
			//LineOfSite Überprüfung
			losPosition = isLOS(&newPos, pos_ptr);
			//In Vector speicher
			if((distanzPosition <= distance) && (losPosition))
			{
				Position positionInstanz = Position(pos_ptr->getX(), pos_ptr->getY());
				position.push_back(positionInstanz);
			}
		}
	}

	return position;
}

