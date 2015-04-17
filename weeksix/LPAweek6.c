#include <stdio.h>
#include <stdlib.h>

int distancias[30][30];
int centroides[22];
int resultado = 0;
int n, c;

int vouescolher (int posi){
    int i, j, maiordistancia=0, menordistancia=0 ;
    for(i=0; i<posi; i++){
        menordistancia = 0;
        
        for(j=0;j<n;j++){
            
            if((centroides[j] == 1 || j>=posi) && centroides[i] == 0){
                if(distancias[i][j]<menordistancia || menordistancia == 0)
                    menordistancia=distancias[i][j];
            }
        }
        
        if(maiordistancia < menordistancia || maiordistancia == 0){
            maiordistancia = menordistancia;
        }
    }
    
    if(resultado>maiordistancia || resultado==0){
        return 1;
    }
    return 0;
}

void encontraCentroides(int posi, int num_centroids){
    int i, j;
    if(num_centroids == c){
        int maiordistancia=0, menordistancia=0;
        
        for(i = 0; i < n; i++){
            menordistancia = 0;
            
            for(j = 0; j < n; j++){
                
                if(centroides[j] == 1 && centroides[i] == 0){
                    if(distancias[i][j]<menordistancia || menordistancia == 0)
                        menordistancia=distancias[i][j];
                }
            }
            
            if(maiordistancia < menordistancia || maiordistancia == 0){
                maiordistancia = menordistancia;
            }
        }
        
        if(resultado>maiordistancia || resultado==0){
            resultado=maiordistancia;
        }
    }else{
        for(i = posi; i < n; i++){
            if(vouescolher(i)==1){
                centroides[i]=1;
                encontraCentroides(i+1, num_centroids+1);
                centroides[i]=0;
            }else{
                i = n;
            }
        }
    }
}

int main() {
    
    int i, no1, no2, distancia;
    scanf("%d %d", &n, &c);
    for(i=0;i < n*(n-1)/2;i++){
        scanf("%d %d %d", &no1, &no2, &distancia);
        distancias[no1-1][no2-1] = distancia;
        distancias[no2-1][no1-1] = distancia;
    }
    
    encontraCentroides(0, 0);
    
    printf("%d\n", resultado);
    
    return 0;
}
