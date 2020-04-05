#include "main.h"

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

void core_game()
{
	// ship type: type, orientation, length, row, col
	Ship Carrier	= { "", 'C', '\0', 5, 0, 0 };
	Ship Battleship = { "", 'B', '\0', 4, 0, 0 };
	Ship Cruiser	= { "", 'R', '\0', 3, 0, 0 };
	Ship Submarine	= { "", 'S', '\0', 3, 0, 0 };
	Ship Destroyer	= { "", 'D', '\0', 2, 0, 0 };

	// In the beginning both players have the same fleet, unplaced and undamaged.
	// Therefore, initialize both arrays as such.
	Ship P1_Fleet[5] = { Carrier, Battleship, Cruiser, Submarine, Destroyer },
		 P2_Fleet[5] = { Carrier, Battleship, Cruiser, Submarine, Destroyer };

	// Declare and intialize one array board for each player.
	char P1_board[10][10] = { 0 },
		 P2_board[10][10] = { 0 };
	initialize_board(P1_board);
	initialize_board(P2_board);

	// Call function to set up the gameboard.
	pre_game(P1_Fleet, P2_Fleet, P1_board, P2_board);

	// Flip a coin to determine which player goes first.
	int coin = flipcoin();
	// IF coin == 0 THEN turn: P1.
	// IF coin == 1 THEN turn: P2.

}

void pre_game(struct ship P1_Fleet[], struct ship P2_Fleet[],
										char P1_board[][10], char P2_board[][10])
{
	char ship_name[5][11] = { "Carrier",
							  "Battleship",
							  "Cruiser",
							  "Submarine",
							  "Destroyer" };

	// Ship placements for P1.
	//for (int i = 0; i < 5; ++i)
	//{
	//	strcpy(P1_Fleet[i].alias, ship_name[i]);
	//	printf("\n%s:\n", P1_Fleet[i].alias);
	//	manually_place_ship_on_board(P1_board, &P1_Fleet[i]);
	//	update_gameboard(P1_board);
	//	print_gameboard();
	//	//print_board(P1_board);
	//}

	// ship placements for P2.
	for (int i = 0; i < 5; ++i)
	{
		*P2_Fleet[i].alias = *ship_name[i];
		randomly_place_ship_on_board(P2_board, &P2_Fleet[i]);
		update_gameboard_P2(P2_board);
		print_gameboard();
		print_board(P2_board);
	}
}

void post_game()
{

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