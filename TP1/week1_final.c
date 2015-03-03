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
   
    if(n == 0){
        if(m > max_topicos_dia)
            dias_desesperado = 1;
        printf("%d %d\n", m, dias_desesperado);
        return 1;
    }

    if (m == 0){
        printf("0 0\n");
        return 1;
    }

    for(i = 0; i<n ; i++)
    {
        scanf("%d %d", &actual, &proximo);
        tp[actual].proximos[tp[actual].ligacoes]=proximo;
        tp[actual].ligacoes++;
        tp[proximo].dependencias++;
    }
  
    for (i = 0; i < m; ++i)
    {
        if (tp[i].dependencias==0)
        {
            dias_estudo[temp]=i;
            temp++;
        }
    }
    temp_max_tp_dia = temp;
    if (temp_max_tp_dia > max_topicos_dia_jocas)
    {
        max_topicos_dia = temp_max_tp_dia;
        dias_desesperado++;
    } else {
        max_topicos_dia = temp_max_tp_dia;
    }
    a=dias_estudo;
    p=dias_estudo_proximo;

    i=0;
    while(i!=temp)
    {
        for (j = 0; j < tp[a[i]].ligacoes; j++)
        {
            tp[tp[a[i]].proximos[j]].dependencias--;

            if (tp[tp[a[i]].proximos[j]].dependencias==0)
            {
                p[temp2]=tp[a[i]].proximos[j];
                temp2++;
            }
        }
        i++;
        if (i==temp)
        {
            temp=temp2;
            temp2=0;
            i=0;
            aux=a;
            a=p;
            p=aux;
            if (temp > max_topicos_dia_jocas)
            {
                dias_desesperado++;
            }
            if(temp > temp_max_tp_dia)
            {
                temp_max_tp_dia = temp;
            }
        }

    }

    printf("%d %d\n", temp_max_tp_dia, dias_desesperado);
    return 0;
}