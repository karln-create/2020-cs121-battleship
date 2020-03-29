/*
	NAME: KARL NORDEN | CLASS: CPTS 121, SECTION 17
	DESCRIPTION: BUILD A BATTLESHIP GAME IN C.
				Refer to README.md for more information and complete program development.
*/

#include "mainheader.h"

// declares and initializes global arrays. Can be used anywhere.
int g_label[1][22] = { 0 };
char g_gameboard[10][21] = { '\0' };

int main(void)
{

	// sets values for the array _label[][].
	set_arrays(g_label, g_gameboard);

	// calls function to print out the gameboard.
	print_gameboard(g_label, g_gameboard);

	return 0;
}