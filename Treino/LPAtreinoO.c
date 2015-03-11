#include <stdio.h>
#include <stdlib.h>

int usado[100];
int ligacoes[100][100];
int best = 0, n;

void verificaCoisas(int escolhi[], int size){
    int feasible = 0;
    int i, j;
    if(best<size){
        best=size;
    }
    for(i=0; i<n; i++){
        feasible = 0;
        if(usado[i] == 0){
            for(j=0;j<size;j++){
                if(ligacoes[i][escolhi[j]] == 1){
                    feasible = 1;
                    break;
                }
            }
            if(feasible == 0){
                escolhi[size] = i;
                usado[i] = 1;
                verificaCoisas(escolhi, size+1);
                usado[i] = 0;
            }
        }
        
    }
    
}

int main() {
    int m, i;
    scanf("%d %d", &n, &m);
    int aux1, aux2;
    int escolhi[n];
    for(i=0;i<m;i++){
        scanf("%d %d", &aux1, &aux2);
        ligacoes[aux1][aux2] = 1;
        ligacoes[aux2][aux1] = 1;
    }
    

    verificaCoisas(escolhi, 0);
    
    printf("%d\n", best);

    return 0;
}
