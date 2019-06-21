#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "Tile.h"

using namespace std;

class Square{

private:
	int x1, x2, y1, y2; //square bounds
	string premium_type;
	Tile placed_tile;
	bool has_tile;

public:
	Square();
	Square(int, int, int, int);
	int get_x1();
	int get_x2();
	int get_y1();
	int get_y2();
	void setPremium_type(string);
	bool isPremium();
	void placeTile(Tile);
	bool hasTile();
	Tile getTile();
};

#endif