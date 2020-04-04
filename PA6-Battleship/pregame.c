#include "pregame.h"

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

int flipcoin(void)
{
	return rand() % 2;
}



void manually_place_ship_on_board(char board[][10], struct ship* a_ship)
{
	int i = 0, flag = 1;
	a_ship->orientation = '\0';

	while (flag == 1)
	{
		// Asks P1 to enter integer coordinates: (row = i, col = j).
		printf("Please enter a coordinate [row][col]: ");
		scanf(" %d %d", &a_ship->row, &a_ship->col);
		flag = 0;
		if (a_ship->row > 10 || a_ship->row < 0 || a_ship->col > 10 || a_ship->col < 0)
		{
			printf("\tINVALID. Coordinate is outside the board.\n");
			flag = 1;
		}

		// Asks P1 to choose an orientiation, vertical or horizontal for the ship placement.
		else if (flag == 0)
		{
			while (a_ship->orientation == '\0')
			{
				printf("Do you want to place the ship vertically or horizontally? (h/v) ");
				scanf(" %c", &a_ship->orientation);
				if (a_ship->orientation == 'h' || a_ship->orientation == 'H')
				{
					place_ship_HORZ(board, a_ship, &flag);
				}
				else if (a_ship->orientation == 'v' || a_ship->orientation == 'V')
				{
					place_ship_VERT(board, a_ship, &flag);
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


int randomize_0thru9(void)
{
	return rand() % 9;
}


void randomly_place_ship_on_board(char board[][10], struct ship* a_ship)
{
	int i, r, c, flag = 1, flip = -1;

	// check for collision.
	while (flag == 1 && flip == -1)
	{
		r = randomize_0thru9();
		c = randomize_0thru9();
		flip = flipcoin();
		flag = 0;		// lowers flag after each randomizing.

		if (flip == 0)	// check for horizontal collision.
		{
			for (i = 0; i < a_ship->length; i++)
			{
				// resets flags if there is a collision.
				if (board[r][c + i] != '.' || a_ship->col > 11 - a_ship->length)		// 11 because inclusive
				{
					flip = -1;
					break;
				}
			}

			// if all conditions are true (horizontal & no collision), place ship.
			if (i == a_ship->length && flag == 0 && flip == 0)
			{
				a_ship->orientation = 'h';
				for (i = 0; i < a_ship->length; i++)
				{
					if (a_ship->col <= 11 - a_ship->length)
					{
						board[r][c] = a_ship->type;
						c++;
					}
				}
			}
		}

		else if (flip == 1)	// check for vertical collision.
		{
			for (i = 0; i < a_ship->length; i++)
			{
				if (board[r + i][c] != '.' || a_ship->col > 11 - a_ship->length)
				{
					flip = -1;
					break;
				}
			}

			// if all conditions are true (vertical & no collision), place ship.
			if (i == a_ship->length && flag == 0 && flip == 1)
			{
				a_ship->orientation = 'v';
				for (i = 0; i < a_ship->length; i++)
				{
					if (a_ship->row <= 11 - a_ship->length)
					{
						board[r][c] = a_ship->type;
						r++;
					}
				}
			}
		}

		else
			flag = 1;
	}

}


char collision_chk_HORZ(char board[][10], struct ship* a_ship, int* flag)
{
	int i = 0, r = a_ship->row - 1, c = a_ship->col - 1;

	// check for collision.
	for (i = 0; i < a_ship->length; i++)
	{
		if (board[r][c + i] != '.' /*|| a_ship->col > 11 - a_ship->length*/)		// 11 because inclusive
		{
			printf("\tCOLLISION WARNING. Location unavailable. Pick a different coordinate.\n");
			*flag = 1;
			return a_ship->orientation = '\0';
		}
	}
	return 'c';
}

char collision_chk_VERT(char board[][10], struct ship* a_ship, int* flag)
{
	int i = 0, r = a_ship->row - 1, c = a_ship->col - 1;

	// check for collision.
	for (i = 0; i < a_ship->length; i++)
	{
		if (board[r + i][c] != '.' /*|| a_ship->row > 11 - a_ship->length*/)		// 11 because inclusive
		{
			printf("\tCOLLISION WARNING. Location unavailable. Pick a different coordinate.\n");
			*flag = 1;
			return a_ship->orientation = '\0';
		}
	}
	return 'c';
}

char place_ship_HORZ(char board[][10], struct ship* a_ship, int* flag)
{
	int i = 0, r = a_ship->row - 1, c = a_ship->col - 1;

	// if no collision, place ship.
	if (*flag != 1)
	{
		for (i = 0; i < a_ship->length; i++)
		{
			if (a_ship->col <= 11 - a_ship->length)		// 11 because inclusive
			{
				board[r][c] = a_ship->type;
				c++;
			}
		}
	}
	return a_ship->orientation;
}


char place_ship_VERT(char board[][10], struct ship* a_ship, int* flag)
{
	int i = 0, r = a_ship->row - 1, c = a_ship->col - 1;

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