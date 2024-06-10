/* Title: Tic-tac-toe

	Instructions:
	
	* This game will have two players that will input in the same terminal. 
	
	* This 3x3 game board will need to be represented using a data structure, like a vector or an array. 
	
	* There are 8 winning combinations.

	Hints: 
	
	* Loops: This program should use a for loop or while loop to iterate through the player turns. 
	
	* Vector: This program should use a vector or an array to hold nine positions of the 3x3 grid. 
	
	* Functions: This program should be modular. 	
	
*/

#include <iostream>
#include "Function_Declarations.hpp"

using namespace std;

int main () {
	
	/* Introduction */
    Introduction();	

	/* Play the Game */
	Start_Playing();

	/* End of the Game */
	end_game();

	return 0; 
	
}