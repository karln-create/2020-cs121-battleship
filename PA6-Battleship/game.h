/*
	Contains the functions that are used to execute the core game, such as:

*/
#include "main.h"

// THE CORE GAME ------------------------------------------------------------------------
// Resets the global gameboard (seen by the players).
void prep_set_arrays();

// Print out the global gameboard. TO-DO: OBFUSCATE P2'S BOARD.
void print_gameboard();

// **************************************************************************************
// Execute the coregame (turn based shooting).
void core_game();

// Bring all functions together to set up the pregamne boards.
void pre_game(struct ship P1_Fleet[], struct ship P2_Fleet[],
										char P1_board[][10], char P2_board[][10]);

// Calculate statistics for all players.
void post_game();

//***************************************************************************************


// Update the global gameboard.
void update_gameboard(char board[][10]);

// DEBUGGER: UPDATE BOARD FOR P2. TO BE DELETED ONCE DONE.
void update_gameboard_P2(char board[][10]);

void print_board(char board[][10]);
