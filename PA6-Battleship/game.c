#include "root.h"

void prep_board()
{
	int i = 0, j = 0;
	for (; i < 22; i++, j++)
	{
		g_label[0][i] = j;
		if (i == 10)
			j = -1; //sets to -1 so that when the loops go back, 1 is added to j and j is reset 0.
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 21; j++)
		{
			g_gameboard[i][j] = '.';
			if (j == 10)
				g_gameboard[i][j] = '|';
		}
	}
}

void print_gameboard()
{
	system("cls");
	printf("\tPLAYER 1\t\t\t\tPLAYER2\n");
	int i = 0, j = 0;
	for (; i < 22; i++, j++)
	{
		printf("%2d ", g_label[0][i]);
	}
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		printf("%2d", g_label[0][i + 1]);
		for (j = 0; j < 21; j++)
		{
			printf(" %2c", g_gameboard[i][j]);
		}
		printf("\n");
	}
}

//void fechof_gameboard(FILE* outfile, int turn)
//{
//	fprintf(outfile, "\nTURN #%d:\tPLAYER 1:\t\t\tPLAYER2:\n", turn);
//	int i = 0, j = 0;
//	for (; i < 22; i++, j++)
//	{
//		fprintf(outfile, "%2d ", g_label[0][i]);
//	}
//	fprintf(outfile, "\n");
//
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(outfile, "%2d", g_label[0][i + 1]);
//		for (j = 0; j < 21; j++)
//		{
//			fprintf(outfile, " %2c", g_gameboard[i][j]);
//		}
//		fprintf(outfile, "\n");
//	}
//}
//
//void fechof(file *stream, const char *format, ...)
//{
//	va_list args;
//	va_start(args, format);
//	vfprintf(stream, format, args);
//	va_end(args);
//}

void get_coordinate(int* row, int* col)
{
	printf("\tPlease select an available coordinate [row][col]: ");
	scanf(" %d %d", row, col);
}

void core_game(struct player* p1, struct player* p2,
	char P1_board[][10], char P2_board[][10], FILE* outfile)
{
	char ship_letters[] = { 'c', 'C', 'b', 'B', 'r', 'R', 's', 'S', 'd', 'D' };
	sort_merge(ship_letters, 0, (sizeof(ship_letters) / (sizeof(*ship_letters))) - 1);

	int all_hit = 17, num_hit = 0, num_miss = 0;	//		misses	hits	shots
	int players_hitcheck[2][3] = { 0 };				//	p1	[0]		[0]		[0]
	int winflag = 0;								//	p2	[0]		[0]		[0]

	// Flip a coin to determine which player goes first. P1: 0, P2: 1.
	int coin = flipcoin();

	// Call function to set up the gameboard.
	pre_game(p1->fleet, p2->fleet, P1_board, P2_board);

	int turn = 0;

	while (winflag == 0)
	{
		// Start MANUAL turn for P1.
		if (coin == 0)
		{
			++turn;
			print_gameboard();
			printf("THIS IS TURN #%d:\n", turn);
			turn_MANUAL(P2_board, ship_letters, players_hitcheck, &turn, outfile);
			//turn_RANDOM(P2_board, ship_letters, players_hitcheck);
			turn_RANDOM(P1_board, ship_letters, players_hitcheck, &turn, outfile);
			print_gameboard();
		}
		// Start RANDOM turn for P2.
		else
		{
			++turn;
			turn_RANDOM(P1_board, ship_letters, players_hitcheck, &turn, outfile);
			print_gameboard();
			printf("THIS IS TURN #%d:\n", turn);
			turn_MANUAL(P2_board, ship_letters, players_hitcheck, &turn, outfile);
			//turn_RANDOM(P2_board, ship_letters, players_hitcheck);
			print_gameboard();
		}

		if (players_hitcheck[0][1] == all_hit)
		{
			winflag = 1;
			printf("\n\tPLAYER 1 WON!\n\n");
			p1->misses = players_hitcheck[0][0];
			p1->hits   = players_hitcheck[0][1];
			p1->shots  = players_hitcheck[0][2];
			p2->misses = players_hitcheck[1][0];
			p2->hits   = players_hitcheck[1][1];
			p2->shots  = players_hitcheck[1][2];
			p1->status = 1;
			p2->status = 0;
		}
		else if (players_hitcheck[1][1] == all_hit)
		{
			winflag = 1;
			printf("\n\tPLAYER 2 WON!\n\n");
			p1->misses = players_hitcheck[0][0];
			p1->hits   = players_hitcheck[0][1];
			p1->shots  = players_hitcheck[0][2];
			p2->misses = players_hitcheck[1][0];
			p2->hits   = players_hitcheck[1][1];
			p2->shots  = players_hitcheck[1][2];
			p2->status = 1;
			p1->status = 0;
		}
	}
}

