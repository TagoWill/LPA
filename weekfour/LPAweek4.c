#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (((a)>(b))?(a):(b))


int main() {
    int i, j, linha, coluna, row, col;
    scanf("%d %d", &linha, &coluna);
    if(linha>coluna){
        row=coluna;
        col=linha;
    }else{
        row=linha;
        col=coluna;
    }
    
    int tabela[row][col];
    
    if(linha>coluna){
        for(i=0;i<col;i++){
            for(j=0;j<row;j++){
                scanf("%d", &tabela[j][i]);
            }
        }
    }else{
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                scanf("%d", &tabela[i][j]);
            }
        }
    }
    
    int maxFinal = 0;
    
    int left, right;
    int temp[col], sum = 0, maxSum=0;

    
    for (left = 0; left < row; ++left)
    {
        memset(temp, 0, sizeof(temp));
        
        for (right = left; right < row; ++right)
        {
            sum = 0;
            maxSum = 0;
            
            for (i = 0; i < col; ++i){
                temp[i] += tabela[right][i];
                
                if (sum < 0)
                {
                    sum = temp[i];
                }
                else
                {
                    sum += temp[i];
                }
                
                maxSum = MAX(maxSum, sum);
            }
            
            maxFinal = MAX(maxFinal, maxSum);
        }
    }
    printf("%d\n", maxFinal);
    
    
    return 0;
    
}
