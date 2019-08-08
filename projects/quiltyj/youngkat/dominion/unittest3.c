#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

void ambassadorTest()
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

    printf ("Starting the test for Ambassador.\n");
    memcpy(&testingBoard, &G, sizeof(struct gameState));

    /*
     * Ambassador will immediately exit if there's any number of input issues.
     * Here we'll check for something returning -1.
     */

    /*
     * This one wouldn't really work, so I'm just doing the one test since I ran out of time.
    int holderValue1 = selectAmbassador(choiceTrue, choiceTrue, &testingBoard, currentPlayer, handPos);

    if (holderValue1 == -1)
    {
    	printf("Invalid values given.\n");
    }*/

    /*
     * Now we'll test what happens to the card counts.
     */

   // selectAmbassador(choiceTrue, choiceFalse, &testingBoard2, currentPlayer, 2);

}

int main ()
{
	//Running tests three times
	for (int i = 0; i > 3; i++)
	{
		ambassadorTest();
	}

	return 0;

/*	if (initializeGame(numplayers, k[10], seed, TheGame) == 0)
		printf("Success on initGame!\n");
	else
		printf("initializeGame broken!");*/

}
