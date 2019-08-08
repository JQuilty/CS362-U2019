#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

void mineTest()
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

	int* tributeRevealedCards[3] = { 1, 2, 3};

	//Setting up structs for testing
	struct gameState G, testingBoard, testingBoard2;

    //Note that for simplicity, I'm re-using some of the code from main2 in the original player.c
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    //Initialize a game
	initializeGame(numPlayers, k, seed, &G);
	initializeGame(numPlayers, k, seed, &testingBoard);

    printf ("Starting the test for Mine.\n");
    memcpy(&testingBoard, &G, sizeof(struct gameState));

    int returnValue = selectMine(&testingBoard, currentPlayer, 6, 1, 1);

    //Checking the return value;
    printf("SelectMine's return was %d\n", returnValue);

    if (returnValue != -1)
    {
    	printf("Handcount = %d, Original = %d\n", testingBoard.handCount[currentPlayer], G.handCount[currentPlayer]);
    	printf("Coins = %d, Original = %d\n", testingBoard.coins, G.coins);
    }
}

int main ()
{
	mineTest();
	return 0;

/*	if (initializeGame(numplayers, k[10], seed, TheGame) == 0)
		printf("Success on initGame!\n");
	else
		printf("initializeGame broken!");*/

}
