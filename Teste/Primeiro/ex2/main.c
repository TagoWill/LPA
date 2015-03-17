#include <stdio.h>
#include <stdlib.h>

struct jogador{
    int pecas[9][2];
    int usados[9];
};

struct jogador jogadores[8];
int num_jogadores, num_pecas;
int best=0;

void verJogadas(int contador, int player,int valoranterior){

    int i;
    if(best<contador){
        best=contador;
    }
    for(i=0;i<num_pecas;i++){
        if(jogadores[player].usados[i] == 0){
            if(jogadores[player].pecas[i][0] == valoranterior){
                jogadores[player].usados[i] = 1;
                verJogadas(contador+1, ((player+1)%num_jogadores), jogadores[player].pecas[i][1]);
                jogadores[player].usados[i] = 0;
            }
            if(jogadores[player].pecas[i][1] == valoranterior){
                jogadores[player].usados[i] = 1;
                verJogadas(contador+1, ((player+1)%num_jogadores), jogadores[player].pecas[i][0]);
                jogadores[player].usados[i] = 0;
            }
        }
    }

}

int main()
{
    int i, j, valor1, valor2;
    scanf("%d", &num_jogadores);
    scanf("%d", &num_pecas);

    for(i=0;i<num_jogadores;i++){
        for(j=0;j<num_pecas;j++){
            scanf("%d %d", &valor1, &valor2);
            jogadores[i].pecas[j][0] = valor1;
            jogadores[i].pecas[j][1] = valor2;
        }
    }

    for(i=0;i<num_pecas;i++){
        verJogadas(0, 0, jogadores[0].pecas[i][1]);
    }
    printf("%d\n", best);

    return 0;
}
