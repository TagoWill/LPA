#include <stdio.h>
#include <stdlib.h>

#define N 51

int pontosmaximo=0;

void calcularpontosmaximos(int arrayactual[],int valor,int n){
    int i;

    if(pontosmaximo<valor){
        pontosmaximo = valor;
    }
    if(n>1){
        for(i=0;i<n;i++)
        {
            int arraynovo[n], contadordepontos=0, tamanhonovoarray=0, diferente = 0;
            
            int proximo=i+1;
            if(arrayactual[i] == arrayactual[proximo])
            {
                contadordepontos++;
                if(proximo<n)
                {
                    if(i!=0){
                        int posicao =0;
                        do{
                            arraynovo[tamanhonovoarray] = arrayactual[posicao];
                            tamanhonovoarray++;
                            posicao++;
                        }while(posicao<i);
                    }
                    do{
                        if(arrayactual[proximo] == arrayactual[i] && diferente == 0){
                            contadordepontos++;
                        }else{
                            diferente = 1;
                            arraynovo[tamanhonovoarray] = arrayactual[proximo];
                            tamanhonovoarray++;
                        }
                        proximo++;
                    }while(proximo<n);
                
                    calcularpontosmaximos(arraynovo,valor+(contadordepontos*(contadordepontos+1)),tamanhonovoarray);
                
                
                    proximo = i+1;
                    while(arrayactual[i]==arrayactual[proximo] && proximo<n){
                        i++;
                        proximo++;
                    } 
                }
            }
        }
    }
}

int main() {
    int caso,numero_testes,n, i;
    scanf("%d", &numero_testes);
    for(caso=0;caso<numero_testes;caso++){
        
        pontosmaximo=0;
        scanf("%d", &n);
        int array[n];
        
        for(i=0;i<n;i++){
            scanf("%d", &array[i]);
        }
        
        calcularpontosmaximos(array,0,n);
        
        printf("%d\n", pontosmaximo);
    }
    
    return 0;
}