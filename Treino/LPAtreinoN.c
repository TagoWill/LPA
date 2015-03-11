#include <stdio.h>
#include <stdlib.h>

static int matriz[26][230];
static int examesusados[26];
int slots = 20000;

int verSlots(int arrayactual[], int numeroslot, int numeroexames){
    int i, j, marcar;
    for(i=0;i<n;i++){
        int aux[k];
        marcar = 0;
        if(examesusados[i] == 0){
            for(j=0;j<k;j++){
                if(matriz[i][j] == 1 && arrayactual[j] == 1){
                    marcar =1;
                    break;
                }else{
                    if(matriz[i][j] == 1)
                        aux[j] = 1;
                    else
                        aux[j] = arrayactual[j];
                }
            }
            if(marcar == 0){
                numeroexames++;
                examesusados[i] = 1;
                for(j=0;j<k;j++){
                    arrayactual[j] = aux[j];
                }
            }
        }
    }
    if(numeroexames == n){
        if(numeroslot < slots){
            slots= numeroslot;
        }
    }else{
        int aux[k];
        verSlots(aux,numeroslot + 1, numeroexames);
    }
    
}


int main() {
    
    int i, n, k, exame1, exame2;
    
    scanf("%d %d", &n, &k);
    int aux[k];
    for(i=0;i<k;i++){
        scanf("%d %d", &exame1, &exame2);
        matriz[i][exame1-1]=1;
        matriz[i][exame2-1]=1;
    }
    verSlots(aux, 1, 0);
    
    
    return 0;
}
