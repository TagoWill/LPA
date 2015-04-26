#include <stdlib.h>
#include <stdio.h>

#define N 1000

struct dia{
    int populacao;
    int depedencias;
    int ligacoes;
    int ponteiros[N];
    int usado;
};




int main(){
    int total;
    int semanas=0;
    int i, j;
    int populacao=0, nosligados=0;
    int n;
    int contador=0, contador2=0;
    while(scanf("%d %d", &n, &total)!=EOF){
    struct dia tabela[n];
    int aux[n], aux2[n];
    
    /*Inicializa*/
    for(i=0;i<n;i++){
        tabela[i].populacao = 0;
        tabela[i].depedencias = 0;
        tabela[i].ligacoes = 0;
        tabela[i].usado=0;
    }
    
    int id;
    /*Contruir array de estrutura*/
    for(i=0;i<n;i++){
        scanf("%d %d", &populacao, &nosligados);
        tabela[i].populacao = populacao;
        tabela[i].ligacoes = nosligados;
        for(j=0;j<nosligados;j++){
            scanf("%d", &id);
            tabela[i].ponteiros[j] = id;
            tabela[id].depedencias++;
        }
    }
    
    /*buscar os primeiros elementos*/
    total = total - tabela[0].populacao;
    tabela[i].usado =1;
    aux[contador] = 0;
    contador++;
    for(i=1; i<n; i++){
        if(tabela[i].depedencias == 0){
            tabela[i].usado=1;
            aux[contador] = i;
            contador++;
        }
    }
    semanas++;
    /*Verificar se existem nos para continuar*/
    if(total<=0){
        printf ("%d\n", semanas);
    }
    
    int *a, *b, *c;
    
    a = aux;
    b = aux2;
    j=0;
    int posso = 0;
    while(contador != 0 && posso==0){
        contador2=0;
        while(j<contador && posso == 0){
            for(i=0;i<tabela[a[j]].ligacoes;i++){
                if(tabela[tabela[a[j]].ponteiros[i]].usado == 0){
                    tabela[tabela[a[j]].ponteiros[i]].usado = 1;
                    total = total - tabela[tabela[a[j]].ponteiros[i]].populacao;
                    b[contador2] = tabela[a[j]].ponteiros[i];
                    contador2++;
                }
            }
            j++;
            
        };
        semanas++;
        contador = contador2;
        j=0;
        c = a;
        a = b;
        b = c;
        if(total<=0){
            posso=1;
        }
    }
    if(total<=0){
        printf("%d\n", semanas);
    }else{
        printf("Safe!\n");
    }
    posso=0;
    }
    return 0;
}
