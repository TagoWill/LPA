#include <stdio.h>
#include <stdlib.h>

int test_case[50][50];
int largest_score[50];

int backtracking(int tcase, int size, int ball)
{
	int i=0;
	/*Whenever the player shoots a ball, all adjacent balls with the same color are eliminated. 
	Everytime the player eliminates more n > 1 balls with the same color in a single shot, the score increments by n (n + 1). 
	Moreover, the player cannot shoot isolated balls (i.e., no adjacent ball has the same color). 
	Therefore, the game terminates once all balls are shot or there are only isolated balls.*/
	printf("Entrei: tcase: %d size: %d ball: %d\n", tcase, size, ball);
	for (i = 0; i < size; ++i)
	{
		if (test_case[tcase][i]==test_case[tcase][i+1])
		{
			if(test_case[tcase][i]==test_case[tcase][i-1])
			{
				largest_score[tcase]=largest_score[tcase]+(3*4);

				test_case[tcase][i-1]=test_case[tcase][i-2];
				test_case[tcase][i]=test_case[tcase][i+2];

				backtracking(tcase, size-2, 0);
			} else
			{
				largest_score[tcase]=largest_score[tcase]+(2*3);
				
				test_case[tcase][i]=test_case[tcase][i+2];

				backtracking(tcase, size-1, 0);
			}
		} 
		else if(test_case[tcase][i]==test_case[tcase][i-1]) 
		{
			if(test_case[tcase][i]==test_case[tcase][i+1])
			{
				largest_score[tcase]=largest_score[tcase]+(3*4);

				test_case[tcase][i-1]=test_case[tcase][i-2];
				test_case[tcase][i]=test_case[tcase][i+2];

				backtracking(tcase, size-2, 0);
			} else
			{
				largest_score[tcase]=largest_score[tcase]+(2*3);

				test_case[tcase][i-1]=test_case[tcase][i-2];

				backtracking(tcase, size-1, 0);
			}
		}
	}
	return largest_score[tcase];
}

int main()
{
    int i=0, j=0;
    int tests=0;

    scanf("%d", &tests);
    largest_score[tests]=0;

    for (i = 0; i < tests; ++i)
    {
    	scanf("%d", &test_case[i][0]);
    	for (j = 1; j < test_case[i][0]+1; ++j)
    	{
    		scanf("%d", &test_case[i][j]);
    	}

    	largest_score[i] = backtracking(i, test_case[i][0], 0);
    	printf("%d\n", largest_score[i]);
    }

	/*for (i = 0; i < tests; ++i)
    {
    	printf("%d\n", test_case[i][0]);

    	for (j = 1; j < test_case[i][0]+1; ++j)
    	{
    		printf("%d ", test_case[i][j]);
    	}
    	printf("\n");
    }*/

    return 0;
}