#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void cardTest2()
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
	//See what happens if you invoke a non-existent player
	initializeGame(numPlayers, k, seed, &G);
	int returnValue = shuffle(3, &G);
	printf("Exited with a value of %d, anything but 0 is bad.\n", returnValue);
}

int main()
{
	cardTest2();
	return 0;
}
