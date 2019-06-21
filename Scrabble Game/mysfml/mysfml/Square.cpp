#include "Square.h"

Square::Square(){
	premium_type = "";
}
//Creates a new square using on the top left corner and bottom right corner points
Square::Square(int x1, int x2, int y1, int y2){
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

int Square::get_x1(){
	return this->x1;
}

int Square::get_x2(){
	return this->x2;
}

int Square::get_y1(){
	return this->y1;
}

int Square::get_y2(){
	return this->y2;
}

void Square::setPremium_type(string premium_type){//sets square premium type (e.g x3WS, x2LS,...etc)
	this->premium_type = premium_type;
}
bool Square::isPremium(){//checks if square is premium
	return premium_type == "";
}

void Square::placeTile(Tile t){//places given tile on the square
	placed_tile = t;
	has_tile = true;
}

bool Square::hasTile(){//checks if square has tile
	return has_tile;
}

Tile Square::getTile(){
	return placed_tile;
}