#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 128

int simnao = 0;
char cadeia[TAMANHO];

/*A funcao verifica recebe como argumentos o caracter actual e a posicao a frente para a 
    verificacao acontecer e ainda o tamanho da string*/
int verificar(char atestar, int posicao, int tamanho){
    int casa;
    casa = posicao; /*Somente para debug. Remover no fim*/
    
    /*caso a variavel sim nao estiver a zero, significa que a string ate ao momento esta correcta
        entao podemos continuar a verificala se ainda n a terminamos*/
        if (simnao == 0) {
            
            /*do while para termos a certeza que quando estamos a fazer a verificacao
                esta chegue ao fim da string e nao termine a meio*/
            do{
                /*Se encontrar um paretices aberto tem que entrar na recursica com as novas posicoes para verificacao. Caso encontre paretices fechado, verifica se termina o parentices aberto actual. Caso nao o termine teve modificar a variavel simnao (para string errada) e terminar as verificaoes que jao n sao mais necessarias fazer*/
                if(atestar == '(' || atestar == '['){
                    if(cadeia[posicao] == '(' || cadeia[posicao] == '['){
                        posicao = verificar(cadeia[posicao], posicao+1, tamanho);
                    }
                    if(cadeia[posicao] == ')'){
                        if  (atestar == '(')
                            return posicao+1;
                        else{
                            simnao = 1;
                            return tamanho;
                        }
                    }
                    if (cadeia[posicao] == ']'){
                        if  (atestar == '[')
                            return posicao+1;
                        else{
                            simnao = 1;
                            return tamanho;
                        }
                    }
                }else{
                    simnao = 1;
                    return tamanho;
                }
            }while(posicao<tamanho);
        }
    return posicao;
}


int main() {
    int n, i, total;
    
    /*Ve quantas strings vao entrar*/
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        total = 0;
        
        scanf("%s", cadeia); /*Recebe a string*/
        
        /*Se for string vazia pode já terminar*/
        if (strcmp(cadeia, "") == 0){
            printf("%d\n", strcmp(cadeia, ""));
            printf("Yes\n");
            return 0;
        }
        
        /*Se for string impar pode tambem terminar. Caso for par entao vamos fazer as verificacoes para ver se esta correcta*/
        if (strlen(cadeia)%2 == 0) {
            while (total < strlen(cadeia)){
                total=verificar(cadeia[total], total+1,(int) strlen(cadeia));
            }
        }else{
            simnao = 1;
        }
        
        /*Imprime o resultado*/
        if (simnao == 0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
        simnao = 0;
    }
    
    
    return 0;
}
