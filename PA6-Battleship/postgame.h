/*
	Contains the functions that are used to calculate players statistics.
*/
// Calculate statistics for all players.
void post_game(struct player* p1, struct player* p2);

// Calculate accuracy ratio
double get_ratio(int hits, int misses);

// Echo statistics into log file.
void fechof_postgame(struct player* p1, struct player* p2, FILE* outfile);
