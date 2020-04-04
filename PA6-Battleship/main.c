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
	// sets the seed for the randomizer.
	srand((unsigned int)time(NULL));

	// sets preparatory values for the gameboard arrays.
	prep_set_arrays(/*g_label, g_gameboard*/);

	// calls function to print out the gameboard.
	print_gameboard(/*g_label, g_gameboard*/);

	core_game();

	print_gameboard(/*g_label, g_gameboard*/);

	return 0;
}

