#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

//Note that for simplicity, I'm re-using some of the code from main2 in the original player.c
int main () 
{
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int choice1 = 1;
	int choice2 = 1;
	int choice3 = 1;
	int handPos = 3;
	int bonusbase = 1;
	int *bonus = &bonusbase;
	int currentPlayer = 1;
	int nextPlayer = 2;
	int[5] revealedCards = {1, 2, 3, 4, 5};
	int seed = 100;
	
	
	struct gameState TheGame;
	printf ("Starting the test for Tribute Card.\n");
	
	initializeGame(2, k[10], seed, TheGame);
	
	selectTribute(TheGame, currentPlayer, nextPlayer, revealedCards);

	
	//checking that it accurately increments the deck count, can access via a variable
	if (TheGame->deckCounter[nextPlayer] < 2)
		printf("deckCounter working!\n");
	else
		printf("deckCounter broken!\n");
	
		return 0;
}
	   
	   