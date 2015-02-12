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

int verifica2(int no, int n)
{
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

void marcar(Ntopicos *lista)
{
    while(lista != NULL){
        usado[lista->topico] = 1;
        lista = lista->next;
    }
}

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
    bool encontrou = false;
    scanf("%d %d %d", &m, &n, &maxtopics);
   
    /* Se o numero de precedencias for 0 o resultado e' logo dado */
    if(n == 0){
        if(m>maxtopics)
            max_desp_dias++;
        printf("%d %d\n", m, max_desp_dias);
        return 1;
    }

    /* Se o numero de topicos for 0 o resultado e' automaticamente 0 0 */
    if (m == 0){
        printf("0 0\n");
        return 1;
    }

    /* Cria tabela */
    for(i = 0; i<n;i++){
        scanf("%d %d", &tabela[i][0], &tabela[i][1]); 
    }

     /* Imprime tabela com precedencias */
    for(i=0;i<n;i++){
        printf("precedencias: %d %d\n", tabela[i][0], tabela[i][1]);
    }
    /* Imprime topicos usados */
    for(i=0;i<m;i++){
        printf("topico %d (estudado): %d\n", i, usado[i]);
    }
    
    /* Procura a tabela por topicos sem precedencias */
    Ntopicos *dia = NULL;
    int contador=0;
    for(i=0;i<m;i++){
        encontrou = false;
        j=0;
        do{
            if(n!=0){
                if(i == tabela[j][1])
                {
                    /* se encontra pa'ra o ciclo e prossegue */ 
                    encontrou = true;
                    break;
                }
            }
            j++;
        }while(j<n);
        if(!encontrou)
        {
            /* coloca topicos no 1o dia */
            contador++;
            //usado[i] = 1;
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
    /* Funcao para marcar o topico como estudado no array usados e avancar na lista */
    marcar(dia);
    
    /* verifica se o contador esta superior ao numero de topicos estudados nesse dia e se sim iguala o num de topicos estudados nesse dia ao contador */
    if(contador>max_topicos_dia)
        max_topicos_dia = contador;
    /* Verifica se o contador esta superior ao input maxtopics e se for verdade aumenta o numero de dias em que o jocas vai ficar desesperado */
    if(contador>maxtopics){
        max_desp_dias++;
    }
    
    printf("Verifica Contador: %d\n", contador);
    
    for(i=0;i<m;i++){
        printf("topico %d (estudado): %d\n", i, usado[i]);
    }
    /* Se o primeiro dia estiver vazio ja pode terminar o programa */
    if(dia == NULL){
        printf("0 0\n");
        return 1;
    }
    /* Procura precedencias para os proximos dias */
    contador=0;
    Ntopicos *proximodia = NULL;
    while(dia != NULL){
        printf("%d ", dia->topico);
        i=0;
        do{
            if(dia->topico == tabela[i][0]){
                if(verifica2(tabela[i][1], n)){
                    contador++;
                    //usado[tabela[i][1]] = 1;
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
        //verifica_dependencias(dia, &contador);
        if(dia->next != NULL){
            dia = dia->next;
        }else{
            
            printf("\nContador %d - ", contador);
            
            marcar(proximodia);
            
            if(contador>max_topicos_dia)
                max_topicos_dia = contador;
            if(contador>maxtopics){
                max_desp_dias++;
            }
            
            printf("Resultado actual: %d %d\n", max_topicos_dia, max_desp_dias);
            
            contador=0;
            dia = proximodia;
            proximodia = NULL;
        }
    }
    
    for(i=0;i<m;i++){
        printf("topico %d (estudado): %d\n", i, usado[i]);
    }
    
    /*
     Ntopicos *aponta2 = dia;
     printf("%d ", aponta2->topico);
     do{
     aponta2 = aponta2->next;
     printf("%d ", aponta2->topico);
     }while(aponta2->next != NULL);
     */
    
    printf("Resultado final: %d %d\n", max_topicos_dia, max_desp_dias);
    return 0;
}
