#ifndef MAINHEADER_H
#define MAINHEADER_H
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <string.h>

// DO ONLY ONCE. Set values for the gameboard.
void set_arrays(int _label[][22], char gameboard[][21]);

// PRINT the gameboard on-demand.
void print_gameboard(int _label[][22], char gameboard[][21]);

// EXECUTES COREGAME.
void core_game(char gameboard[][21]);








#endif