#include "mainheader.h"

void prep_set_arrays()
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
			g_gameboard[i][j] = '~';
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

void core_game()
{
	// declares and intializes one array board for each player.
	int P1_board[10][10] = { 0 }, P2_board[10][10] = { 0 };


}

