#ifndef MAINHEADER_H
#define MAINHEADER_H
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// GLOBAL ARRAYS -----------------------------------------------------------------------------------------------------------
// are shared across all files in the program.
extern int g_label[1][22], g_gameboard[10][21];

// PREPARES THE GAMEBOARD --------------------------------------------------------------------------------------------------
// is used only ONCE.
void prep_set_arrays();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// PRINTS THE GAMEBOARD ON-DEMAND.
void print_gameboard();

// EXECUTES COREGAME.
void core_game();








#endif