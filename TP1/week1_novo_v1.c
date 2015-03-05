#include <stdio.h>
#include <stdlib.h>

#define N 300000
#define M 5000

typedef struct ntopicos
{
    int dependencias;
    int ligacoes;
    int proximos[M];
} Ntopicos;

Ntopicos tp[M];
int dias_estudo[M];
int dias_estudo_proximo[M];

int main(){
    int i=0;
    int *a, *b, *aux;
    int j, temp=0, temp2=0;
    int actual, proximo;
    int m, n, temp_max_tp_dia, max_topicos_dia_jocas;
    int max_topicos_dia = 0, dias_desesperado = 0;
    
    scanf("%d %d %d", &m, &n, &max_topicos_dia_jocas);
   
    /* Se o numero de precedencias for 0 o resultado e' logo dado */
    if(n == 0){
        if(m > max_topicos_dia)
            dias_desesperado = 1;
        printf("%d %d\n", m, dias_desesperado);
        return 1;
    }

    /* Se o numero de topicos for 0 o resultado e' automaticamente 0 0 */
    if (m == 0){
        printf("0 0\n");
        return 1;
    }

    /* Cria array */
    for(i = 0; i<n ; i++)
    {
        scanf("%d %d", &actual, &proximo);
        tp[actual].proximos[tp[actual].ligacoes]=proximo;
        tp[actual].ligacoes++;
        tp[proximo].dependencias++;
    }

    /*for(i = 0; i<n; i++)
    {
        printf("no: %d dependencias: %d ligacoes: %d Proximos topicos: ", i, tp[i].dependencias, tp[i].ligacoes);
        for (j = 0; j < tp[i].ligacoes; ++j)
        {
            printf("%d ", tp[i].proximos[j]);
        }
        printf("\n");
    }*/

    /* Procura os topicos que pode estudar no primeiro dia */    
    for (i = 0; i < m; ++i)
    {
        if (tp[i].dependencias==0)
        {
            /*printf("Encontrei o topico %d!\n", i);*/
            dias_estudo[temp_max_tp_dia]=i;
            temp_max_tp_dia++;
        }
    }
    /* Verifica se o primeiro dia tem mais topicos do que aqueles que ele consegue estudar */
    if (temp_max_tp_dia > max_topicos_dia_jocas)
    {
        /*printf("Ultrapassou o numero de topicos que consegue estudar num dia\n");*/
        max_topicos_dia = temp_max_tp_dia;
        dias_desesperado++;
    } else {
        /*printf("Nao ultrapassou o numero de topicos que consegue estudar num dia!\n");*/
        max_topicos_dia = temp_max_tp_dia;
    }

    /* Cria ponteiros para o dia actual de estudo e o dia seguinte */
    a=dias_estudo;
    b=dias_estudo_proximo;

    /* Procura os topicos que pode estudar nos dias seguintes */
    temp = temp_max_tp_dia;
    while(temp_max_tp_dia!=0)
    {
        temp2=0;
        for (j = 0; j < tp[dias_estudo[temp2]].ligacoes; ++j)
        {
            printf("Entrei com j: %d temp2: %d ligacoes: %d que tem dependencias: %d\n", j, temp2, tp[dias_estudo[temp2]].ligacoes, tp[tp[temp2].proximos[j]].dependencias);
            tp[tp[temp2].proximos[j]].dependencias--;

            if (tp[tp[temp2].proximos[j]].dependencias==0)
            {
                printf("Encontrei o topico %d!\n", tp[temp2].proximos[j]);
                dias_estudo_proximo[temp2]=tp[temp2].proximos[j];
                temp2++;
                printf("temp2: %d\n", temp2);
            }


        }
        temp_max_tp_dia--;
        if (temp_max_tp_dia==0)
        {
            printf("Entrei no IF\n");
            temp_max_tp_dia=temp2;
            aux=a;
            a=b;
            b=aux;
            if (temp_max_tp_dia > max_topicos_dia_jocas)
            {
                printf("Ultrapassou o numero de topicos que consegue estudar num dia\n");
                dias_desesperado++;
            }
            if(temp_max_tp_dia > temp)
            {
                printf("Entrei no segundo IF\n");
                temp = temp_max_tp_dia;
            }
        }

    }

    printf("Resultado final: %d %d\n", temp, dias_desesperado);
    return 0;
}