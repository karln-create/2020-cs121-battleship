/*
	NAME: KARL NORDEN | CLASS: CPTS 121, SECTION 17
	DESCRIPTION: BUILD A BATTLESHIP GAME IN C.
*/

# PA6-Battleship | DESCRIPTION
	This program simulates the game of Battleship.
	Battleship is a two-player naval game, in which the players compete to win by sinking all the ships of their opponent.
	The first player to sink all ships on the other side wins.

	Both players' fleets consist of 5 ships that are hidden from the enemy. Each ship may be differentiated by its size
	(besides the Cruiser and Submarine), or by number of cells its expands on the game board:
			- Carrier			5 cells			c
			- Battleship		4 cells			b
			- Cruiser			3 cells			r
			- Submarine			3 cells			s
			- Destroyer			2 cells			d
		
	(*)	The program should be built such that the user is Player1 (P1) and the computer is Player2 (P2).

		Two Boards exist within the game, each Board is a 2-dim array of size 10 by 10.
		At the beginning of the game, each Board should be initialized to all '~' indicating that no ships have been placed.

		Before the game starts, P1 should have the Option either to place each of the 5 ships manually or randomize the
		placements. If P1 decides to place the ships manually, then they should be prompted to place the ships in order
		as listed above. Ships cannot be placed diagonally on either Board, they can only be placed horizontally or vertically.

	(*)	My program must check to see if the user tries to place the ship outside the boundaries of the Board on top of a ship
		that has already been placed.

		Each cell on the Board containing part of the ship must be indicated by the a letter indicating the type of ship.

		Once P1 has finished their placement of ships, P2's ship placements are randomized.

	(*)	Then the program randomply selects which player to go first. Then the game starts.

	(*)	Whenever it's P1's turn, the program will display a prompt to ask for a position to target (or where to shoot)
		on the enemy's Board. The position should be specified in terms of a Row and Column on the Board: {R: #, C: #}

	(*) The Row and Column should always be displayed along with the Board.

		If the position specified happens to contain an undamaged part of a ship, then a '*' will replace the '~'. Otherwise,
		if the shot is a miss, then an 'm' is placed there instead.

	(*) The players are not allowed to enter the same position.

	(*)	Clear the screen between turns using system("cls").

	(*)	For each move made by either player, the results should be echoed to a file called "battleship.log".
		Explicitly note the move's targeted position and whether the move was a hit or miss.
		If one of the ships happens to sink (or all parts destroyed), this also must also be logged in the file.

	At the end of of the game, statistics of both players should be written in the log file.
	The stats include:
			- total number of Hits
			- total number of Misses
			- total number of Shots
			- Hits to Misses ratio (as percentage)
			- Win / Loss status

	(*) The statistics should be placed in a structure called 'STATS'. I will need 2 variables of type Stats, one for each player.
		Once the game has ended, the the contents of each struct variable will be written in to the log file.
------------------------------------------------------------------------------------------------------------------------------------------------

# PA6-Battlship | PROGRAM DEVELOPMENT HISTORY
	
	UPDATE 2020-03-28-SAT-1122: First program formulation.
		Set up all relevant initial declarations. The program will have the following files:

		> header & main files: relevant declarations and main executable
			main.c: this file contains 2 board-arrays (one for each player), the updated board at the end of each round is fed back to
			board.c	for the next round of game. The function call is looped until the win flag is raised.
			<--> board.c: contains function calls to update one board.
						The updated board is then fed to main.c for printing out to the log file.
				<-- board-functions.c: contains functions relevant to updating positions on one gameboard.
			
			<-- statistics.c: contains all functions relevant to getting player statistics.

		> log file: for a complete history of all moves made.

		(*) Explaination of the arrows:
			The arrows represent the scope of relationship between files. For example, board-functions.c will very likely only interact with
			and feed data into boards.c.
		
			On the other hand, both boards.c and statistics.c feed data into main so that such data can be written out into a log file.
			They are on the same "rank" so there might be some interactions between the two.
		
			Similarly for main and log, main and log are on the same rank because main write out results in log.

	UPDATE 2020-03-28-SAT-1235: Set up a board-array for each player in main().
		
	UPDATE 2020-03-28-SAT-1938: Resolved a problem with the gameboard complex (row and column labels, and the actual content gameboard).
		SUMMARY: Originally, I created one single <char> array of size 11x22. I was intending to have the first row and first column to be
			the labels. However, it turns out that this simply does not work. I couldn't typecast the content of an integer into the
			array blocks and print the content out as characters. The result was garbage values for the labels.

			I decided to make a separate <int> array and recycle it for both the row and column label, while having a separate <char> array
			for the actual gameboard.

			In other words, the actual gameboard structure consist of an <int> array for label and a <char> for the playable gameboard.
			
		TO-DO: Implement the ship placement function for P1.

	UPDATE 2020-03-29-SUN-0948:
		SUMMARY: I decided to keep using for now the integer arrays for the gameboard and stream ascii code into the arrays, because
			it seems to be working fine.
			
		(*)	Will come back later to try again to merge both arrays into one single gameboard.

		TO-DO: Implement the ship placement randomizer for P1.
			Need: reliable rand function. Last implementation in PA5 was incredibly unreliable, i.e. it tends to bias towards
			multiple-of-a-kind, which sort of takes the fun out of playing.

	UPDATE 2020-04-02-THU-1215:
		I have changed the global arrays back to <char> type. After reading and thinking more about type, I remembered that char type has a
		much smaller memory footprint (1 byte per char vs. 4 bytes per integer). On the other hand, there is virtually no difference in
		implementation of the arrays.

		TO-DO: start work on the core-game:
			1. Coinflip to determine which player goes first.
			2.	a. Create the manual ship placement algorithm.
				b. Create the random ship placement algorithm.
			3. Create the algorithm to update the player board.

	UPDATE 2020-04-02-THU-1350:
		Completed implementation for the first ship placement (the Carrier) for either orientations (horizontal or vertical).
		TO-DOL: Create condition to check if the next ship length might collide with the previousply placed ship.

	UPDATE 2020-04-02-THU-1900: Implemented manual ship placement.
		I had some difficulties implementing this part because I was setting too many conditions making the program unnecessarily convoluted.
		For example, I was trying to 'help' out the player. If the player placed a ship too close to the border, I would flip the ship
		and place it in the opposite direction. This created unwanted behaviors that I could not figure out how to solve.

		In the end, I decided to simplify the conditions by grouping all collision and out-of-bound coordinates together. The program throws
		a warning flag if the player enter any coordinates that fit in this group.

		TO-DO: Create a randomizer for ship placement for P2.

