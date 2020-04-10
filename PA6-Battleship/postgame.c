#include "root.h"

void post_game(struct player p1, struct player p2)
{
	p1.ratio = get_ratio(p1.hits, p1.misses);
	p2.ratio = get_ratio(p2.hits, p2.misses);

	printf("PLAYER STATISTICS\t:\tPLAYER 1\t\t\tPLAYER 2");
	printf("\n\ttotal shots\t:\t%d\t\t\t\t%d", p1.shots, p2.shots);
	printf("\n\ttotal hits\t:\t%d\t\t\t\t%d", p1.hits, p2.hits);
	printf("\n\ttotal misses\t:\t%d\t\t\t\t%d", p1.misses, p2.misses);
	printf("\n\thits/misses\t:\t%lf%%\t\t\t%lf%%", p1.ratio, p2.ratio);
	if(p1.status == WIN)
		printf("\n\t\t\t\t%s\t\t\t\t%s", "WIN", "LOSS");
	else
		printf("\n\t\t\t\t%s\t\t\t\t%s", "LOSS", "WIN");
}


double get_ratio(int hits, int misses)
{
	return 100 * ((double)hits / misses);
}