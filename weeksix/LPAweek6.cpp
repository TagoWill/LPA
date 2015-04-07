#include <stdio.h>
#include <iostream>

#define N 30
#define C 22

int distancias[N][N];
int centroides[C];
int usados[N];
int menorset = 1000000000;
int tdistancia=0;

int ligarNo(int no, int c){
    int i, ligacao=0, distancia=1000000000;
    for(i=0;i<c;i++){
        if(distancia>distancias[centroides[i]][no]){
            distancia=distancias[centroides[i]][no];
            ligacao = i;
        }
    }
    return ligacao;
}

void encontraCentroides(int n, int c, int posi, int escolhido){
    int i, maiordistancia=0, total=0 ;
    
    if(posi<c){
        for(i=escolhido;i<n;i++){
            if(usados[i]==0){
                usados[i]=1;
                centroides[posi]=i;
                encontraCentroides(n, c, posi+1, i);
                usados[i]=0;
            }
        }
    }else{
        for(i=0;i<n;i++){
            if(usados[i]==0){
                int ligacao = ligarNo(i, c);
                
                if(maiordistancia<distancias[centroides[ligacao]][i]){
                    maiordistancia=distancias[centroides[ligacao]][i];
                }
                total+=distancias[centroides[ligacao]][i];
                
                if(menorset<total){
                    return ;
                }
            }
        }
        
        if(menorset>total){
            menorset=total;
            tdistancia=maiordistancia;
        }
    }
}

int main() {
    
    int i, n, c;
    scanf("%d %d", &n, &c);
    for(i=0;i< n*(n-1)/2;i++){
        int no1, no2, distancia;
        scanf("%d %d %d", &no1, &no2, &distancia);
        distancias[no1-1][no2-1] = distancia;
        distancias[no2-1][no1-1] = distancia;
    }

    encontraCentroides(n, c, 0, 0);

    printf("%d\n", tdistancia);
    
    return 0;
}
