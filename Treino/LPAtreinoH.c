#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int tabela[21][3];
int tamanho=0;

int testarString(int posi, int estado){
    int contador = 0;
    if(posi<tamanho){
        contador += testarString(posi+1, tabela[estado][0]);
        contador += testarString(posi+1, tabela[estado][1]);
    }else if(posi == tamanho && tabela[estado][2] == 1){
        return 1;
    }else{
        return 0;
    }
    return contador;
}


int main() {
    
    int i, n, m, resultado;
    char teste[40];
    while(scanf("%d %d", &n, &m) != EOF){
        tamanho = m;
        for(i=0;i<n+1;i++){
            fgets(teste, 30, stdin);
            sscanf(teste, "%d %d", &tabela[i][0], &tabela[i][1]);
            if(teste[strlen(teste)-2] == '*'){
                tabela[i][2] = 1;
            }
        }
        
        resultado = testarString(0,1);
        
        printf("%d\n", resultado);
        
    }
    return 0;
}
