#include "Tile.h"
#include <iostream>

Tile::Tile(){//default construct creates a blank tile
	letter = '-';
	value = 0;
}

Tile::Tile(char l, int v){//Creates tile with a letter and its value
	letter = l;
	value = v;
}

char Tile::getLetter(){
	return letter;
}

void Tile::setLetter(char l){
	letter = l;
}

int Tile::getValue(){
	return value;
}

bool Tile::hasPlayer(){//checks if tile has a player (has been picked from bag)
	return player.getId() > 0;
}

Player Tile::getPlayer(){
	return player;
}

void Tile::setPlayer(Player p){ //sets tile player
	player = p;
}
