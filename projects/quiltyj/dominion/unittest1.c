#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

//#define CARD "Baron";

void baronTest()
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

    printf ("Starting the test for Baron.\n");

    //Copy game state to a new test case instance

    memcpy(&testingBoard, &G, sizeof(struct gameState));
	selectBaron(choiceFalse, 0, 0, &testingBoard, handPos, bonusPointer, currentPlayer);

	/*
	 * The Baron card will ALWAYS do +1 for numbuys, then gives you a choice for getting rid of an estate or gaining one.
	 * Here we test that but make sure that we  gain an estate card.
	 */

	newCards = 1;
	addedCoins = 0;
	printf("handCount = %d, Original Value = %d\n", testingBoard.handCount[currentPlayer], G.handCount[currentPlayer] + newCards);
	printf("deckCount = %d, Original Value = %d\n", testingBoard.deckCount[currentPlayer], G.deckCount[currentPlayer] - newCards + shuffleCount);
	printf("Number of Coins = %d, Original Value = %d\n", testingBoard.coins, G.coins + addedCoins);
	printf("Number of buys = %d, Original Value = %d\n", testingBoard.numBuys, G.numBuys + buyIncrement);
	printf("estate supply count = %d, Original Value = %d\n", testingBoard.supplyCount[estate], G.supplyCount[estate]);


	/*
	 * Now we test a scenario in whichyou do not have an estate card to get rid of, and as such are forced to get one.
	 */

	memcpy(&testingBoard2, &G, sizeof(struct gameState));
	selectBaron(choiceTrue, 0, 0, &G, handPos, bonusPointer, currentPlayer);

	//We have to get rid of any existing estate cards, so we're going to zero them out and replace them.

	for (int i = 0; i < testingBoard2.handCount[currentPlayer]; i++)
	{
		if (testingBoard2.hand[currentPlayer] == estate)
		{
			//Changing it to adventurer and adjusting card counts
			testingBoard2.hand[currentPlayer][i] = adventurer;
			testingBoard2.supplyCount[adventurer]--;
			testingBoard2.supplyCount[estate]++;

			//Doing the same for the original board.
			G.hand[currentPlayer][i] = adventurer;
			G.supplyCount[adventurer]--;
			G.supplyCount[estate]++;
		}
	}
}


int main ()
{
	//Running tests three times
	for (int i = 0; i > 3; i++)
	{
		baronTest();
	}

	return 0;

/*	if (initializeGame(numplayers, k[10], seed, TheGame) == 0)
		printf("Success on initGame!\n");
	else
		printf("initializeGame broken!");*/

}
