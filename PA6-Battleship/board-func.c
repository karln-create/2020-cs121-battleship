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

void flipcoin(int* face)
{
	*face = rand() % 2 + 1;
}



void manually_place_ship_on_board(char board[][10], struct ship* a_ship)
{
	int i = 0, flag = 1;
	a_ship->orientation = '\0';

	while (flag == 1)
	{
		// Asks P1 to enter integer coordinates: (row = i, column = j).
		printf("Please enter a coordinate [row][column]: ");
		scanf(" %d %d", &a_ship->row, &a_ship->column);
		if (a_ship->row > 10 || a_ship->row < 0 || a_ship->column > 10 || a_ship->column < 0)
			printf("\tINVALID. Coordinate is outside the board.\n");

		// Asks P1 to choose an orientiation, vertical or horizontal for the ship placement.
		else
		{
			flag = 0;
			while (a_ship->orientation == '\0')
			{
				printf("Do you want to place the ship vertically or horizontally? (h/v) ");
				scanf(" %c", &a_ship->orientation);
				if (a_ship->orientation == 'h' || a_ship->orientation == 'H')
				{
					place_ship_horizontally(board, a_ship, &flag);
				}
				else if (a_ship->orientation == 'v' || a_ship->orientation == 'V')
				{
					place_ship_vertically(board, a_ship, &flag);
				}
				else
				{
					printf("\tINVALID orientation.\n");
					a_ship->orientation = '\0';
				}
			}
		}
	}
}


void coordinate_randomizer(int* num)
{
	*num = rand() % 9;
}


//void randomly_place_ship_on_board(char board[][10], char ship_type, int ship_length)
//{
//	int row = -1, column = -1, flip = -1;
//	//char orientation = '\0';
//
//	while (flip == -1)
//	{
//		flipcoin(&flip);
//		if (flip == 1)
//
//	}
//
//}


char place_ship_horizontally(char board[][10], struct ship* a_ship, int* flag)
{
	int i = 0, r = a_ship->row - 1, c = a_ship->column - 1;

	// check for collision.
	for (i = 0; i < a_ship->length; i++)
	{
		if (board[r][c + i] != '.' || a_ship->column > 11 - a_ship->length)		// 11 because inclusive
		{
			printf("\tCOLLISION WARNING. Location unavailable. Pick a different coordinate.\n");
			*flag = 1;
			return a_ship->orientation = '\0';
		}

	}

	// if no collision, place ship.
	if (*flag != 1)
	{
		for (i = 0; i < a_ship->length; i++)
		{
			if (a_ship->column <= 11 - a_ship->length)		// 11 because inclusive
			{
				board[r][c] = a_ship->type;
				c++;
			}
		}
	}
	return a_ship->orientation;
}


char place_ship_vertically(char board[][10], struct ship* a_ship, int* flag)
{
	int i = 0, r = a_ship->row - 1, c = a_ship->column - 1;

	// check for collision.
	for (i = 0; i < a_ship->length; i++)
	{
		if (board[r + i][c] != '.' || a_ship->row > 11 - a_ship->length)		// 11 because inclusive
		{
			printf("\tCOLLISION WARNING. Location unavailable. Pick a different coordinate.\n");
			*flag = 1;
			return a_ship->orientation = '\0';
		}
	}

	// if no collision, place ship.
	if (*flag != 1)
	{
		for (i = 0; i < (a_ship)->length; i++)
		{
			if (a_ship->row <= 11 - a_ship->length)		// 11 because inclusive
			{

				board[r][c] = a_ship->type;
				r++;
			}
		}
	}
	return a_ship->orientation;
}