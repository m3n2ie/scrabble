#include "Player.h"
//Creates player
Player::Player(int i){
	id = i;
	score = 0;
}

Player::Player(){
	id = -1;
}

const int Player::getId(){
	return id;
}
//Gets player score
int Player::getScore(){
	return score;
}
//Sets player score
void Player::setScore(int value){
	score = value;
}