#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

char inputChar()
{
    //Filling the array with all possible characters that infulence the if statements
    char characterArray[9] = { ' ', 'a', 'x', '[', '(', '{','}', ')', ']' };
    
    //Getting a random element to use as an input
	int randomElement = (rand() % 9);
    
    //Returning the number corresponding to the random element
    return characterArray[randomElement];
}

char *inputString()
{
    //A string to hold the characters with a null terminator
    //This would segfault without static, so I guess there was some scope issue without it. 
	static char returnedString[6] = {' ', ' ', ' ', ' ', ' ', '\0'};
	
    //In the last if statement, reset with a null terminator will get us to error and terminate
    char terminateChars[5] = "reset";
	
    //This will randomly jumble up r e s e t \n so we get a string to pass in.
    //This mixed with the random char in inputChar will let us get random values
    //to pass through the giant if branches that we see in testme(). Just by pure brute force
    //we can eventually get "reset\n" and kill the loop.
    for (int i = 0; i < 5; i++)
    {
		int swapIndex = (rand() % 5);
		returnedString[i] = terminateChars[swapIndex];
	}

    return returnedString;
}

//Everything below here is from the sample file
void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}

