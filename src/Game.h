
#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include "GameObject.h"
#include "Playground.h"
#include <iostream>
#include <vector>
#include <string>

class Game
{
public: //auf private setzen später
	Player* player[3];
	std::vector<GameObject*> rocks;
	std::vector<GameObject*> wall;
	std::vector<GameObject*> bombs;
	Playground* pg = NULL;

	void drawLogo();

	void deleteLogo();

	void drawLegend();

	void drawPlayerStats(int player_number);

	void drawScoreboard();

	void init(std::string filename);

	bool allPlayersAlive();

public:
	void run();

	Game();
};

#endif /* GAME_H_ */
