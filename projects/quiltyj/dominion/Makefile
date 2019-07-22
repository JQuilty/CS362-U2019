CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)


#########

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

unittestresults:
    ./unittest1.c &> unittestresult.out
    gcov unittest1.c >> unittestresult.out
    cat unittest1.c >> unittestresult.out
    ./unittest2.c &> unittestresult.out
    gcov unittest2.c >> unittestresult.out
    cat unittest2.c >> unittestresult.out
    ./unittest3.c &> unittestresult.out
    gcov unittest3.c >> unittestresult.out
    cat unittest3.c >> unittestresult.out
    ./unittest4.c &> unittestresult.out
    gcov unittest4.c >> unittestresult.out
    cat unittest4.c >> unittestresult.out
    ./unittest5.c &> unittestresult.out
    gcov unittest5.c >> unittestresult.out
    cat unittest5.c >> unittestresult.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
