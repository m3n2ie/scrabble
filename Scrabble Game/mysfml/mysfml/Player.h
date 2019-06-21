//#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player{
private:
	int id;
	int score;

public:
	Player();
	Player(int);
	const int getId();
	int getScore();
	void setScore(int);
};

#endif