
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
private:
	Player* player[3];
	std::vector<GameObject*> rocks;
	std::vector<GameObject*> wall;
	std::vector<GameObject*> bombs;
	Playground* pg = NULL;

	void drawSmallLogo();

	void drawBigLogo();

	void deleteSmallLogo();

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
