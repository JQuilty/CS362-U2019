#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

void minionTest()
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

    printf ("Starting the test for Minion.\n");
    memcpy(&testingBoard, &G, sizeof(struct gameState));

    /*
     * Here we're testing taking the increase in coin count. Normally it'll be +2 but due to a but
     * I introduced it's -2, but we'll assume +2 is correct
     */
	selectMinion(choiceTrue, choiceTrue, choiceTrue, &testingBoard, handPos, bonusPointer, currentPlayer);
	printf("Coin Count = %d, Original Value = %d\n", testingBoard.coins, G.coins);


	/*
	 * Now we test the discarding hand and getting +4 cards, and affecting other players
	 */

	memcpy(&testingBoard, &G, sizeof(struct gameState));
	selectMinion(choiceFalse, choiceTrue, choiceTrue, &testingBoard2, handPos, bonusPointer, currentPlayer);
	printf("Player Hand Count = %d, Original Value = %d\n", testingBoard2.handCount[currentPlayer], G.handCount[currentPlayer]);
	printf("Next Player Hand Count = %d, Original Value = %d\n", testingBoard2.handCount[currentPlayer+1], G.handCount[currentPlayer+1]);
}

int main ()
{
	//Running tests three times
	for (int i = 0; i > 3; i++)
	{
		minionTest();
	}

	return 0;

/*	if (initializeGame(numplayers, k[10], seed, TheGame) == 0)
		printf("Success on initGame!\n");
	else
		printf("initializeGame broken!");*/

}
