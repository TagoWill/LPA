#include <stdlib.h>
#include <stdio.h>

struct reuniao{
    int inicio;
    int fim;
};

void quickSort(struct reuniao reunioes[], int esquerda, int direita){
    int i, j, x ,y, y2;
    i = esquerda;
    j=direita;
    x=reunioes[(esquerda+direita)/2].fim;
    while(i<=j){
        while(reunioes[i].fim<x && i<direita){
            i++;
        }
        while(reunioes[j].fim>x && j>esquerda){
            j--;
        }
        if(i<=j){
            y=reunioes[i].inicio;
            y2=reunioes[i].fim;
            reunioes[i].inicio=reunioes[j].inicio;
            reunioes[i].fim=reunioes[j].fim;
            reunioes[j].inicio=y;
            reunioes[j].fim=y2;
            i++;
            j--;
        }
    }
    if(j>esquerda){
        quickSort(reunioes, esquerda, j);
    }
    if(i<direita){
        quickSort(reunioes, i, direita);
    }
}

int main()
{
    int nreunioes,i;
    struct reuniao reunioes[201];
    scanf("%d", &nreunioes);
    for(i=0;i<nreunioes;i++){
        int aux1, aux2;
        scanf("%d %d", &aux1, &aux2);
        reunioes[i].inicio = aux1;
        reunioes[i].fim = aux2;
    }

    quickSort(reunioes, 0, nreunioes-1);

    int resultado=1;
    int j=0;

    for(i=0;i<nreunioes;i++){
        if(reunioes[i].inicio >= reunioes[j].fim){
            j=i;
            resultado++;
        }
    }
    printf("%d\n", resultado);


    return 0;
}
