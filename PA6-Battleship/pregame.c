#include "root.h"

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

void manually_place_ship_on_board(char board[][10], struct ship *a_ship)
{
	int i = 0, r = -1, c = -1, flag = -1;
	a_ship->orientation = '\0';

	while (flag != 0)
	{
		// Ask P1 to enter integer coordinates: (row = i, col = j).
		get_coordinate(&r, &c);
		// Store coordinate in the ship's profile.
		a_ship->row = r - 1;
		a_ship->col = c - 1;
		flag = 0;
		// If inputs are out-of-bound, raise flag.
		if (r < 1 || r > 10 || c < 1 || c > 10)
		{
			printf("\n\tINVALID input.\n\tCoordinate is outside the gameboard.\n");
			flag = 1;
		}

		// If conditions satisfied, lower flag.
		else if (flag == 0)
		{
			// Asks P1 to choose an orientiation, vertical or horizontal for the ship placement.
			while (a_ship->orientation == '\0')
			{
				printf("Place the ship vertically or horizontally (h/v): ");
				scanf(" %c", &a_ship->orientation);
				if (a_ship->orientation == 'h' || a_ship->orientation == 'H')
				{
					flag = collision_chk_HORZ(board, a_ship);
					if (flag == 1)
					{
						printf("\tCOLLISION WARNING. Location unavailable. Pick a different coordinate.\n");
						break;
					}
					else if (flag == 0)
						place_ship_HORZ(board, a_ship);
				}
				else if (a_ship->orientation == 'v' || a_ship->orientation == 'V')
				{
					flag = collision_chk_VERT(board, a_ship);
					if (flag == 1)
					{
						printf("\tCOLLISION WARNING. Location unavailable. Pick a different coordinate.\n");
						break;
					}
					else if (flag == 0)
						place_ship_VERT(board, a_ship);
				}
				else
				{
					printf("\tThat is an INVALID orientation.\n\tPlease reenter an acceptable orientation.\n");
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

void randomly_place_ship_on_board(char board[][10], struct ship *a_ship)
{
	int r, c, flag = 1, flip = -1;
	a_ship->orientation = '\0';

	// check for collision.
	while (flag != 0)
	{
		r = randomize_0thru9();
		c = randomize_0thru9();
		a_ship->row = r;
		a_ship->col = c;

		flag = 0; // lowers flag after each randomizing.
		while (a_ship->orientation == '\0')
		{
			flip = flipcoin();
			if (flip == 0)
			{
				flag = collision_chk_HORZ(board, a_ship);
				if (flag == 1)
					break;
				else
				{
					a_ship->orientation = 'h';
					place_ship_HORZ(board, a_ship);
				}
			}
			else if (flip == 1)
			{
				flag = collision_chk_VERT(board, a_ship);
				if (flag == 1)
					break;
				else
				{
					a_ship->orientation = 'v';
					place_ship_VERT(board, a_ship);
				}
			}
		}
	}
}

int collision_chk_HORZ(char board[][10], struct ship *a_ship)
{
	int i = 0, r = a_ship->row, c = a_ship->col, check = 0;
	int max_c = MAX_BOARD_DIM - (a_ship->length);

	// check for collision.
	for (i = 0; i < a_ship->length; i++)
	{
		// inclusive: acceptable value of c must be <= max_c.
		if (board[r][c + i] != '.' || c > max_c)
		{
			// raise flag if either condition is satisfied.
			check = 1;
			break;
		}
	}
	return check;
}

int collision_chk_VERT(char board[][10], struct ship *a_ship)
{
	int i = 0, r = a_ship->row, c = a_ship->col, check = 0;
	int max_r = MAX_BOARD_DIM - (a_ship->length);

	// check for collision.
	for (i = 0; i < a_ship->length; i++)
	{
		// inclusive: acceptable value of r must be <= max_r.
		if (board[r + i][c] != '.' || r > max_r)
		{
			// raise flag if either condition is satisfied.
			check = 1;
			break;
		}
	}
	return check;
}

void place_ship_HORZ(char board[][10], struct ship *a_ship)
{
	int i = 0, r = a_ship->row, c = a_ship->col;

	// if no collision, place ship.
	for (i = 0; i < (a_ship->length); i++)
	{
		board[r][c] = a_ship->type;
		c++;
	}
}

void place_ship_VERT(char board[][10], struct ship *a_ship)
{
	int i = 0, r = a_ship->row, c = a_ship->col;

	// if no collision, place ship.
	for (i = 0; i < (a_ship->length); i++)
	{
		board[r][c] = a_ship->type;
		r++;
	}
}

void pre_game(struct ship P1_Fleet[], struct ship P2_Fleet[],
			  char P1_board[][10], char P2_board[][10])
{
	char ship_name[5][11] = {"Carrier",
							 "Battleship",
							 "Cruiser",
							 "Submarine",
							 "Destroyer"};

	// Set display form for the gameboard arrays.
	prep_board();

	// Call function to print out the gameboard.
	print_gameboard();

	 //Place ships for P1.
	for (int i = 0; i < 5; ++i)
	{
		strcpy(P1_Fleet[i].alias, ship_name[i]);
		printf("\n%s:\n", P1_Fleet[i].alias);
		//manually_place_ship_on_board(P1_board, &P1_Fleet[i]);
		randomly_place_ship_on_board(P1_board, &P1_Fleet[i]);
		update_gameboard(P1_board);
		print_gameboard();
		//print_board(P1_board);
	}

	// Place ships for P2.
	for (int i = 0; i < 5; ++i)
	{
		*P2_Fleet[i].alias = *ship_name[i];
		randomly_place_ship_on_board(P2_board, &P2_Fleet[i]);
		update_gameboard_P2(P2_board);
		print_gameboard();
		//print_board(P2_board);
	}
}