#include <stdio.h>
#include <stdlib.h>

int largest_score[50];

int backtracking(int tcase, int test_case[], int size, int max_temp)
{
    printf("Entrei com tcase: %d size: %d max_temp: %d\n", tcase, size, max_temp);
	int i=0;

	if(largest_score[tcase] < max_temp)
	{
        largest_score[tcase] = max_temp;
    }
    if(size > 1)
    {
        for(i=0; i<size; i++)
        {
        	int next_ball=i+1, new_test_case[size], n=0, new_size=0, equal=1, j, k;

            if(test_case[i] == test_case[next_ball])
            {
                printf("Encontrou: i: %d test_case[i]: %d test_case[i+1]: %d\n", i, test_case[i], test_case[next_ball]);
                n++;
            	if(next_ball < size)
            	{
                    printf("next_ball<size\n");
                    /* Preenche o novo array com as bolas que estavam antes das que foram eliminadas */
                	if(i!=0)
                    {
                        for (j = 0; j < i; j++)
                        {
                            new_test_case[new_size] = test_case[j];
                            new_size++;
                        }
                	}
                    /* Preenche o novo array com as bolas que estavam a seguir 'as que foram eliminadas */
                	for (k = next_ball; k < size; k++)
                    {
                        if(test_case[i] == test_case[k] && equal == 1)
                        {
                            printf("Encontrei mais uma bola igual test_case[i]: %d test_case[i+1]: %d\n", test_case[i], test_case[k]);
                            n++;
                        }else{
                            equal=0;
                            new_test_case[new_size] = test_case[k];
                            new_size++;
                        }
                    }
                
                    /* Entra na recursiva com o novo array que contem as bolas que ficaram para a jogada seguinte. actualiza o score consoante a jogada feita */
                	backtracking(tcase, new_test_case, new_size, max_temp+(n*(n+1)));
                

                    /* Avanca no array as bolas que foram removidas durante a jogada */
                	while(test_case[i]==test_case[next_ball] && next_ball < size)
                    {
                        printf("ultimo while\n");
                    	i++;
                    	next_ball++;
                	}
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