
#include <stdio.h>
#include <stdlib.h>

struct local{
    int linha;
    int colunha;
};

struct local caminho[100];

char tabela[100][100];
int encontrou=0;


void verificaCaminho(char anterior, int local, int posi, int linha, int coluna){
    int i, ver;
    if(posi < linha){
        for(i=0;i<3;i++){
            if(i==0){
                ver=-1;
            }else if(i==1){
                ver=0;
            }else{
                ver=1;
            }
            if(encontrou == 0){
                
                    if(tabela[posi][local+ver] == '/' ||
                       tabela[posi][local+ver] == '|' ||
                       tabela[posi][local+ver] == '\\' ){
                        caminho[posi].linha = posi+1;
                        caminho[posi].colunha = local+ver+1;
                        verificaCaminho(tabela[posi][local+ver],local+ver, posi+1, linha, coluna);
                    }

            }
        }
    }else{
        encontrou = 1;
    }
}


int main() {
    int r, c, i;
    
    while(scanf("%d %d", &r, &c) != EOF){
        encontrou = 0;
        for(i=0;i<r;i++){
            scanf("%s", tabela[i]);
        }
        
        for(i=0;i<r;i++){
            if(encontrou==0){
                if(tabela[0][i] == '/' ||
                   tabela[0][i] == '|' ||
                   tabela[0][i] == '\\' ){
                    caminho[0].linha = 0+1;
                    caminho[0].colunha = i+1;
                    verificaCaminho(tabela[0][i],i, 1, r, c);
                }
            }
        }
        
        
        
        
        if(encontrou == 0){
            printf("No Path!\n");
        }else{
            for(i=0;i<r;i++){
                printf("(%d,%d)", caminho[i].linha,caminho[i].colunha);
                if(i<r-1){
                    printf(",");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
