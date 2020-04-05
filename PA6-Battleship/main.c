/*
	NAME: KARL NORDEN | CLASS: CPTS 121, SECTION 17
	DESCRIPTION: BUILD A BATTLESHIP GAME IN C.
				Refer to README.md for more information and complete program development.
*/
#include "main.h"

// declares and intializes global arrays for the displayed gameboard.
char g_label[1][22] = { 0 }, g_gameboard[10][21] = { 0 };


int main(void)
{
	// Set the seed for the randomizer.
	srand((unsigned int)time(NULL));

	// ship type: type, orientation, length, row, col
	Ship Carrier = { "", 'C', '\0', 5, 0, 0 };
	Ship Battleship = { "", 'B', '\0', 4, 0, 0 };
	Ship Cruiser = { "", 'R', '\0', 3, 0, 0 };
	Ship Submarine = { "", 'S', '\0', 3, 0, 0 };
	Ship Destroyer = { "", 'D', '\0', 2, 0, 0 };

	// In the beginning both players have the same fleet, unplaced and undamaged.
	// Therefore, initialize both arrays as such.
	Ship P1_Fleet[5] = { Carrier, Battleship, Cruiser, Submarine, Destroyer },
		P2_Fleet[5] = { Carrier, Battleship, Cruiser, Submarine, Destroyer };

	// Declare and intialize one array board for each player.
	char P1_board[10][10] = { 0 },
		P2_board[10][10] = { 0 };
	initialize_board(P1_board);
	initialize_board(P2_board);

	core_game(P1_Fleet, P2_Fleet, P1_board, P2_board);

	return 0;
}

