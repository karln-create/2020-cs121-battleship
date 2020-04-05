/*
	Contains the functions that are used to execute the core game, such as:

*/
#include "main.h"

// THE CORE GAME ------------------------------------------------------------------------
// Resets the global gameboard (seen by the players).
void prep_board();

// Print out the global gameboard. TO-DO: OBFUSCATE P2'S BOARD.
void print_gameboard();

// **************************************************************************************
// Ask P1 for coordinate [row][col].
void get_coordinate(int* row, int* col);

// Execute the coregame (turn based shooting).
void core_game(struct ship P1_Fleet[], struct ship P2_Fleet[],
									char P1_board[][10], char P2_board[][10]);

// Execute P1's turn.
int turn_MANUAL(char player_board[][10], struct ship player_Fleet[]);

// Execute P2's turn (bot).
int turn_RANDOM(char player_board[][10], struct ship player_Fleet[]);
//***************************************************************************************


// Update the global gameboard.
void update_gameboard(char board[][10]);

// DEBUGGER: UPDATE BOARD FOR P2. TO BE DELETED ONCE DONE.
void update_gameboard_P2(char board[][10]);

// DEBUGGER: print either individual board (10x10)
void print_board(char board[][10]);
