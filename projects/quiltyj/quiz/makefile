CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme testme.c -g $(CFLAGS)

executetests: testme
	./testme &> testme.out
	gcov testme.c &> gcovtext.txt

clean:
	rm -f *.o testme *.gcov *.gcda *.gcno *.so *.txt *.out

