#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void cardTest5()
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
	int numPlayers = 5;
	int seed = 500;
	int shuffleCount = 0;


	//Setting up structs for testing
	struct gameState G, testingBoard, testingBoard2;

    //Note that for simplicity, I'm re-using some of the code from main2 in the original player.c
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    //Initialize a game
	initializeGame(numPlayers, k, seed, &G);
	initializeGame(numPlayers, k, seed, &testingBoard);

	//Having the first player draw a card
	drawCard(0, &G);

	printf("G Deck Count = %d, testingBoardDeckCount = %d\n", G.deckCount[0], testingBoard.deckCount[0]);
	printf("G P1 Handcount = %d, testingBoard P1 handcount = %d\n", G.handCount[0], testingBoard.handCount[0]);
}

int main()
{
	cardTest5();
	return 0;
}
