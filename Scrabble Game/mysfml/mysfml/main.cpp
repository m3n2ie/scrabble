#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Board.h"
#include "Bag.h"
#include "Dictionary.h"
#include <ctime>

using namespace sf;

int main(){
	//==========Setup Starts=====================

	//Loads font and sets text for displaying score and turns
	Font font;
	Text p1_score_text, p2_score_text, turn_text;
	if (font.loadFromFile("fonts/comic.ttf")){
		p1_score_text.setFont(font); p1_score_text.setString("0");
		p1_score_text.setFillColor(Color::Magenta); p1_score_text.setPosition(25, 179);
		p2_score_text.setFont(font); p2_score_text.setString("0");
		p2_score_text.setFillColor(Color::Magenta); p2_score_text.setPosition(750, 179);
		turn_text.setFillColor(Color::Cyan); turn_text.setPosition(357, 0);
		p1_score_text.setString("0"); p2_score_text.setString("0");
		turn_text.setFont(font); turn_text.setCharacterSize(15); turn_text.setString("Player one's turn");
	}
	else
		std::cout << "Couldn't load font";

	//Board background images
	Texture board_texture, d_menu_texture, p_menu_texture, l_menu_texture, e_menu_texture;
	if (!board_texture.loadFromFile("images/the_board.png") || !d_menu_texture.loadFromFile("images/menu_default.png")
		|| !p_menu_texture.loadFromFile("images/menu_play.png") || !l_menu_texture.loadFromFile("images/menu_load.png")
		|| !e_menu_texture.loadFromFile("images/menu_exit.png"))
		std::cout << "Texture didn't load";
	Sprite background(board_texture), d_menu(d_menu_texture), p_menu(p_menu_texture), l_menu(l_menu_texture),e_menu(e_menu_texture);

	bool in_menu = true; //stores the states (whether it's on menu or not)
	string selected = ""; //stores the selected menu option
	int turn = 1; //stores played 
	//Dictionary dictionary;
	Board board;//The playing board
	Bag bag;//Bag with tiles
	struct TileOnRack{Tile t;Vector2f t_pos;};//Store tiles and default position on rack
	Player player1(1);//Player 1
	Player player2(2);//Palyyer 2
	std::vector <TileOnRack> player1_rack(7);//Rack for player 1
	std::vector <TileOnRack> player2_rack(7);//Rack for player 2
	std::vector <Texture> tiles_textures(100);//Stores tile textures
	std::vector <Sprite> tiles_sprites(100);//Stores tile sprites
	std::vector <Tile> tiles(100);//Stores tiles
	Tile tile;//Temporarily holds a tile
	TileOnRack tile_on_rack;//To temporarily hold a tile to be putted on rack
	int tile_id=0;//To identify every tile played (Also used as a counter)
	std::vector<bool> tile_drag(100);//Drag status for all 100 tiles that can be placed on board
	string played_word="";
	char played_letters[15][15];//stores played letters
	for (int i = 0; i < 15; i++){//stores a non alphabet (invalid) character to all played letters array
		for (int j = 0; j < 15; j++)
			played_letters[i][j] = '-';
	}
	//Puts tiles on rack for player 1 and 2
	for (int i = 0; i < 7; i++){//Puts tiles on players racks
		tile = bag.pickTile(); //randomly picks tile from bag
		tile.id = tile_id;
		tile_on_rack.t = tile;
		tile.setPlayer(player1);
		std::cout << "Tile id: "<<tile.id<<endl;
		tiles.at(i) = tile;
		tile_drag.at(tile.id) = false; //set drag status of tile to false
		tiles_textures.at(i).loadFromFile("images/tiles/"+bag.getTile_img(tile));
		tiles_sprites.at(i).setPosition(35, 310 + i * 37); //sets tile position on the rack
		tile_on_rack.t_pos = tiles_sprites.at(i).getPosition();
		player1_rack.at(i) = tile_on_rack; //puts tile on rack
		tiles_sprites.at(i).setTexture(tiles_textures.at(i));
		tile_id++;

		tile = bag.pickTile();//same logic as above but for player 2
		tile.id = tile_id;
		tile_on_rack.t = tile;
		tile.setPlayer(player2);
		std::cout << "Tile id: " << tile.id << endl; 
		tiles.at(i + 7) = tile;
		tile_drag.at(tile.id+7) = false;
		tiles_textures.at(i+7).loadFromFile("images/tiles/" + bag.getTile_img(tile));
		tiles_sprites.at(i+7).setPosition(765, 310 + i * 37);
		tile_on_rack.t_pos = tiles_sprites.at(i+7).getPosition();
		player2_rack.at(i) = tile_on_rack;
		tiles_sprites.at(i+7).setTexture(tiles_textures.at(i+7));
		tile_id++;
	}

	RenderWindow window(VideoMode(833 , 680), "Scrabble", Style::Titlebar);
	//==================Setup Ends=======================

	//==================Game Loop========================
	while (window.isOpen()){
	Event event;
	while (window.pollEvent(event)){
		if (event.type == Event::Closed){
			window.close();
		}

		//====================================Menu=====================================
		//Play menu option selected
		if (Mouse::getPosition(window).x > 163 && Mouse::getPosition(window).y > 190 &&
			Mouse::getPosition(window).x < 667 && Mouse::getPosition(window).y < 271 &&in_menu){
			selected = "play";
			if (Mouse::isButtonPressed(Mouse::Left))
				in_menu = false;
		}
		//Load Previous Game menu option selected
		else if (Mouse::getPosition(window).x > 163 && Mouse::getPosition(window).y > 301 &&
			Mouse::getPosition(window).x < 667 && Mouse::getPosition(window).y < 382 && in_menu){
			selected = "load";
		}
		//Exit menu option selected
		else if (Mouse::getPosition(window).x > 163 && Mouse::getPosition(window).y > 408 &&
			Mouse::getPosition(window).x < 667 && Mouse::getPosition(window).y < 489 && in_menu){
			selected = "exit";
			if (Mouse::isButtonPressed(Mouse::Left)){
				try{
					return 0;
				}
				catch (const std::exception& a){
					std::cout << a.what(); return EXIT_FAILURE;
				}
			}
		}
		else{
			selected = "";
		}
		//================================================================================

		//---------tile grad and drop----------------
		for (int i = 0; i < 100; i++)
			if (tile_drag.at(i)){
				tiles_sprites[i].setPosition(Mouse::getPosition(window).x - 15/*30*/, Mouse::getPosition(window).y - 16/*32*/);
			}
					
			
		//Checks if mouse clicks the tile 
		for (int i = 0; i < 100; i++){//Checks using tile bounds
			if (((tiles_sprites[i].getPosition().x <= Mouse::getPosition(window).x
				&& tiles_sprites[i].getPosition().y <= Mouse::getPosition(window).y))
				&& (tiles_sprites[i].getPosition().x + 30 >= Mouse::getPosition(window).x
				&& tiles_sprites[i].getPosition().y + 32 >= Mouse::getPosition(window).y)){
				if (Mouse::isButtonPressed(Mouse::Left)){
					if (!tile_drag.at(i)){
						tile_drag.at(i) = true;
						for (int j = 0; j < 100; j++){
							if (j != i)
								tile_drag.at(j) = false;//Ensures that no more than 1 tile is dragged
						}
					}
					else
						tile_drag.at(i) = false;
				}
			}
		}
		//---------------------------------------------
		//std::cout <<"x:" << Mouse::getPosition(window).x<<" y:"<<Mouse::getPosition(window).y<<"\n";

		//This is just for debugging (Detects the square touched by mouse)
		for (int i = 0; i < 15; i++){
			for (int j = 0; j < 15; j++){//Uses square bounds to detect
				if ((Mouse::getPosition(window).x > board.getSquare(i, j).get_x1())&&
					(Mouse::getPosition(window).y > board.getSquare(i, j).get_y1()) &&
					(Mouse::getPosition(window).x < board.getSquare(i, j).get_x2()) &&
					(Mouse::getPosition(window).y < board.getSquare(i, j).get_y2())){
					if (!in_menu)
					std::cout << "Mouse inside square " << i+1 << " , " << static_cast<char>(65+j)<<"\n";
					}
			}
		}

		//Goes to the Menu when the 'menu' button is pressed
		if (Keyboard::isKeyPressed(Keyboard::Menu)){
			if (in_menu)
				in_menu = false;
			else
				in_menu = true;
		}

		//Executes when the 'spacebar' is pressed to play a word
		if (Keyboard::isKeyPressed(Keyboard::Space)&&!in_menu){
			ofstream saved_game("saved_game.dat"); //saves game state to a file
			for (int t = 0; t < 100; t++){ //iterates through all possible picked tiles (100 is MAX)
				for (int i = 0; i < 15; i++){ //Searches board rows for tile
					for (int j = 0; j < 15; j++){//Searches board columns for tile
						//Uses tile and square bound to detect if tile is inside the square
						if ((tiles_sprites.at(t).getPosition().x > board.getSquare(i, j).get_x1()) &&
							(tiles_sprites.at(t).getPosition().y > board.getSquare(i, j).get_y1()) &&
							(tiles_sprites.at(t).getPosition().x < board.getSquare(i, j).get_x2()) &&
							(tiles_sprites.at(t).getPosition().y < board.getSquare(i, j).get_y2())){
							board.getSquare(i, j).placeTile(tiles.at(t));//Places tile on board
							played_word += tiles.at(t).getLetter();
							for (int k = 0; k < 7; k++){//For each tile on player 1 or 2 rack
								if (tiles.at(t).getPlayer().getId() == 1){
									if (tiles.at(t).id == player1_rack.at(k).t.id){
										tile_id++;
										tile = bag.pickTile();//randomly picks new tile
										tile.setPlayer(player1);
										tiles.at(tile_id) = tile;
										std::cout << "\nTile id: " << tile_id;
										tile.id = tile_id;
										tile_drag.at(tile.id) = false;
										tiles_textures.at(tile_id).loadFromFile("images/tiles/" + bag.getTile_img(tile));
										tiles_sprites.at(tile_id).setPosition(player1_rack.at(k).t_pos);
										tiles_sprites.at(tile_id).setTexture(tiles_textures.at(tile_id));
										player1_rack.at(k).t = tile; //places tile in player rack
										
									}
								}
								else if (tiles.at(t).getPlayer().getId() == 2){//Same logic as above for player 2
									if (tiles.at(t).id == player2_rack.at(k).t.id){
										tile_id++;
										tile = bag.pickTile();
										tile.setPlayer(player2);
										tiles.at(tile_id) = tile;
										std::cout << "\nTile id: " << tile_id;
										tile.id = tile_id;
										tile_drag.at(tile.id) = false;
										tiles_textures.at(tile_id).loadFromFile("images/tiles/" + bag.getTile_img(tile));
										tiles_sprites.at(tile_id).setPosition(player2_rack.at(k).t_pos);
										tiles_sprites.at(tile_id).setTexture(tiles_textures.at(tile_id));
										player2_rack.at(k).t = tile;
									}
								}
							}
							
							played_letters[i][j] = tiles.at(t).getLetter();//adds played tiles

							if (turn == 1){//alternates player turns
								turn = 2;
								turn_text.setString("Player two's turn");
							}
							else{
								turn = 1;
								turn_text.setString("Player one's turn");
							}
							//std::cout << "Tile "<<tiles.at(t).getLetter()<<" inside square " << i + 1 << " , " << static_cast<char>(65 + j) <<endl;
						}
					}
				}

			}

			//Saves board state after each played
			for (int i = 0; i < 15; i++){
				played_word = "";
				for (int j = 0; j < 15; j++){
					if (played_letters[i][j] != '-'){
						played_word += played_letters[i][j];
					}else{
						played_word += "-";
					}
				}
				std::cout << "Board: " << played_word << endl;
				saved_game << played_word<<endl;
			}

		}
		}

		//-------------------------------Game Graphics Drawing--------------------------
		window.clear();//clears window before drawing again
		if (!in_menu){ //checks if game is on menu or not
			window.draw(background);//draws background image (the board)
			for (int i = 0; i < 100; i++)//iterates through all possible tiles
				window.draw(tiles_sprites[i]);//draws tiles on the game
			window.draw(p1_score_text);//draws score for player 1
			window.draw(p2_score_text);//draws score for player 2
			window.draw(turn_text);//draws text for player turns
			window.setTitle("Scrabble                                            <<<<<Press 'menu' button for Menu (between 'left-alt' & 'left-ctrl')>>>>>");
		}
		else{//Check if menu options are selected
			if (selected == "play")
				window.draw(p_menu);
			else if (selected == "load")
				window.draw(l_menu);
			else if (selected == "exit")
				window.draw(e_menu);
			else
				window.draw(d_menu);
			in_menu = true;
			window.setTitle("Scrabble");
		}
		window.display();//display the window
		//-------------------------------------------------------------------------------
	}
	//==========================================================
	return 0;
}