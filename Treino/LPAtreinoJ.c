
#include <stdio.h>
#include <stdlib.h>

int lado = 0;

int verificaQuadrado(int ciclo, int arrayactua[], int m){
    int i;
    int consegui=0;
    int soma, proximo, naomeperder=0;
    if(m!=0 && ciclo<4){
        for(i=0;i<m;i++){
            int novoarray[21];
            naomeperder =0;
            
            if(i!=0){
                proximo =0;
                do{
                    novoarray[naomeperder] = arrayactua[proximo];
                    naomeperder++;
                    proximo++;
                }while(proximo<i);
            }
            
            if(arrayactua[i]<=lado){
                
                soma = arrayactua[i];
                proximo = i+1;
                while(soma<lado && proximo<m){
                    
                    if(soma + arrayactua[proximo]<= lado)
                        soma = soma + arrayactua[proximo];
                    else{
                        novoarray[naomeperder]= arrayactua[proximo];
                        naomeperder++;
                    }
                    proximo++;
                }
                if(soma == lado){
                    while(proximo<m){
                        novoarray[naomeperder] = arrayactua[proximo];
                        proximo++;
                        naomeperder++;
                    }
                    consegui = verificaQuadrado(ciclo+1, novoarray, naomeperder);
                }
            }else{
                return 0;
            }
            if(consegui == 1){
                return 1;
            }
        }
    }else{
        if(m!=0)
            return 0;
        else
            return 1;
    }
    
    return 0;
}


int main() {
    int i, j, n, m;
    int soma =0;
    float teste;
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        int array[21];
        soma=0;
        scanf("%d", &m);
        for(j=0;j<m;j++){
            scanf("%d", &array[j]);
            soma = soma + array[j];
        }
        teste = soma/4.0;
        
        int teste2 = teste * 100;
        
        if((teste2) % 100 == 0){
            lado = soma/4;
            if(verificaQuadrado(0, array, m)==1){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
        else{
            printf("no\n");
        }
        
    }
    
    return 0;
}
