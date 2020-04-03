#include "mainheader.h"


// INTITIALIZES A BOARD
void initialize_board(char board[][10]);

// DETERMINES RANDOMLY WHICH PLAYER GOES FIRST.
void flipcoin(int* face);

// LETS P1 MANUALLY PLACE THEIR SHIPS ON THE BOARD.
void manually_place_ship_on_board(char board[][10], struct ship* a_ship);

// RANDOMIZE A COORDINATE.
void coordinate_randomizer(int* num);

// RANDOMLY SHIP PLACEMENTS FOR P2.
void randomly_place_ship_on_board(char board[][10], char ship_type, int ship_length);

// PLACE THE SHIP HORIZONTALLY.
char place_ship_horizontally(char board[][10], struct ship* a_ship, int* flag);

// PLACE THE SHIP VERTICALLY.
char place_ship_vertically(char board[][10], struct ship* a_ship, int* flag);