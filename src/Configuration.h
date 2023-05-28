#pragma once
namespace Configuration
{
	const int PLAYGROUND_XSIZE = 12 ;
	const int PLAYGROUND_YSIZE = 12;
	const int PLAYGROUND_OFFSETX = 1;
	const int PLAYGROUND_OFFSETY = 1;

	const int PLAYGROUND_BORDERWIDTH = 1;

	//GAMEOBJECT - INPUT
	const int GAMEOBJECT_MOVE_UP = 0;
	const int GAMEOBJECT_MOVE_DOWN = 1;
	const int GAMEOBJECT_MOVE_RIGHT = 2;
	const int GAMEOBJECT_MOVE_LEFT = 3;
	const int GAMEOBJECT_ACTION = 4;


	//GAMEOBJECT - MOVEABLE
	const char GAMEOBJECT_PLAYER_1 = 'X';
	const char GAMEOBJECT_PLAYER_2 = 'O';
	const char GAMEOBJECT_PLAYER_3 = '+';
	const char GAMEOBJECT_PLAYER_4 = '*';
	const char GAMEOBJECT_MONSTER = 'M';

	//GAMEOBJECT - OBSTACLES NON-MOVEABLE / SOLID
	const char GAMEOBJECT_ROCK = 'R';
	const char GAMEOBJECT_WALL = '#';

	//GAMEOBJECTS - PICKUP
	const char GAMEOBJECT_GHOST = 'G';
	const char GAMEOBJECT_BOMB = 'B';
	const char GAMEOBJECT_SUPERBOMB = 'S';
	const char GAMEOBJECT_PORTAL = 'P';
	const char GAMEOBJECT_TRAP = 'T';

	//GAMEMODES
	const int GAMEMODE_ENDLESS_BOMBS = 0;
	const int GAMEMODE_HIGHSCORE = 1;

	//GAMEPLAY
	const int GAMEMODE = GAMEMODE_ENDLESS_BOMBS;
	const int NUMBER_OF_PLAYERS = 2;
	const int GAMESPEED = 50;
	const int BOMB_TIMER = 30;
	const int BOMB_RADIUS = 3;
	const int SUPERBOMB_TIMER = 200;
	const int SUPERBOMB_RADIUS = 8;


	const int PLAYER_LIVES = 3;
	const int PLAYER_BOMBS = 3;
	const int NUMBER_OF_ROCKS = 30;
	const int NUMBER_OF_WALLS = 100;
	const int NUMBER_OF_PORTALS = 2;
	const int NUMBER_OF_BOMBS = 2;

	//SCORE
	const int POINTS_BLAST_ROCK = 5;
	const int POINTS_BLAST_PLAYER = 100;
};
