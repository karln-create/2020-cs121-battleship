/*
	Contains the functions that are used to set up the individual boards, such as:
	- initializing the individual boards (invisible boards, not seen by the players).
	- determining which player goes first.
	- placing ships on the board manually (P1).
	- placing ships on the board randomly (P2, i.e. bot).
*/
#include "main.h"

// PRE-PREGAME SETUP. ******************************************************************
// Initializies a player's board of size 10x10.
void initialize_board(char board[][10]);

// Flips a coin to get Head or Tail.
// Can be used to determine which player goes first, and also recycled elsewhere.
int flipcoin(void);

// SHIP PLACEMENT FOR P1. ---------------------------------------------------------------
// Lets P1 place their ships on the board manually.
void manually_place_ship_on_board(char board[][10], struct ship* a_ship);

// SHIP PLACE FOR P2 (bot). -------------------------------------------------------------
// randomizes and returns a single number between 0 and 9 inclusively.
int randomize_0thru9(void);
// RANDOMLY SHIP PLACEMENTS FOR P2.
void randomly_place_ship_on_board(char board[][10], struct ship* a_ship);

// COLLISION CHECKING (USED FOR BOTH PLAYERS). ------------------------------------------
// Check for collision HORIZONTALLY.
int collision_chk_HORZ(char board[][10], struct ship* a_ship);
// Check for collision VERTICALLY.
int collision_chk_VERT(char board[][10], struct ship* a_ship);

// SHIP PLACEMENT METHODS (USED FOR BOTH PLAYERS). --------------------------------------
// Place the ship HORIZONTALLY.
void place_ship_HORZ(char board[][10], struct ship* a_ship);
// Place the ship VERTICALLY.
void place_ship_VERT(char board[][10], struct ship* a_ship);

// TIE ALL FUNCTIONS TOGETHER FOR PREGAME SET UP ****************************************
// Bring all functions together to set up the pregamne boards.
void pre_game(struct ship P1_Fleet[], struct ship P2_Fleet[],
	char P1_board[][10], char P2_board[][10]);

