#include <stdio.h>
#include <stdlib.h>

#define N 51

int pontosmaximo=0;
static int array[N][2];
int continua=0;

void calcularpontosmaximos(int valor, int nivel ,int n){
    if(continua==0){
    //printf("nivel - %d\n",nivel);
    int i, contadordepontos=0, teste, teste2;
    for(i=0;i<n;i++){
        //printf("no - %d\n",array[i][0]);
        if(array[i][1] == 0){
            
            int proximo=i+1, fixo;
            while(array[proximo][1] == 1 && proximo<n){
                proximo++;
            }
            fixo = proximo;
            if(proximo<n){
                if(array[i][0] == array[proximo][0]){
                    contadordepontos++;
                    array[i][1]=1;
                    do{
                        contadordepontos++;
                        array[proximo][1]=1;
                        proximo++;
                        while(array[proximo][1] == 1){
                            proximo++;
                        }
                    }while(array[proximo][0] == array[i][0]);
                    
                    for(teste2=0;teste2<2;teste2++){
                        for(teste=0;teste<n;teste++){
                            printf("%d ",array[teste][teste2]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                    
                    calcularpontosmaximos(valor+(contadordepontos*(contadordepontos+1)),nivel+1 ,n);
                    
                    contadordepontos=0;
                    proximo=fixo;
                    array[i][1]=0;
                    do{
                        array[proximo][1]=0;
                        proximo++;
                        while(array[proximo][1] == 1 && array[proximo][0] != array[i][0] && proximo<n){
                            proximo++;
                        }
                    }while(array[proximo][0] == array[i][0]);
                }
            }
        }
    }
    if(pontosmaximo<valor){
        pontosmaximo = valor;
    }
        int lolololol=0, aux=0;
        for(lolololol=0;lolololol<n;lolololol++){
            if(array[lolololol][1] == 0){
                aux = 1;
            }
        }
        if(aux == 0){
            continua = 1;
        }
           
}
}

int main() {
    int caso,numero_testes,n, i;
    scanf("%d", &numero_testes);
    for(caso=0;caso<numero_testes;caso++){
        
        pontosmaximo=0;
        scanf("%d", &n);
        
        for(i=0;i<n;i++){
            scanf("%d", &array[i][0]);
            array[i][1]=0;
        }
        
        calcularpontosmaximos(0,0,n);
        printf("%d\n", pontosmaximo);
    }
    
    return 0;
}
