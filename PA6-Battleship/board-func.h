#include "mainheader.h"


// INTITIALIZES A BOARD
void initialize_board(char board[][10]);

// DETERMINES RANDOMLY WHICH PLAYER GOES FIRST.
void select_who_starts_first(int* player_turn);

// LETS P1 MANUALLY PLACE THEIR SHIPS ON THE BOARD.
void manually_place_ship_on_board(char board[][10], char ship_type, int* ship_length);

// PLACE THE SHIP HORIZONTALLY.
char place_ship_horizontally(char board[][10], char ship_type, int* ship_length,
	int* row, int* column, char* orientation, int* flag);

// PLACE THE SHIP VERTICALLY.
char place_ship_vertically(char board[][10], char ship_type, int* ship_length,
	int* row, int* column, char* orientation, int* flag);