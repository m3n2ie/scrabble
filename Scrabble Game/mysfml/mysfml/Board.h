#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Square.h"

using namespace std;

class Board{

private:
	 Square board_squares[15][15];//Stores all squares on the board
public:
	Board();
	Square getSquare(int, int);
};

#endif