void turn_MANUAL(char player_board[][10], char ship_letters[], int players_hitcheck[][3], int* turn, FILE* outfile)
{
	int i, r, c, found = 0, key = 0;

	// Check for Hit/Miss using Linear-Search.
	while (found != 1)
	{
		// Ask P1 for a coordinate on the board.
		get_coordinate(&r, &c);
		if (r < 1 || r > 10 || c < 1 || c > 10)
		{
			printf("\tWRONG INPUT. OUTSIDE OF GAMEBOARD.\n");
		}

		else
		{
			key = player_board[r - 1][c - 1];
			if (player_board[r - 1][c - 1] == 42 || player_board[r - 1][c - 1] == 109)
			{
				printf("PREVIOUSLY PICKED. CHOOSE ANOTHER LOCATION!\n");
				found = 0;
			}
			else if (player_board[r - 1][c - 1] == 46)
			{
				found = 1;
				player_board[r - 1][c - 1] = 109;
				++players_hitcheck[0][0];
				++players_hitcheck[0][2];
				break;
			}
			else
			{
				for (i = 0; i < MAX_SHIP_TABLE; ++i)
				{
					if (key == ship_letters[i] || ship_letters[i] == key + 32)
					{
						found = 1;
						++players_hitcheck[0][1];
						++players_hitcheck[0][2];
						player_board[r - 1][c - 1] = 42;
						break;
					}
				}
			}
		}
	}

	fprintf(outfile, "TURN #%2d, P1 [%2d][%2d]\n", *turn, r, c);
	update_gameboard_P2(player_board);
}

void turn_RANDOM(char player_board[][10], char ship_letters[], int players_hitcheck[][3], int* turn, FILE* outfile)
{
	int i, r, c, key = 0, found = 0;

	while (found != 1)
	{
		r = randomize_0thru9();
		c = randomize_0thru9();

		key = player_board[r][c];

		if (player_board[r][c] == 42 || player_board[r][c] == 109)
		{
			found = 0;
		}
		else if (player_board[r][c] == 46)
		{
			found = 1;
			player_board[r][c] = 109;
			++players_hitcheck[1][0];
			++players_hitcheck[1][2];
			break;
		}
		else
		{
			for (i = 0; i < MAX_SHIP_TABLE; ++i)
			{
				if (key == ship_letters[i] || ship_letters[i] == key + 32)
				{
					found = 1;
					++players_hitcheck[1][1];
					++players_hitcheck[1][2];
					player_board[r][c] = 42;
					break;
				}
			}
		}
	}

	fprintf(outfile, "TURN #%2d, P2 [%2d][%2d]\n", *turn, r + 1, c + 1);
	update_gameboard(player_board);
}

void update_gameboard(char board[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			g_gameboard[i][j] = board[i][j];
		}
	}
}

void update_gameboard_P2(char board[][10])
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (board[i][j] == 'm' || board[i][j] == '*')
				g_gameboard[i][11 + j] = board[i][j];
			else
				g_gameboard[i][11 + j] = '.';
		}
	}
}