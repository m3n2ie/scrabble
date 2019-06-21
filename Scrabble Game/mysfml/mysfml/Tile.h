#ifndef TILE_H
#define TILE_H

#include "Player.h"

class Tile{

private:
	char letter;
	int value;
	Player player;

public:
	int id;
	Tile();
	Tile(char, int);
	char getLetter();
	void setLetter(char); //for blank tiles
	int getValue();
	bool hasPlayer();
	Player getPlayer();
	void setPlayer(Player); //player to be set after a tile was randomly picked from the bag

};

#endif