#include "mainheader.h"

void set_arrays(int _label[][22], char gameboard[][21])
{
	int i = 0, j = 0;
	for (; i < 22; i++, j++)
	{
		_label[0][i] = j;
		if (i == 10)
			j = -1;		//sets to -1 so that when the loops go back, 1 is added to j and becomes 0.
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 21; j++)
		{
			gameboard[i][j] = '~';
			if (j == 10)
				gameboard[i][j] = '|';
		}
	}
}

void print_gameboard(int _label[][22], char gameboard[][21])
{
	system("cls");
	int i = 0, j = 0;
	for (; i < 22; i++, j++)
	{
		printf("%2d ", _label[0][i]);
	}
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		printf("%2d", _label[0][i + 1]);
		for (j = 0; j < 21; j++)
		{
			printf(" %2c", gameboard[i][j]);
		}
		printf("\n");
	}
}

void core_game(char gameboard[][21])
{
	int
}