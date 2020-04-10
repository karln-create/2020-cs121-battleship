/*
	Contains the functions that are used to calculate players statistics.
*/
#include "root.h"

// Calculate statistics for all players.
void post_game(struct player p1, struct player p2);

// Calculate accuracy ratio
double get_ratio(int hits, int misses);
