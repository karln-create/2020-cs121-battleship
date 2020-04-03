#ifndef MAINHEADER_H
#define MAINHEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board-func.h"

// GLOBAL ARRAYS -----------------------------------------------------------------------------------------------------------
// are shared across all files in the program.
extern char g_label[1][22], g_gameboard[10][21];

// RESETS THE GAMEBOARD --------------------------------------------------------------------------------------------------
// for a new game.
void prep_set_arrays();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// PRINTS THE GAMEBOARD.
void print_gameboard();

// EXECUTES COREGAME.
void core_game();

// UPDATE THE GAMEBOARD.
void update_gameboard(char board[][10]);

// DEBUGGER: UPDATE BOARD FOR P2. TO BE DELETED ONCE DONE.
void update_gameboard_P2(char board[][10]);

// DEFINE THE struct ship{} Ship.
typedef struct ship {
	char type;
	int length;
	int row;
	int column;
	char orientation;
} Ship;

#endif