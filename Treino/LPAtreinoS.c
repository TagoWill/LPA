#include <stdio.h>
#include <stdlib.h>

static int matriz[13][13];
static int ligacoes[13];
static int usado[13];

int main() {
    int n, m, k, i;
    int no1, no2, custo;
    while(scanf("%d %d %d", &n, &m, &k) != EOF){
        
        int resultado = 10000000;
        int total = 10000000;
        
        for(i=0;i<m;i++){
            scanf("%d %d %d", &no1, &no2, &custo);
            matriz[no1-1][no2-1] = custo;
            matriz[no2-1][no1-1] = custo;
        }
        
        usado[0] = 1;
        for(i=0;i<n;i++){
            if(matriz[0][i] > 0){
                usado[i] = 1;
                resultado = criarLigacoes();
                usado[i] = 0;
            }
            if(total<resultado){
                total = resultado;
            }
        }
        
        
    }
    
    return 0;
}
