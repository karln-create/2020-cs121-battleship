#include "main.h"

void prep_board()
{
	int i = 0, j = 0;
	for (; i < 22; i++, j++)
	{
		g_label[0][i] = j;
		if (i == 10)
			j = -1;		//sets to -1 so that when the loops go back, 1 is added to j and j is reset 0.
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

void get_coordinate(int* row, int* col)
{
	printf("\tPlease select an available coordinate [row][col]: ");
	scanf(" %d %d", row, col);
}

void core_game(struct ship P1_Fleet[], struct ship P2_Fleet[],
									char P1_board[][10], char P2_board[][10])
{
	// Flip a coin to determine which player goes first.
	int coin = flipcoin();
	int all_hit = 17, num_hit = 0, num_miss = 0;
	// IF coin == 0 THEN turn: P1.
	// IF coin == 1 THEN turn: P2.

	// Call function to set up the gameboard.
	pre_game(P1_Fleet, P2_Fleet, P1_board, P2_board);

	// Start MANUAL turn by P1.
	num_hit = turn_MANUAL(P2_board, P2_Fleet);

	// Start RANDOM turn by P2.
	// turn_RANDOM
}

int turn_MANUAL(char player_board[][10], struct ship player_Fleet[])
{
	int hit = 0, r, c;
	char check_ship[] = { 'c', 'C', 'b', 'B', 'r', 'R', 's', 'S', 'd', 'D' };

	// Ask P1 for a coordinate on the board.
	get_coordinate(&r, &c);

	for (int i = 0; i < sizeof(check_ship) / sizeof(check_ship[0]); i++)
	{
		if (player_board[r - 1][c - 1] == check_ship[i])
		{
			// count a successful hit.
			hit++;
			// check for the type of ship damaged.

		}
	}

	return hit;
}

int turn_RANDOM(char player_board[][10], struct ship player_Fleet[])
{
	int hit = 0;

	return hit;
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
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			g_gameboard[i][11 + j] = board[i][j];
		}
	}
}

void print_board(char board[][10])
{
	printf("\n");
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
			printf(" %c ", board[i][j]);
		printf("\n");
	}
}