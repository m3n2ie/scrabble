#include "Bag.h"
#include <ctime>
#include <iostream>



Bag::Bag(){
	srand(time(0));
	//CREATING TILES
	const Tile tile_Blank(' ', 0),
		//tiles with value of 1
		tile_A('A', 1), tile_E('E', 1), tile_I('I', 1), tile_O('O', 1), tile_U('U', 1),
		tile_L('L', 1), tile_N('N', 1), tile_S('S', 1), tile_T('T', 1), tile_R('R', 1),
		//tiles with value of 2
		tile_D('D', 2), tile_G('G', 2),
		//tiles with value of 3
		tile_B('B', 3), tile_C('C', 3), tile_M('M', 3), tile_P('P', 3),
		//tiles with value of 4
		tile_F('F', 4), tile_H('H', 4), tile_V('V', 4), tile_W('W', 4), tile_Y('Y', 4),
		//tile with value of 5
		tile_K('K', 5),
		//tiles with value of 8
		tile_J('J', 8), tile_X('X', 8),
		//tiles with value of 10
		tile_Q('Q', 10), tile_Z('Z', 10);

	//Adding details of tile
	tile_details t_Blank; t_Blank.tile = tile_Blank; t_Blank.quantity = 2; t_Blank.img = "Blank.png";
	tile_details t_A; t_A.tile = tile_A; t_A.quantity = 9; t_A.img = "A.png";
	tile_details t_B; t_B.tile = tile_B; t_B.quantity = 2; t_B.img = "B.png";
	tile_details t_C; t_C.tile = tile_C; t_C.quantity = 2; t_C.img = "C.png";
	tile_details t_D; t_D.tile = tile_D; t_D.quantity = 4; t_D.img = "D.png";
	tile_details t_E; t_E.tile = tile_E; t_E.quantity = 12; t_E.img = "E.png";
	tile_details t_F; t_F.tile = tile_F; t_F.quantity = 2; t_F.img = "F.png";
	tile_details t_G; t_G.tile = tile_G; t_G.quantity = 3; t_G.img = "G.png";
	tile_details t_H; t_H.tile = tile_H; t_H.quantity = 2; t_H.img = "H.png";
	tile_details t_I; t_I.tile = tile_I; t_I.quantity = 9; t_I.img = "I.png";
	tile_details t_J; t_J.tile = tile_J; t_J.quantity = 1; t_J.img = "J.png";
	tile_details t_K; t_K.tile = tile_K; t_K.quantity = 1; t_K.img = "K.png";
	tile_details t_L; t_L.tile = tile_L; t_L.quantity = 4; t_L.img = "L.png";
	tile_details t_M; t_M.tile = tile_M; t_M.quantity = 2; t_M.img = "M.png";
	tile_details t_N; t_N.tile = tile_N; t_N.quantity = 6; t_N.img = "N.png";
	tile_details t_O; t_O.tile = tile_O; t_O.quantity = 8; t_O.img = "O.png";
	tile_details t_P; t_P.tile = tile_P; t_P.quantity = 2; t_P.img = "P.png";
	tile_details t_Q; t_Q.tile = tile_Q; t_Q.quantity = 1; t_Q.img = "Q.png";
	tile_details t_R; t_R.tile = tile_R; t_R.quantity = 6; t_R.img = "R.png";
	tile_details t_S; t_S.tile = tile_S; t_S.quantity = 4; t_S.img = "S.png";
	tile_details t_T; t_T.tile = tile_T; t_T.quantity = 6; t_T.img = "T.png";
	tile_details t_U; t_U.tile = tile_U; t_U.quantity = 4; t_U.img = "U.png";
	tile_details t_V; t_V.tile = tile_V; t_V.quantity = 2; t_V.img = "V.png";
	tile_details t_W; t_W.tile = tile_W; t_W.quantity = 2; t_W.img = "W.png";
	tile_details t_X; t_X.tile = tile_X; t_X.quantity = 1; t_X.img = "X.png";
	tile_details t_Y; t_Y.tile = tile_Y; t_Y.quantity = 2; t_Y.img = "Y.png";
	tile_details t_Z; t_Z.tile = tile_Z; t_Z.quantity = 1; t_Z.img = "Z.png";
	//100 tiles (in total) of different types are in the bag

	//Adding tile with details in the 'bag'
	all_tiles[0] = t_Blank; all_tiles[1] = t_A; all_tiles[2] = t_B; all_tiles[3] = t_C; all_tiles[4] = t_D;
	all_tiles[5] = t_E; all_tiles[6] = t_F; all_tiles[7] = t_G; all_tiles[8] = t_H; all_tiles[9] = t_I;
	all_tiles[10] = t_J; all_tiles[11] = t_K; all_tiles[12] = t_L; all_tiles[13] = t_M; all_tiles[14] = t_N;
	all_tiles[15] = t_O; all_tiles[16] = t_P; all_tiles[17] = t_Q; all_tiles[18] = t_R; all_tiles[19] = t_S;
	all_tiles[20] = t_T; all_tiles[21] = t_U; all_tiles[22] = t_V; all_tiles[23] = t_W; all_tiles[24] = t_X;
	all_tiles[25] = t_Y; all_tiles[26] = t_Z;
}



bool Bag::isEmpty(){
	for (int i = 0; i < 27; i++){//check all tiles in the bag
		if (all_tiles[i].quantity > 0)	//if some tile still has a duplicate left
			return false;
	}
	return true;
}


Tile Bag::pickTile(){
	random = rand()%26; //generate a random number between 0 and 26
	//std::cout <<"Random number: "<< random<<endl;
	if (all_tiles[random].quantity < 1 && !isEmpty()){//if a tile picked has no duplicates left restart the picking process
		//std::cout << "\nno duplicates left";
		pickTile();
	}
	else if(!isEmpty()){
		//decreases quantity of tiles of the picked type in the bag
		all_tiles[random].quantity = all_tiles[random].quantity - 1;
	}
	else{
		std::cout << "\n\n\nBag Empty\n\n";
		return Tile();
	}
	//std::cout << "Picked tile: " << all_tiles[random].tile.getLetter()<<endl;
	id++;
	all_tiles[random].tile.id = id;
	return all_tiles[random].tile;
}

string Bag::getTile_img(Tile t){
	for (int i = 0; i < 27; i++){
		if (all_tiles[i].tile.getLetter() == t.getLetter()){
			//std::cout << "Requested image for: " << t.getLetter() <<" got: "<<all_tiles[i].img.at(0)<<endl;
			return all_tiles[i].img;
		}
	}
	return "";
}