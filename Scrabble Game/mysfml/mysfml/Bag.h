#ifndef BAG_H
#define BAG_H

#include "Tile.h"
#include <array>

using namespace std;

class Bag{

private:
	//To store a tile with its corresponding quantity
	struct tile_details{
		Tile tile;
		int quantity;
		string img;
	};
	int random; //stores the random value used to pick tiles from the bag
	int id = 0;
	//To store all tiles in the bag
	array <tile_details, 27> all_tiles;
	//27 types of tiles

public:
	Bag();
	Tile pickTile();
	string getTile_img(Tile);
	bool isEmpty();

};

#endif