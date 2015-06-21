#include <stdio.h>
#include <stdlib.h>

static int matriz[101][101];
static int usados[101][101];
int result=100000;
int chegou=0;

int funcao(int n, int local, int n_niveis){
    int valor1=10000, valor2=10000;

    if(n==n_niveis-1){
        usados[n][local]=1;
        chegou=1;
        return matriz[n][local];

    }else{

        if(matriz[n+1][local] != -1){
                if(usados[n+1][local] == 0)
                    valor1=funcao(n+1, local, n_niveis);
                else{
                    valor1=matriz[n+1][local];
                }
        }

        if(matriz[n+1][local+1] != -1){
                if(usados[n+1][local+1] == 0){
                    valor2=funcao(n+1, local+1, n_niveis);
                }else{
                    valor2=matriz[n+1][local+1];
                }
        }
        valor1=valor1+matriz[n][local];
        valor2=valor2+matriz[n][local];
        if(valor1<valor2){
            matriz[n][local]=valor1;
        }else{
            matriz[n][local]=valor2;
        }
        usados[n][local]=1;
        return matriz[n][local];
    }

}

int main()
{
    int n_niveis,i,j;
    scanf("%d", &n_niveis);
    for(i=0;i<n_niveis;i++){
        for(j=0;j<i+1;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    result = funcao(0,0,n_niveis);

    if(chegou==1){
        printf("%d\n", result);
    }else{
        printf("no way!\n");
    }

    return 0;
}
