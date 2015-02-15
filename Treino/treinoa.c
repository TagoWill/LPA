#include <stdio.h>
#include <stdlib.h>

#define N 30
#define M 7
#define TOTAL 400


static int tabuleiro[TOTAL][TOTAL]; /*inicializa a matriz a zeros*/


/*funcao verificaPosibilidades recebe como argumentos a possicao de cada cavalo e quantos moviemtos ainda tem tem*/
int verificaPosibilidades(int novox,int novoy,int novom){
    /*verifica se não sai dos limites do tabuleiro*/
    if(novox < 0 || novox > 400){
        return 0;
    }
    if(novoy < 0 || novoy > 400){
        return 0;
    }
    /*marca a posicao actual na matrix*/
    tabuleiro[novox][novoy] = 1;
    /*se ainda tiver movimentos entao entra na recursiva com as novas posicoes para verificacao*/
    if(novom != 0){
        verificaPosibilidades(novox-1, novoy+2, novom-1);
        verificaPosibilidades(novox+1, novoy+2, novom-1);
        verificaPosibilidades(novox-2, novoy+1, novom-1);
        verificaPosibilidades(novox-2, novoy-1, novom-1);
        verificaPosibilidades(novox+2, novoy+1, novom-1);
        verificaPosibilidades(novox+2, novoy-1, novom-1);
        verificaPosibilidades(novox-1, novoy-2, novom-1);
        verificaPosibilidades(novox+1, novoy-2, novom-1);
    }
    return 0;
}

int main() {
    
    int i, j;
    int n, m, x, y;
    int resultado = 0;
    
    scanf("%d", &n); /*Le quantos Cavalos podem exisitir*/
    
    /*Insere cada Cavalo numa matrix de 400x400 para evitar numeros negativos e testa quais os seus movimentos possiveis*/
    for (i=0;i<n;i++){
        scanf("%d %d %d", &x, &y, &m);
        x = x + 200;
        y = y + 200;
        verificaPosibilidades(x, y, m);
    }
    
    /*verifica quantas casas individuais foram usadas na matriz*/
    for (i=0;i<TOTAL;i++){
        for(j=0;j<TOTAL;j++){
            if(tabuleiro[i][j] != 0){
                resultado ++;
            }
        }
    }
    /*imprime o resultado*/
    printf("%d\n", resultado);
    return 0;
}
