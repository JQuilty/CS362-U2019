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
	int numplayers = 2;
	int *bonus = &bonusbase;
	int currentPlayer = 1;
	int seed = 100;
	
	struct gameState g;
	struct gamestate* TheGame = &g;
	initializeGame(numplayers, k[10], seed, TheGame);
	printf ("Starting the test for getting the winners.\n");
	
	//Checks that the value of players is greater than 0, indicating a win. I know this is logically not how it works but I want to show how I'd test it.
	if ( TheGame->players[i] <= 0)
		printf("Failure on getWinners!\n");
	else
		printf("getWinners success!\n");
	
}