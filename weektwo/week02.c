#include <stdio.h>
#include <stdlib.h>

/*    D   L   R   U Imagem*/
int tabela[24][4]= {
    {17, 13, 5, 21}, /* 1*/
    {18, 14, 6, 24}, /* 2*/
    {19, 15, 7, 23}, /* 3*/
    {20, 16, 8, 22}, /* 4*/
    {8, 1, 9, 6}, /* 5*/
    {5, 2, 10, 7}, /* 6*/
    {6, 3, 11, 8}, /* 7*/
    {7, 4, 12, 5}, /* 8*/
    {23, 5, 13, 19}, /* 9*/
    {22, 6, 14, 20}, /*10*/
    {21, 7, 15, 17}, /*11*/
    {24, 8, 16, 18}, /*12*/
    {14, 9, 1, 16}, /*13*/
    {15, 10, 2, 13}, /*14*/
    {16, 11, 3, 14}, /*15*/
    {13, 12, 4, 15}, /*16*/
    {11, 20, 18, 1}, /*17*/
    {12, 17, 19, 2}, /*18*/
    {9, 18, 20, 3}, /*19*/
    {10, 19, 17, 4}, /*20*/
    {1, 24, 22, 11}, /*21*/
    {4, 21, 23, 10}, /*22*/
    {3, 22, 24, 9}, /*23*/
    {2, 23, 21, 12}}; /*24*/;

struct movimento{
    int sentido;
    int linha;
};

struct movimento teste[5], resultado[5];
int max = 5;

void copiavectores(){
    int i;
    for(i=0;i<max;i++){
        resultado[i]=teste[i];
    }
}


int rotacaocubo(int a, int b, int c, int d,int rotacao, int linha,int posicao){
    int i = 0, copia = 0;
    teste[posicao].sentido = rotacao;
    teste[posicao].linha = linha;
    
    if(rotacao==1 || rotacao==2){
        if(linha == 0){
            a = tabela[a-1][rotacao];
            b = tabela[b-1][rotacao];
        }else{
            c = tabela[c-1][rotacao];
            d = tabela[d-1][rotacao];
        }
    }else{
        if(linha == 0){
            a = tabela[a-1][rotacao];
            c = tabela[c-1][rotacao];
        }else{
            b = tabela[b-1][rotacao];
            d = tabela[d-1][rotacao];
        }
    }
    
    posicao++;
    
    if (posicao<=max){
        if(a == 1 && b == 1 && c == 1 && d == 1){
            if(posicao==max){
            
                while(i<max){
                    if(resultado[i].sentido < teste[i].sentido){
                        copia = 1;
                        break;
                    }
                    if(resultado[i].sentido == teste[i].sentido){
                        if(resultado[i].linha < teste[i].linha){
                            copia = 1;
                            break;
                        }
                    }
                    i++;
                }
                if(copia == 0){
                    copiavectores();
                }
            }
            if(posicao<max){
                max = posicao;
                copiavectores();
            }
            return 0;
        }
        rotacaocubo(a,b,c,d, 0, 0, posicao);
        rotacaocubo(a,b,c,d, 0, 1, posicao);
        rotacaocubo(a,b,c,d, 1, 0, posicao);
        rotacaocubo(a,b,c,d, 1, 1, posicao);
        rotacaocubo(a,b,c,d, 2, 0, posicao);
        rotacaocubo(a,b,c,d, 2, 1, posicao);
        rotacaocubo(a,b,c,d, 3, 0, posicao);
        rotacaocubo(a,b,c,d, 3, 1, posicao);
    }
    return 0;
}

int main() {
    int i;
    int cubo[2][2];
    
    for(i=0;i<max;i++){
        resultado[i].sentido = 6;
    }
    
    scanf("%d", &max);
    
    scanf("%d %d\n%d %d", &cubo[0][0], &cubo[0][1], &cubo[1][0], &cubo[1][1]);
    
    rotacaocubo(cubo[0][0],cubo[0][1],cubo[1][0],cubo[1][1], 0, 0, 0);
    rotacaocubo(cubo[0][0],cubo[0][1],cubo[1][0],cubo[1][1], 0, 1, 0);
    rotacaocubo(cubo[0][0],cubo[0][1],cubo[1][0],cubo[1][1], 1, 0, 0);
    rotacaocubo(cubo[0][0],cubo[0][1],cubo[1][0],cubo[1][1], 1, 1, 0);
    rotacaocubo(cubo[0][0],cubo[0][1],cubo[1][0],cubo[1][1], 2, 0, 0);
    rotacaocubo(cubo[0][0],cubo[0][1],cubo[1][0],cubo[1][1], 2, 1, 0);
    rotacaocubo(cubo[0][0],cubo[0][1],cubo[1][0],cubo[1][1], 3, 0, 0);
    rotacaocubo(cubo[0][0],cubo[0][1],cubo[1][0],cubo[1][1], 3, 1, 0);
    
    
    for(i=0;i<max;i++){
        if(resultado[i].sentido == 0){
            printf("D");
        }
        if(resultado[i].sentido == 1){
            printf("L");
        }
        if(resultado[i].sentido == 2){
            printf("R");
        }
        if(resultado[i].sentido == 3){
            printf("U");
        }
        printf("%d ", resultado[i].linha+1);
    }
    printf("\n");
    
    return 0;
}
