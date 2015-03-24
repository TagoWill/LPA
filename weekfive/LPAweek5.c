#include <stdio.h>
#include <stdlib.h>

void quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];
    
    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        quickSort(valor, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(valor,  i, direita);
    }
}


int main() {
    int n, c=0, t, i;
    int tempodechegada;
    int tempomaquina, result;
    while(scanf("%d %d %d", &c, &n, &t) != EOF){
        int tempo[n];
        tempodechegada=0;
        tempomaquina = 0;
        result=0;
        for(i=0;i<n;i++){
            scanf("%d", &tempo[i]);
        }
        
        quickSort(tempo, 0, n-1);
        
        i=0;
        int batchs[c];
        int posso=0, j=0;
        
        
        for(j=0;j<n%c;j++){
            if(i+j<n){
                batchs[j]=tempo[i+j];
            }else{
                posso=1;
                break;
            }
        }if(j != 0){
            i=i+n%c;
            if(posso==0 && i<n)
                result = batchs[j-1] + t*2;
            else
                result = batchs[j-1] + t;
        }
        while(i<n){
            if(posso==0){
                for(j=0;j<c;j++){
                    if(i+j<n){
                        batchs[j]=tempo[i+j];
                    }else{
                        posso=1;
                        break;
                    }
                }
                i=i+c;
                if(posso==0 && i<n){
                    if(result > batchs[j-1]){
                        result = result + t*2;
                    }else{
                        result = batchs[j-1] + t*2;
                    }
                }else{
                    if(result > batchs[j-1]){
                        result = result + t;
                    }else{
                        result = batchs[j-1] + t;
                    }
                }
            }
        }
        
        
        
        printf("%d\n", result);
    }
    
    
    
    
    return 0;
}
