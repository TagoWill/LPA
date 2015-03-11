#include <stdio.h>
#include <stdlib.h>

int n, m;
static int ligacoes[101][101];
static int usado[101];
int best =0;

void verificaLigacoes(int posi, int escolhi[], int size){
    int feasible =0;
    int teste;
    int i,j;
    if(best<size){
        best=size;
    }
    for(i=posi;i<n;i++){
        feasible =0;
        if(usado[i] == 0){
            for(j=0;j<size;j++){
                    if(i<escolhi[j])
                        teste = ligacoes[i][escolhi[j]];
                    else
                        teste = ligacoes[escolhi[j]][i];
                if(teste == 1){
                    feasible =1;
                    break;
                }
            }
            if(feasible == 0){
                escolhi[size] = i;
                usado[i] = 1;
                verificaLigacoes(i, escolhi,size+1);
                usado[i] = 0;
            }
        }
    }
}

int main()
{
    int i, valor1, valor2;
    scanf("%d %d", &n, &m);
    int escolhi[n];
    for(i=0;i<m;i++){
        scanf("%d %d", &valor1, &valor2);
        ligacoes[valor1-1][valor2-1] = 1;

    }

    verificaLigacoes(0, escolhi,0);
    printf("%d\n", best);

    return 0;
}
