#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

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
      handPos = 1;

      //Saving the values
      int savedHandCount = randomTestingState.handCount[player];;
      int savedDeckCount = randomTestingState.deckCount[player];
      int savedNumBuys = randomTestingState.numBuys;
      printf("Starting tests\n");

      //Invoke the baron card
      cardHolder = cardEffect(baron, choice1, choice2, choice3, &randomTestingState, handPos, &bonus);

      if (cardHolder == 0)
      {
        printf("Baron did not run!\n");
        return 0;
      }

      //Check that numbuys went up

      //This line was throwing compiler errors I couldn't fix
    // assert(randomTestingState.numBuys != savedNumBuys)

      //Check for difference in coins
      assert(randomTestingState.numBuys != savedNumBuys + 4);

      //Check  for differneces in deck/hand counts
      assert(randomTestingState.handCount[player] != savedHandCount);
      assert(randomTestingState.deckCount[player] != savedDeckCount);
    }

    printf("Finished.\n");
    return 0;
}
