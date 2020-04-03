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
	// declares and intializes one array board for each player.
	char P1_board[10][10] = { 0 }, P2_board[10][10] = { 0 };

	initialize_board(P1_board);
	initialize_board(P2_board);

	Ship Carrier	= { 'C', 5 };
	Ship Battleship = { 'B', 4 };
	Ship Cruiser	= { 'R', 3 };
	Ship Submarine	= { 'S', 3 };
	Ship Destroyer	= { 'D', 2 };

	int player_turn;
	// If player_turn == 1 ---> turn: P1. If player_turn == 2 ---> turn: P2.
	flipcoin(&player_turn);

	// Sets location for Carrier.
	printf("\n\tCarrier: ");
	manually_place_ship_on_board(P1_board, &Carrier);
	update_gameboard(P1_board);
	print_gameboard();

	printf("\n\tBattleship: ");
	manually_place_ship_on_board(P1_board, &Battleship);
	update_gameboard(P1_board);
	print_gameboard();

	printf("\n\tCruiser: ");
	manually_place_ship_on_board(P1_board, &Cruiser);
	update_gameboard(P1_board);
	print_gameboard();

	printf("\n\tSubmarine: ");
	manually_place_ship_on_board(P1_board, &Submarine);
	update_gameboard(P1_board);
	print_gameboard();

	printf("\n\tDestroyer: ");
	manually_place_ship_on_board(P1_board, &Destroyer);
	update_gameboard(P1_board);
	print_gameboard();



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