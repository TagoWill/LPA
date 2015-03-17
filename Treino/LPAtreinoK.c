
#include <stdio.h>
#include <stdlib.h>

int pizzas[61];
int media=0, tamanho;

int calcularTempos(int posi, int forno1, int forno2){
    int primeira = 0, segunda = 0;
    if(posi < tamanho){
        if(forno1 < media){
            primeira = calcularTempos(posi+1, forno1+pizzas[posi], forno2);
        }else{
            media = media * 2;
            primeira = forno1;
        }
        segunda = calcularTempos(posi+1, forno1, forno2+pizzas[posi]);
    }else{
        if(forno1 < forno2){
            return (forno2-forno1);
        }else{
            return forno1-forno2;
        }
    }
    if(primeira<segunda){
        return primeira;
    }else{
        return segunda;
    }
}

int main() {
    
    int i;
    int minimo, aux, aux2;
    
    while(scanf("%d", &tamanho) != EOF){
        for(i=0;i<tamanho;i++){
            scanf("%d.%d", &aux, &aux2);
            pizzas[i] = (aux * 100) + aux2;
            media += pizzas[i];
        }
        
        media = media / 2;
        
        minimo = calcularTempos(1, pizzas[0], 0);
        
        
        printf("%.2f\n", minimo / 100.0);
    }
    
    return 0;
}