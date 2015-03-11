#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int c;
static char string[7];

void combinacoes(int posi, int n , int actual[],int tamanho){
    int i;
    if(posi == c){
        for(i=0;i<c;i++){
            printf("%c", actual[i]);
        }
        printf("\n");
    }
    for(i=n;i<tamanho;i++){

        actual[posi] = string[i];
        combinacoes(posi+1, i+1, actual, tamanho);

        while(string[i] == string[i+1]){
            i++;
        }

    }
}

int main()
{
    int aux[7];
    scanf("%s %d", string, &c);

    combinacoes(0, 0, aux, strlen(string));

    return 0;
}
