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
        	int new_test_case[size], n=0, new_size=0, diferente = 0;
            
            int next_ball=i+1;
            if(test_case[i] == test_case[next_ball])
            {
                printf("Encontrou: i: %d test_case[i]: %d test_case[i+1]: %d\n", i, test_case[i], test_case[next_ball]);
                n++;
            	if(next_ball < size)
            	{
                    printf("next_ball<size\n");
                    /* Preenche o novo array com as bolas que estavam antes das que foram eliminadas */
                	if(i!=0){
                    	int posicao = 0;
                    	do{
                            printf("do while num1\n");
                        	new_test_case[new_size] = test_case[posicao];
                        	new_size++;
                        	posicao++;
                    	}while(posicao<i);
                	}
                    /* Preenche o novo array com as bolas que estavam a seguir 'as que foram eliminadas */
                	do{
                        printf("do while num2\n");
                    	if(test_case[i] == test_case[next_ball] && diferente == 0)
                    	{
                            printf("Encontrei mais uma bola igual test_case[i]: %d test_case[i+1]: %d\n", test_case[i], test_case[next_ball]);
                        	n++;
                    	}else{
                        	diferente = 1;
                        	new_test_case[new_size] = test_case[next_ball];
                        	new_size++;
                    	}
                    	next_ball++;
                	}while(next_ball < size);
                
                    /* Entra na recursiva com o novo array que contem as bolas que ficaram para a jogada seguinte. actualiza o score consoante a jogada feita */
                	backtracking(tcase, new_test_case, new_size, max_temp+(n*(n+1)));
                

                    /* Avanca no array as bolas que foram removidas durante a jogada */
                	next_ball = i+1;
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