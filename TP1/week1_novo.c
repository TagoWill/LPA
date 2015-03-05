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
    int *a, *p, *aux;
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
            dias_estudo[temp]=i;
            temp++;
        }
    }
    temp_max_tp_dia = temp;
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
    /*printf("temp: %d max_topicos_dia: %d dias_desesperado: %d\n", temp, max_topicos_dia, dias_desesperado);*/
    /* Cria ponteiros para o dia actual de estudo e o dia seguinte */
    a=dias_estudo;
    p=dias_estudo_proximo;

    /*for (i = 0; i < temp; ++i)
    {
        printf("i: %d topico estudo: %d tp: %d ligacoes: %d dependencias: %d\n", i, dias_estudo[i], dias_estudo[temp], tp[dias_estudo[i]].ligacoes, tp[dias_estudo[i]].dependencias);
    }*/
    i=0;
    /* Procura os topicos que pode estudar nos dias seguintes */
    while(i!=temp)
    {
        printf("Entrei no while com temp: %d i: %d\n", temp, i);
        
        for (j = 0; j < tp[a[i]].ligacoes; j++)
        {
            printf("j: %d temp2: %d dia estudo: %d ligacoes: %d", j, temp2, a[i], tp[a[i]].ligacoes);
            printf(" Proximo topico: %d Dependencias: %d\n", tp[a[i]].proximos[j], tp[tp[a[i]].proximos[j]].dependencias);
            tp[tp[a[i]].proximos[j]].dependencias--;

            if (tp[tp[a[i]].proximos[j]].dependencias==0)
            {
                printf("Encontrei o topico %d!\n", tp[a[i]].proximos[j]);
                p[temp2]=tp[a[i]].proximos[j];
                temp2++;
                printf("temp2: %d\n", temp2);
            }
        }
        i++;
        if (i==temp)
        {
            printf("Entrei no IF\n");
            temp=temp2;
            temp2=0;
            i=0;
            aux=a;
            a=p;
            p=aux;
            if (temp > max_topicos_dia_jocas)
            {
                printf("Ultrapassou o numero de topicos que consegue estudar num dia\n");
                dias_desesperado++;
            }
            if(temp > temp_max_tp_dia)
            {
                printf("Entrei no segundo IF\n");
                temp_max_tp_dia = temp;
            }
        }

    }

    printf("Resultado final: %d %d\n", temp_max_tp_dia, dias_desesperado);
    return 0;
}