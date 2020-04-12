#ifndef MAIN_H
#define MAIN_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include "pregame.h"
#include "game.h"
#include "postgame.h"
#include "search_sort.h"

// **************************************************************************************

// DECLARE GLOBAL PARAMETERS ------------------------------------------------------------

// DEFINE a constant from the maximum dimension of the square board.
#define MAX_BOARD_DIM 10
#define MAX_SHIP_TABLE 10
// DEFINE global arrays for the displayed gameboard (seen by players).
extern char g_label[1][22],
g_gameboard[10][21];

// DEFINE the structure ship{} with some inherent characteristics.
typedef struct ship {
	char alias[11],		// the alias of the ship.
		type,			// the type of ship.
		orientation;	// whether it is place HORZ or VERT.
	int length,			// its maximum length.
		row,			// its <row> coordinate.
		col;			// its <column> coordinate.
} Ship;

// DEFINE the structure player_stats{}
typedef struct player {
	int misses,
		hits,
		shots;
	double ratio;
	Ship fleet[5];
	enum victory status;
} Player;

typedef enum victory {
	LOSS, WIN
} Victory;
// **************************************************************************************

#endif