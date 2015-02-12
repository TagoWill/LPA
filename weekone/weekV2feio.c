#include <stdlib.h>
#include <stdio.h>

#define M 5000
#define N 300000

struct dia{
    int depedencias;
    int ligacoes;
    int ponteiros[M];
};

struct dia tabela[M];

int main(){
    
    int i, j;
    int valor1=0, valor2=0;
    int m, n, consigoestudar;
    int maxtopicosdia=0, desesperodia=0, contador=0, contador2=0;
    int aux[M], aux2[M];
    scanf("%d %d %d", &m, &n, &consigoestudar);
    
    /*Inicializa*/
    for(i=0;i<m;i++){
        tabela[i].depedencias = 0;
        tabela[i].ligacoes = 0;
    }
    
    /*Contruir array de estrutura*/
    for(i=0;i<n;i++){
        scanf("%d %d", &valor1, &valor2);
        tabela[valor1].ponteiros[tabela[valor1].ligacoes] = valor2;
        tabela[valor1].ligacoes = tabela[valor1].ligacoes + 1;
        tabela[valor2].depedencias = tabela[valor2].depedencias + 1;
    }
    
    /*buscar os primeiros elementos*/
    for(i=0; i<m; i++){
        
        if(tabela[i].depedencias == 0){
            aux[contador] = i;
            contador++;
            printf("depedencias %d\t", tabela[i].depedencias);
            printf("ligacoes %d\n", tabela[i].ligacoes);
        }
    }
    
    for(i=0;i<m;i++){
        printf("sou o no %d - %d %d - ligacao com ", i, tabela[i].depedencias, tabela[i].ligacoes);
        for(j=0;j<tabela[i].ligacoes;j++){
            printf("%d ", tabela[i].ponteiros[j]);
        }
        printf("\n");
        
    }
    
    
    /*Verificar se existem nos para continuar*/
    if(contador == 0){
        printf("0 0\n");
        return 0;
    }else{
        if(contador > maxtopicosdia){
            maxtopicosdia = contador;
        }
        if(contador > consigoestudar){
            desesperodia++;
        }
    }
    
    int *a, *b, *c;
    
    a = aux;
    b = aux2;
    j=0;
    int numeronoaux, ponteironumero, numeronatabela;
    while(contador != 0){
        contador2=0;
        while(j<contador){
            numeronoaux = a[j];
            for(i=0;i<tabela[a[j]].ligacoes;i++){
                ponteironumero = tabela[a[j]].ponteiros[i];
                numeronatabela = tabela[tabela[a[j]].ponteiros[i]].depedencias;
                tabela[tabela[a[j]].ponteiros[i]].depedencias = tabela[tabela[a[j]].ponteiros[i]].depedencias - 1;
                if(tabela[tabela[a[j]].ponteiros[i]].depedencias == 0){
                    b[contador2] = tabela[a[j]].ponteiros[i];
                    contador2++;
                }
            }
            j++;
            
        };
        contador = contador2;
        j=0;
        c = a;
        a = b;
        b = c;
        if(contador > maxtopicosdia){
            maxtopicosdia = contador;
        }
        if(contador > consigoestudar){
            desesperodia++;
        }
    }
    printf("final %d %d\n", maxtopicosdia, desesperodia);
    
    return 0;
}
