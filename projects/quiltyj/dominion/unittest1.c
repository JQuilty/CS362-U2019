#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"


int main () 
{
		//Note that for simplicity, I'm re-using some of the code from main2 in the original player.c
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int choice1 = 1;
	int choice2 = 1;
	int choice3 = 1;
	int handPos = 3;
	int bonusbase = 1;
	int *bonus = &bonusbase;
	int currentPlayer = 1;
	int seed = 100;
	
	
	struct gameState g;
	struct gamestate* TheGame = &g;
	
	printf ("Starting the test for Baron Card.\n");
	
	initializeGame(2, k[10], seed, TheGame);
	
	selectBaron(choice1, choice2, choice3, TheGame, handPos, bonus, currentPlayer);

	
	//checking that it accurately increments numBuys, should go up by one
	if (TheGame->numBuys == 2)
		printf("NumBuys working!\n");
	else
		printf("NumBuys broken!\n");

		return 0;
}
	   
	   