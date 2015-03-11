#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static int locais[13][2];
static int usado[13];
double resultado = 100000000;
int tamanho;

double Distance(double x1, double y1, double x2, double y2)

{
    
    double diffx = x1 - x2;
    double diffy = y1 - y2;
    double diffx_sqr = pow(diffx,2);
    double diffy_sqr = pow(diffy,2);
    double distance = sqrt(diffx_sqr + diffy_sqr);
    
    return distance;
    
}

int calcularDistancia(int posi, int local, double distancia){
    int i = 0;
    
    if(resultado<distancia){
        return 0;
    }
    if(posi == tamanho && distancia < resultado){
        resultado = distancia;
        return 0;
    }
    
    for(i=0;i<tamanho;i++){
        if(usado[i] == 0){
            usado[i] = 1;
            calcularDistancia(posi+1, i, distancia +
                              Distance(locais[local][0],locais[local][1],locais[i][0],locais[i][1]));
            usado[i] = 0;
            
        }
    }
    
    return 0;
}


int main() {
    
    int i;
    
    scanf("%d", &tamanho);
    
    
    for(i=0;i<tamanho;i++) {
        scanf("%d %d", &locais[i][0], &locais[i][1]);
    }
    
    for(i=0;i<tamanho;i++){
        usado[i] = 1;
        calcularDistancia(1, i, 0);
        usado[i] = 0;
    }
    
    
    printf("%.3f\n", resultado);
    
    return 0;
}