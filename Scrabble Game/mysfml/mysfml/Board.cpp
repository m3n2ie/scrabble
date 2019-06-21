#include "Board.h"
#include <iostream>


Board::Board(){
	//Sets bounds for all squares on the board
	for (int row = 0; row < 15; row++){
		for (int col = 0; col < 15; col++){
			board_squares[row][col] = Square(144+(34*col)+(2*col), 144+34*(col + 1)+(2*col) , 49+(34*row)+(2*row), 49+34*(row+1)+(2*row));
		}
	}

	//=====================Sets premium squares================================
	//Red squares
	board_squares[0][0].setPremium_type("3xWS"); board_squares[0][7].setPremium_type("3xWS"); board_squares[0][14].setPremium_type("3xWS");
	board_squares[7][0].setPremium_type("3xWS"); board_squares[14][0].setPremium_type("3xWS"); board_squares[7][14].setPremium_type("3xWS");
	board_squares[14][14].setPremium_type("3xWS"); board_squares[14][7].setPremium_type("3xWS");
	//Pink squares
	board_squares[1][1].setPremium_type("2xWS"); board_squares[2][2].setPremium_type("2xWS"); board_squares[3][3].setPremium_type("2xWS");
	board_squares[4][4].setPremium_type("2xWS"); board_squares[10][10].setPremium_type("2xWS"); board_squares[11][11].setPremium_type("2xWS");
	board_squares[12][12].setPremium_type("2xWS"); board_squares[13][13].setPremium_type("2xWS"); board_squares[14][14].setPremium_type("2xWS");
	board_squares[1][13].setPremium_type("2xWS"); board_squares[2][12].setPremium_type("2xWS"); board_squares[3][11].setPremium_type("2xWS");
	board_squares[4][10].setPremium_type("2xWS"); board_squares[13][1].setPremium_type("2xWS"); board_squares[12][2].setPremium_type("2xWS");
	board_squares[11][3].setPremium_type("2xWS"); board_squares[10][4].setPremium_type("2xWS");
	//Light Blue squares
	board_squares[3][0].setPremium_type("2xLS"); board_squares[11][0].setPremium_type("2xLS"); board_squares[6][2].setPremium_type("2xLS");
	board_squares[8][2].setPremium_type("2xLS"); board_squares[0][3].setPremium_type("2xLS"); board_squares[7][3].setPremium_type("2xLS");
	board_squares[14][3].setPremium_type("2xLS"); board_squares[2][6].setPremium_type("2xLS"); board_squares[6][6].setPremium_type("2xLS");
	board_squares[8][6].setPremium_type("2xLS"); board_squares[12][6].setPremium_type("2xLS"); board_squares[3][7].setPremium_type("2xLS");
	board_squares[11][7].setPremium_type("2xLS"); board_squares[2][8].setPremium_type("2xLS"); board_squares[6][8].setPremium_type("2xLS");
	board_squares[8][8].setPremium_type("2xLS"); board_squares[12][8].setPremium_type("2xLS"); board_squares[0][11].setPremium_type("2xLS");
	board_squares[7][11].setPremium_type("2xLS"); board_squares[14][11].setPremium_type("2xLS"); board_squares[6][12].setPremium_type("2xLS");
	board_squares[8][12].setPremium_type("2xLS"); board_squares[3][14].setPremium_type("2xLS"); board_squares[11][14].setPremium_type("2xLS");
	//Blue squares
	board_squares[5][1].setPremium_type("3xLS"); board_squares[9][1].setPremium_type("3xLS"); board_squares[1][5].setPremium_type("3xLS");
	board_squares[5][5].setPremium_type("3xLS"); board_squares[9][5].setPremium_type("3xLS"); board_squares[13][5].setPremium_type("3xLS");
	board_squares[1][9].setPremium_type("3xLS"); board_squares[5][9].setPremium_type("3xLS"); board_squares[9][9].setPremium_type("3xLS");
	board_squares[13][9].setPremium_type("3xLS"); board_squares[5][13].setPremium_type("3xLS"); board_squares[9][13].setPremium_type("3xLS");
	//======================================================================================================================================
}

//Gets a Square from a board
Square Board::getSquare(int row, int col){
	return board_squares[row][col];
}