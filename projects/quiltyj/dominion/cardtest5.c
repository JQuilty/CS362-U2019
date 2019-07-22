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
	
	//Re-uses a condition within the function itself to test. If there's no cards, then logically nothing was drawn yet it completed anyway
	if ( TheGame->deckCount[1] <= 0)
		printf("Failure on drawing!\n");
	else
		printf("drawCard success!\n");
	
}