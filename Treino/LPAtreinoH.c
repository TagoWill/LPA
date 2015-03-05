#include <stdio.h>
#include <stdlib.h>

int tabela[21][3];
int contador=0;
int tamanho=0;

int testarString(int posi, int estado, int tamanho){
    
    if(posi<tamanho){
        testarString(posi+1, tabela[estado][0], tamanho);
        testarString(posi+1, tabela[estado][1], tamanho);
    }
    
    if(posi == tamanho && tabela[estado][2] == 1){
        contador++;
        return 0;
    }
    return 0;
}


int main() {
    
    int i, j, n, m;
    char teste;
    while(scanf("%d %d", &n, &m) != EOF){
        contador = 0;
        tamanho = m;
        for(i=1;i<n+1;i++){
            for(j=0;j<2;j++){
                scanf("%s", &teste);
                if(teste == '*'){
                    tabela[i-1][2] = 1;
                    scanf("%s", &teste);
                    tabela[i][j] = teste - '0';
                }else{
                tabela[i][j] = teste - '0';
                }
            }
        }
        
        
        testarString(1, tabela[1][0], tamanho);
        testarString(1, tabela[1][1], tamanho);
        
        printf("%d\n", contador);
        
    }
    return 0;
}
