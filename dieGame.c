#include <stdio.h>
#include <stdlib.h>
#include "dieGame.h"

// 250201092 Aynur Atış

// This code compiled with gcc version 10.2.0

void Round(int round) // number of round function
{
	if(round == 1)
		printf("%dst Round \n", round);
	else if(round == 2)
		printf("%dnd Round \n", round);
	else if(round == 3)
		printf("%drd Round \n", round);
	else
		printf("%dth Round \n", round);
}

void orderUsers (char Player1[], char Player2[], char Player3[], char User[], int totalP1, int totalP2, int totalP3, int totalUser) { // ordering the users

	char userList[4];
	int pointList[4]; // the array holds the total points of players
	pointList[0] = totalP1;
	pointList[1] = totalP2;
	pointList[2] = totalP3;
	pointList[3] = totalUser;
	int tmp;
	for(int i = 0; i<4; i++) // Ranking players from high score to low score
	{
		for(int j = 0; j<4; j++)
		{
			if(pointList[i] >= pointList[j])
			{
				tmp = pointList[i];
				pointList[i] = pointList[j];
				pointList[j] = tmp;
			}
		}
	}

	int P1=0, P2=0, P3=0, Us=0; //  I using counter for all players because if there are players who have the same point, I want to write the screen all one
	for(int k = 0; k<4; k++)
	{

		if(pointList[k] == totalP1 && P1 == 0)
			{
				if(totalP1 >=20) // if player1 has 20 points or more than 20 points, player1 is gained the game
				{
					printf("%d-%s %d points. Winner \n", k+1, Player1, totalP1);
				}
				else
				{
					printf("%d-%s %d points \n", k+1, Player1, totalP1);
					P1++;
				}
			}
		else if(pointList[k] == totalP2 && P2==0)
			{
				if(totalP2 >=20) // if player2 has 20 points or more than 20 points, player2 is gained the game
				{
					printf("%d-%s %d points. Winner \n", k+1, Player2, totalP2);
				}
				else
				{
					printf("%d-%s %d points \n", k+1, Player2, totalP2);
					P2++;
				}
			}
		else if(pointList[k] == totalP3 && P3==0)
			{
				if(totalP3 >=20) // if player3 has 20 points or more than 20 points, player3 is gained the game
				{
					printf("%d-%s %d points. Winner \n", k+1, Player3, totalP3);
				}
				else
				{
					printf("%d-%s %d points \n", k+1, Player3, totalP3);
					P3++;
				}
			}
		else if(pointList[k] == totalUser && Us==0)
			{
				if(totalUser >=20) // if user has 20 points or more than 20 points, user is gained the game
				{
					printf("%d-%s %d points. Winner \n", k+1, User, totalUser);
				}
				else
				{
					printf("%d-%s %d points \n", k+1, User, totalUser);
					Us++;
				}
			}

	}

}

void finalResult(char userName[]) // Final points function
{
	printf("%s reached 20 points.\n", userName);
	printf("Congratulations! %s have won the game.\n\n", userName);
	printf("Final Results Table: \n");

}


int gameRules(char user[])
{
	// random dice numbers
	int dice_1 = rand() % 6 + 1;
	int dice_2 = rand() % 6 + 1;
	int dice_3 = rand() % 6 + 1;
	// -------------------------------------------

	printf("%s rolled: %d-%d-%d\n", user,dice_1,dice_2,dice_3);

	if(dice_1 == 1 && dice_2 == 1 && dice_3 == 1)
	{
		printf("%s lost 10 points\n", user);
		return -10;
	}
	else if (dice_1 ==6 && dice_2 == 6 && dice_3 == 6)
	{
		printf("%s gained 10 points\n", user);
		return 10;
	}
	else if (dice_1 == dice_2 && dice_1 > 3)
	{
		printf("%s gained %d points\n", user, dice_3);
		return dice_3;
	}
	else if (dice_1 == dice_2 && dice_1 < 4)
	{
		printf("%s lost %d points\n", user,dice_3);
		return -dice_3;
	}
	else if (dice_1 == dice_3 && dice_1 > 3)
	{
		printf("%s gained %d points \n", user,dice_2);
		return dice_2;
	}
	else if (dice_1 == dice_3 && dice_1 < 4)
	{
		printf("%s lost %d points\n", user,dice_2);
		return -dice_2;
	}
	else if (dice_2 == dice_3 && dice_2 > 3)
	{
		printf("%s gained %d points\n", user,dice_1);
		return dice_1;
	}
	else if (dice_2 == dice_3 && dice_2 < 4)
	{
		printf("%s lost %d points\n", user,dice_1);
		return -dice_1;
	}
	else if ((dice_1 == 1 && dice_2 == 2 && dice_3 ==3) || (dice_1 == 1 && dice_2 == 3 && dice_3 ==2) || (dice_1 == 2 && dice_2 == 1 && dice_3 ==3) || (dice_1 == 2 && dice_2 == 3 && dice_3 ==1)
		|| (dice_1 == 3 && dice_2 == 2 && dice_3 ==1) || (dice_1 == 3 && dice_2 == 1 && dice_3 ==2))
	{
		printf("%s lost 3 points\n", user);
		return -3;
	}
	else if ((dice_1 == 4 && dice_2 == 5 && dice_3 ==6) || (dice_1 == 4 && dice_2 == 6 && dice_3 ==5) || (dice_1 == 5 && dice_2 == 4 && dice_3 ==6) || (dice_1 == 5 && dice_2 == 6 && dice_3 ==4)
		|| (dice_1 == 6 && dice_2 == 4 && dice_3 ==5) || (dice_1 == 6 && dice_2 == 5 && dice_3 ==4))
	{
		printf("%s gained 3 points\n", user);
		return 3;
	}

	else if(dice_1 == dice_2 == dice_3)
	{
		printf("%s gained 5 points\n", user);
		return 5;
	}
	else
		{
		printf("%s gained 0 points\n", user);
		return 0;
	}
}
