#include "board-func.h"

void initialize_board(char board[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = '.';
		}
	}
}


void manually_place_ship_on_board(char board[][10], char ship_type, int* ship_length)
{
	int row = 0, column = 0, i = 0;

	char orientation = '\0';

	while (orientation == '\0')
	{
		// Asks P1 to enter integer coordinates: (row = i, column = j).
		int flag = 0;
		while (flag == 0)
		{
			printf("Please enter a coordinate [row][column]: ");
			scanf(" %d %d", &row, &column);
			flag = 1;
			if (row > 10 || row < 0 || column > 10 || column < 0)
			{
				printf("\tINVALID. Coordinate is outside the board.\n");
				flag = 0;
			}
		}
		// Asks P1 to choose an orientiation, vertical or horizontal for the ship placement.
		printf("Do you want to place the ship vertically or horizontally? (h/v) ");
		scanf(" %c", &orientation);

		if (orientation == 'h' || orientation == 'H')
		{
			place_ship_horizontally(board, ship_type, ship_length, &row, &column, &orientation, &flag);
		}
		else if (orientation == 'v' || orientation == 'V')
		{
			place_ship_vertically(board, ship_type, ship_length, &row, &column, &orientation, &flag);
		}
		else
		{
			printf("\tINVALID orientation.\n");
			orientation = '\0';
		}
	}
}

char place_ship_horizontally(char board[][10], char ship_type, int* ship_length,
		int* row, int* column, char* orientation, int* flag)
{
	int i = 0, r = *row - 1, c = *column - 1;

	// check for collision.
	for (i = 0; i < *ship_length; i++)
	{
		if (board[r][c + i] != '.' || *column > 11 - *ship_length)		// 11 because inclusive
		{
			printf("\tCOLLISION WARNING. Location unavailable. Pick a different coordinate.\n");
			*flag = 0;
			return *orientation = '\0';
		}

	}

	// if no collision, place ship.
	if (*flag != 0)
	{
		for (i = 0; i < *ship_length; i++)
		{
			if (*column <= 11 - *ship_length)		// 11 because inclusive
			{
				board[r][c] = ship_type;
				c++;
			}
		}
	}
	return *orientation;
}


char place_ship_vertically(char board[][10], char ship_type, int* ship_length,
	int* row, int* column, char* orientation, int* flag)
{
	int i = 0, r = *row - 1, c = *column - 1;

	// check for collision.
	for (i = 0; i < *ship_length; i++)
	{
		if (board[r + i][c] != '.' || *row > 11 - *ship_length)		// 11 because inclusive
		{
			printf("\tCOLLISION WARNING. Location unavailable. Pick a different coordinate.\n");
			*flag = 0;
			return *orientation = '\0';
		}
	}

	// if no collision, place ship.
	if (*flag != 0)
	{
		for (i = 0; i < *ship_length; i++)
		{
			if (*row <= 11 - *ship_length)		// 11 because inclusive
			{

				board[r][c] = ship_type;
				r++;
			}
		}
	}
	return *orientation;
}