#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#include "dieGame.h"

// 250201092 Aynur Atış

// This code compiled with gcc version 10.2.0

int main()
{
	srand(time(NULL)); //randomize the number generator
	char userName[20], respond[6], yesNo[2];
	char P1[] = "Player1";
	char P2[] = "Player2";
	char P3[] = "Player3";
	char begin[6] = "start";
	int round = 1;
	int totalPointPl1 = 0, totalPointPl2 = 0, totalPointPl3 = 0, totalPointUser = 0;
	printf("Please enter the username: ");
	scanf("%s", userName);
	printf("User registered as '%s' \n", userName);
	printf("Type \"start\" to begin the game: ");
	scanf("%s", respond);
	if(!strcmp(respond, begin)) // if the user enter the start
	{
		Round(round);
		totalPointPl1 += gameRules(P1); // total point for Player1
		totalPointPl2 += gameRules(P2); // total point for Player2
		totalPointPl3 += gameRules(P3); // total point for Player3
		printf("Roll the dice(y/n)?: "); // yes or no respond
		scanf("%s", yesNo);
		while(1)
		{
			
			if(!strcmp(yesNo, "y"))
			{
				totalPointUser += gameRules(userName); // total point for User
				if(totalPointUser >= 20) //the user's point is greater than 20
				{
					finalResult(userName);
					orderUsers(P1, P2, P3, userName, totalPointPl1, totalPointPl2, totalPointPl3, totalPointUser);
					exit(EXIT_SUCCESS);
				}
				printf("\nPoints Table after ");
				Round(round);
				orderUsers(P1, P2, P3, userName, totalPointPl1, totalPointPl2, totalPointPl3, totalPointUser); // the function orders the points to small from big
				round++;
				printf("\n");
				Round(round); // round number
				totalPointPl1 += gameRules(P1);
				if(totalPointPl1 >= 20) // the player1's point is greater than 20
				{
					finalResult(P1);
					orderUsers(P1, P2, P3, userName, totalPointPl1, totalPointPl2, totalPointPl3, totalPointUser);
					exit(EXIT_SUCCESS);
				}
				totalPointPl2 += gameRules(P2); // the player2's point is greater than 20
				if(totalPointPl2 >= 20)
				{
					finalResult(P2);
					orderUsers(P1, P2, P3, userName, totalPointPl1, totalPointPl2, totalPointPl3, totalPointUser);
					exit(EXIT_SUCCESS);
				}
				totalPointPl3 += gameRules(P3);
				if(totalPointPl3 >= 20) // the player3's point is greater than 20
				{
					finalResult(P3);
					orderUsers(P1, P2, P3, userName, totalPointPl1, totalPointPl2, totalPointPl3, totalPointUser);
					exit(EXIT_SUCCESS);
				}
				printf("Roll the dice(y/n)?: ");
				scanf("%s", yesNo);
			}
			else if(!strcmp(yesNo, "n")) // yes or no respond 
			{
				printf("end the game...");
				exit(EXIT_SUCCESS);
			}
			else{
				printf("Wrong respond...\n");
				printf("Roll the dice(y/n)?: ");
				scanf("%s", yesNo);
			}
		}	
		
	}
	else{ // user does not enter start
		printf("The game is over before it starts...");
		exit(EXIT_SUCCESS);
	}
	
}
