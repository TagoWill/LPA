#include <stdio.h>
#include <stdlib.h>

#define N 300000

int tabela[N][2];

typedef enum { false, true } bool;

typedef struct ntopicos{
    int topico;
    struct ntopicos *next;
} Ntopicos;

void verifica_dependencias(Ntopicos *verifica, int *contador){
    int i;
    Ntopicos *elemento_momento = NULL;
    Ntopicos *proximo_elemento = NULL;
    if(verifica != NULL){
        elemento_momento = verifica;
        while(elemento_momento->next != NULL){
            proximo_elemento = elemento_momento->next;
            for(i=0;i<10;i++){
                if(elemento_momento->topico == tabela[i][1]){
                    if(proximo_elemento->topico == tabela[i][0]){
                        /*printf("ELIMINO O %d\n", elemento_momento->topico);*/
                        *contador = *contador -1;
                        /*eliminar_no(elemento_momento->topico, verifica);*/
                    }
                }else if(proximo_elemento->topico == tabela[i][1]){
                    if(elemento_momento->topico == tabela[i][0]){
                        /*elimina proximo elemento*/
                        /*printf("ELIMINO O %d\n", proximo_elemento->topico);*/
                        /*eliminar_no(proximo_elemento->topico, verifica);*/
                        *contador = *contador -1;
                    }
                }
            }
            elemento_momento = elemento_momento->next;
        }
    }
}

int main(){
    int i=0, j=0;
    int m,n, maxtopics;
    int max_topicos_dia = 0, max_desp_dias = 0;
    bool encontrou;
    scanf("%d %d %d", &m, &n, &maxtopics);
    
    
    for(i = 0; i<n;i++){
        scanf("%d %d", &tabela[i][0], &tabela[i][1]); /* criar tabela */
    }
    
    if (m == 0){
        printf("0 0\n");
        return 1;
    }
    
    Ntopicos *dia = NULL;
    int contador=0;
    for(i=0;i<m;i++){
        encontrou = false;
        j=0;
        do{
            if(i == tabela[j][1]){
                encontrou = true;
                break;
            }
            j++;
        }while(j<n);
        if(!encontrou){
            contador++;
            /*printf("%d\n", contador);*/
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
    if(dia == NULL){
        printf("0 0\n");
        return 1;
    }
    
    contador=0;
    Ntopicos *proximodia = NULL;
    while(dia != NULL){
        printf("%d ", dia->topico);
        i=0;
        contador++;
        do{
            if(dia->topico == tabela[i][0]){
                
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
            i++;
        }while(i<n);
        verifica_dependencias(dia, &contador);
        if(dia->next != NULL){
            dia = dia->next;
        }else{
            
            printf(" - contador %d - ", contador);
            
            if(contador>max_topicos_dia)
                max_topicos_dia = contador;
            if(contador>maxtopics){
                max_desp_dias++;
            }
            
            printf("%d %d\n", max_topicos_dia, max_desp_dias);
            
            contador=0;
            dia = proximodia;
            proximodia = NULL;
        }
    }
    
    
    /*
     Ntopicos *aponta2 = dia;
     printf("%d ", aponta2->topico);
     do{
     aponta2 = aponta2->next;
     printf("%d ", aponta2->topico);
     }while(aponta2->next != NULL);*/
    
    printf("%d %d\n", max_topicos_dia, max_desp_dias);
    return 0;
}
