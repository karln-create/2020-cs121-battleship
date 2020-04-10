/*
	NAME: KARL NORDEN | CLASS: CPTS 121, SECTION 17
	DESCRIPTION: BUILD A BATTLESHIP GAME IN C.
				Refer to README.md for more information and complete program development.
*/
#include "root.h"

// declares and intializes global arrays for the displayed gameboard.
char g_label[1][22] = {0}, g_gameboard[10][21] = {0};


void welcome_screen();

int main(void)
{
	FILE* outfile = NULL;
	outfile = fopen("battleship.log", "r");

	// Set the seed for the randomizer.
	srand((unsigned int)time(NULL));

	// ship type: type, orientation, length, row, col
	Ship Carrier = {"", 'C', '\0', 5, 0, 0};
	Ship Battleship = {"", 'B', '\0', 4, 0, 0};
	Ship Cruiser = {"", 'R', '\0', 3, 0, 0};
	Ship Submarine = {"", 'S', '\0', 3, 0, 0};
	Ship Destroyer = {"", 'D', '\0', 2, 0, 0};

	// In the beginning both players have the same fleet, unplaced and undamaged.
	// Therefore, initialize both arrays as such.

	Ship Fleet[5] = { Carrier, Battleship, Cruiser, Submarine, Destroyer };

	Player p1, p2;

	for (int i = 0; i < 5; ++i)
	{
		p1.fleet[i] = Fleet[i];
		p2.fleet[i] = Fleet[i];
	}
	// Declare and intialize one array board for each player.
	char P1_board[10][10] = {0},
		 P2_board[10][10] = {0};

	int input = 0, flag = 1;
	while (flag)
	{
		initialize_board(P1_board);
		initialize_board(P2_board);
		welcome_screen();
		printf("\nEnter your choice: ");
		scanf("%d", &input);
		if (input == 1)
		{
			core_game(&p1, &p2, P1_board, P2_board, outfile);
			post_game(p1, p2);
		}
		else
			break;
	}

	fprintf(outfile, "PLAYER STATISTICS:\tPLAYER 1\t\t\tPLAYER 2");
	fprintf(outfile, "\ttotal shots:\t%d\t\t\t%d", p1.shots, p2.shots);
	fprintf(outfile, "\ttotal hits:\t%d\t\t\t%d", p1.hits, p2.hits);
	fprintf(outfile, "\ttotal misses:\t%d\t\t\t%d", p1.misses, p2.misses);
	fprintf(outfile, "\thits/misses:\t%lf%%\t\t\t%lf%%", p1.ratio, p2.ratio);
	if (p1.status == 1)
		fprintf(outfile, "\t\t\t\t%s\t\t\t%s", "WIN", "LOSS");
	else
		fprintf(outfile, "\t\t\t\t%s\t\t\t%s", "LOSS", "WIN");

	fclose(outfile);
	return 0;
}

void welcome_screen()
{
	printf("\n**************************************************************************************************************");
	printf("\n\tBATTLESHIP");
	printf("\n**************************************************************************************************************");
	printf("\nWELCOME TO THE GAME BATTLESHIP!");
	printf("\n\nGAME RULES: Be the first to sink all 5 of your opponent's ships!");
	printf("\n\t- You may place any ship horizontally or vertically.");
	printf("\n\t- Ships cannot overlap, i.e each cell on the gameboard can only hold a part from only one ship.");
	printf("\n\t- Ship positions cannot be changed once the game is started.");
	printf("\n\nPick a location on the board as [row][column].");
	printf("\nFor example, if you choose a [3][3], go down the rows 3 times, and go right 3 columns.");
	printf("\n\nCHOOSE AN OPTION:\t1. START A NEW GAME\n\t\t\t2. EXIT");
}