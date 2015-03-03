#include <stdio.h>
#include <stdlib.h>

int largest_score[50];

int backtracking(int tcase, int test_case[], int size, int max_temp)
{
	int i=0;

	if(largest_score[tcase] < max_temp)
	{
        largest_score[tcase] = max_temp;
    }
    if(size > 1)
    {
        for(i=0; i<size; i++)
        {
        	int next_ball=i+1, new_test_case[size], n=0, new_size=0, equal=1, j, l=0;

            if(test_case[i] == test_case[next_ball])
            {
                l++;
                n++;
            	if(next_ball < size)
            	{
                    for (j = 0; j < size; j++)
                    {
                        if (j<i)
                        {
                            new_test_case[new_size] = test_case[j];
                            new_size++;
                        } else{
                            if(test_case[i] == test_case[j+1] && equal == 1)
                            {
                                n++;
                            }else{
                                equal=0;
                                new_test_case[new_size] = test_case[j+1];
                                new_size++;
                            }           
                        }
                	}
                
                	backtracking(tcase, new_test_case, new_size, max_temp+(n*(n+1)));
                    
                    i=i+l;
                    next_ball=next_ball+l;
        		}
    		}
    	}
    }
	return largest_score[tcase];
}

int main()
{
    int i=0, j=0;
    int tests=0, size=0;

    scanf("%d", &tests);
    largest_score[tests]=0;

    for (i = 0; i < tests; ++i)
    {
    	scanf("%d", &size);
    	int test_case[size];
    	for (j = 0; j < size; ++j)
    	{
    		scanf("%d", &test_case[j]);
    	}
    	largest_score[i] = backtracking(i, test_case, size, 0);
    	printf("%d\n", largest_score[i]);
    }
    return 0;
}