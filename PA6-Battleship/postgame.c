#include "root.h"

void post_game(struct player *p1, struct player *p2)
{
	p1->ratio = get_ratio(p1->hits, p1->shots);
	p2->ratio = get_ratio(p2->hits, p2->shots);

	printf("PLAYER STATISTICS\t:\tPLAYER 1\t\t\tPLAYER 2");
	printf("\n\ttotal shots\t:\t%d\t\t\t\t%d", p1->shots, p2->shots);
	printf("\n\ttotal hits\t:\t%d\t\t\t\t%d", p1->hits, p2->hits);
	printf("\n\ttotal misses\t:\t%d\t\t\t\t%d", p1->misses, p2->misses);
	printf("\n\thits/misses\t:\t%lf%%\t\t\t%lf%%", p1->ratio, p2->ratio);
	if(p1->status == WIN)
		printf("\n\t\t\t\t%s\t\t\t\t%s", "WIN", "LOSS");
	else
		printf("\n\t\t\t\t%s\t\t\t\t%s", "LOSS", "WIN");
}


double get_ratio(int hits, int shots)
{
	return 100 * ((double)hits / shots);
}

void fechof_postgame(struct player *p1, struct player *p2, FILE *outfile)
{
	fprintf(outfile, "\n\n");
	fprintf(outfile, "\nPLAYER STATS\t,\tPLAYER 1\t,\t\tPLAYER 2");
	fprintf(outfile, "\ntotal shots\t\t,\t%d\t\t\t,\t\t%d", p1->shots, p2->shots);
	fprintf(outfile, "\ntotal hits\t\t,\t%d\t\t\t,\t\t%d", p1->hits, p2->hits);
	fprintf(outfile, "\ntotal misses\t,\t%d\t\t\t,\t\t%d", p1->misses, p2->misses);
	fprintf(outfile, "\nHits/misses\t\t,\t%.2lf%%\t\t,\t\t%.2lf%%", p1->ratio, p2->ratio);
	if (p1->status == WIN)
		fprintf(outfile,"\n\t\t\t\t\t%s\t\t\t,\t\t%s", "WIN", "LOSS");
	else
		fprintf(outfile, "\n\t\t\t\t\t%s\t\t\t,\t\t%s", "LOSS", "WIN");

}