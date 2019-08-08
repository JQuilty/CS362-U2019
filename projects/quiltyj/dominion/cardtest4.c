#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void cardTest4()
{
	/*
	 * Note that I'm using the testUpdateCoins.c as somewhat of a template for testing.
	 */
    //Variables
	int addedCoins = 0;
	int buyIncrement = 1;
	int bonus = 0;
	int bonusPointer = &bonus;
	int choiceFalse = 0;
	int choiceTrue = 1;
	int currentPlayer = 0;
	int discardCount = 1;
	int handPos = 0;
	int newCards = 0;
	int numPlayers = 2;
	int seed = 500;
	int shuffleCount = 0;


	//Setting up structs for testing
	struct gameState G, testingBoard, testingBoard2;

    //Note that for simplicity, I'm re-using some of the code from main2 in the original player.c
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    //Initialize a game
	initializeGame(numPlayers, k, seed, &G);
	initializeGame(numPlayers, k, seed, &testingBoard);

	//Invoking the end of a turn
	endTurn(&G);

	//Checking that the turns can switch.
	int playerValue1 = whoseTurn(&G);
	int playerValue2 = whoseTurn(&testingBoard);
	printf("Current player of G is %d, current player of testingBoard is %d.\n", playerValue1, playerValue2);

	//Checking that coins get zeroed out
	int coinValue1 = G.coins;
	int coinValue2 = testingBoard.coins;
	printf("Current coins of G is %d, current coins of testingBoard is %d.\n", coinValue1, coinValue2);
}

int main()
{
	cardTest4();
	return 0;
}
