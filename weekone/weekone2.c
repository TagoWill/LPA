#include <stdio.h>
#include <stdlib.h>

#define N 300000
#define M 500000

int tabela[N][2];
int usado[M];

typedef enum { false, true } bool;

typedef struct ntopicos{
    int topico;
    struct ntopicos *next;
} Ntopicos;

int verifica2(int no, int n){
    int i;
    for(i=0;i<n;i++){
        if(tabela[i][1] == no){
            if(usado[tabela[i][0]] == 0){
                return 0;
            }
        }
    }
    return 1;
}

void marcar(Ntopicos *lista, int *max_topicos_dia, int *max_desp_dias, int maxtopics){
    int contador = 0;
    while(lista != NULL){
        usado[lista->topico] = 1;
        lista = lista->next;
        contador++;
    }
    if(contador>*max_topicos_dia)
        *max_topicos_dia = contador;
    if(contador>maxtopics)
        *max_desp_dias = *max_desp_dias + 1;
}

int main(){
    int i=0, j=0;
    int m,n, maxtopics;
    int max_topicos_dia = 0, max_desp_dias = 0;
    bool encontrou = false;
    scanf("%d %d %d", &m, &n, &maxtopics);
    
    if(n == 0){
        if(m>maxtopics)
            max_desp_dias++;
        printf("%d %d\n", m, max_desp_dias);
        return 1;
    }
    
    for(i = 0; i<n;i++){
        scanf("%d %d", &tabela[i][0], &tabela[i][1]); /* criar tabela */
    }
    
    if (m == 0){
        printf("0 0\n");
        return 1;
    }
    
    Ntopicos *dia = NULL;
    for(i=0;i<m;i++){
        encontrou = false;
        j=0;
        do{
            if(n!=0){
                if(i == tabela[j][1]){
                    
                    encontrou = true;
                    break;
                }
            }
            j++;
        }while(j<n);
        if(!encontrou){
            Ntopicos *aux = malloc(sizeof(Ntopicos));
            aux->topico = i;
            if(dia == NULL){
                dia = aux;
            }else{
                Ntopicos *aponta = dia;
                while(aponta->next != NULL){
                    aponta = aponta->next;
                }
                aponta->next = aux;
            }
        }
    }
    
    marcar(dia, &max_topicos_dia, &max_desp_dias, maxtopics);
    


    if(dia == NULL){
        printf("0 0\n");
        return 1;
    }
    
    Ntopicos *proximodia = NULL;
    while(dia != NULL){
        i=0;
        do{
            if(dia->topico == tabela[i][0]){
                if(verifica2(tabela[i][1], n)){
                    Ntopicos *aux = malloc(sizeof(Ntopicos));
                    aux->topico = tabela[i][1];
                    if(proximodia == NULL){
                        proximodia = aux;
                    }else{
                        Ntopicos *aponta = proximodia;
                        while(aponta->next != NULL){
                            aponta = aponta->next;
                        }
                        aponta->next = aux;
                    }
                }
            }
            i++;
        }while(i<n);

        if(dia->next != NULL){
            dia = dia->next;
        }else{
            
            marcar(proximodia, &max_topicos_dia, &max_desp_dias, maxtopics);
            
            dia = proximodia;
            proximodia = NULL;
        }
    }
    
    printf("%d %d\n", max_topicos_dia, max_desp_dias);
    return 0;
}
