#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

//Testing Minion
int main()
{
  //Seed the RNG
  srand(time(NULL));

  for (int i = 0; i < 30; i++)
  {
    /*Make our structs and global  vars
    Gold is set to 4 since that's what the baron needs to act
    on discarding an estate. deckCount is 1 since we just
    need to test once.
    */
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    struct gameState randomTestingState;
    initializeGame(3, k, 1, &randomTestingState);
    int bonus = 0;
    int cardHolder;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int deckCount = 1;
    int discardCount = 1;
    int handPos = 0;
    int coins = 4;
    int player = 0;

    //Start the game up and set various parameters
    //Going to modulo the cards by the max_hand and max_deck for randomness
    //so I know they're within the bounds
    randomTestingState.numPlayers = 3;
    randomTestingState.whoseTurn = 0;
    player = whoseTurn(&randomTestingState);
    randomTestingState.handCount[player] = (rand() % MAX_HAND);
    randomTestingState.deckCount[player] = (rand() % MAX_DECK);
    randomTestingState.numBuys = 0;
    randomTestingState.coins = coins;
    handPos = 1;

    int savedHandCount = randomTestingState.handCount[player];
    int savedDeckCount = randomTestingState.deckCount[player];
    int savedP2Hand = randomTestingState.handCount[1];
    int savedP3Hand = randomTestingState.handCount[2];
    int savedNumBuys = randomTestingState.numBuys;
    printf("Starting tests\n");

    //Invoke the minion card
    cardHolder = cardEffect(minion, choice1, choice2, choice3, &randomTestingState, handPos, &bonus);

    if (cardHolder == 0)
    {
      printf("Minion did not run!\n");
      return 0;
    }

    //Check that other players have one less card, since they have to discard
    //five and draw 4
    if (randomTestingState.handCount[player] == savedHandCount)
    {
      assert(randomTestingState.handCount[1] == (savedP2Hand - 1) && randomTestingState.handCount[2] == (savedP3Hand -1));
    }

    else
    {
      assert(randomTestingState.coins == (coins + 2));
    }
  }
    printf("Finished.\n");
    return 0;
}
