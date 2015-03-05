#include <stdio.h>
#include <stdlib.h>

/*    D   L   R   U Imagem*/
int mat[25][4] = 
{ {0, 0, 0, 0},
{17, 13, 5, 21}, /* 1*/
{18, 14, 6, 24}, /* 2*/
{19, 15, 7, 23}, /* 3*/
{20, 16, 8, 22}, /* 4*/
{8, 1, 9, 6}, /* 5*/
{5, 2, 10, 7}, /* 6*/
{6, 3, 11, 8}, /* 7*/
{7, 4, 12, 5}, /* 8*/
{23, 5, 13, 19}, /* 9*/
{22, 6, 14, 20}, /*10*/
{21, 7, 15, 17}, /*11*/
{24, 8, 16, 18}, /*12*/
{14, 9, 1, 16}, /*13*/
{15, 10, 2, 13}, /*14*/
{16, 11, 3, 14}, /*15*/
{13, 12, 4, 15}, /*16*/
{11, 20, 18, 1}, /*17*/
{12, 17, 19, 2}, /*18*/
{9, 18, 20, 3}, /*19*/
{10, 19, 17, 4}, /*20*/
{1, 24, 22, 11}, /*21*/
{4, 21, 23, 10}, /*22*/
{3, 22, 24, 9}, /*23*/
{2, 23, 21, 12}}; /*24*/

int spins[10][2];
static int minspins[10][2]={{ 50, 50 }, { 50, 50 }, { 50, 50}, { 50, 50}, { 50, 50}, { 50, 50}, { 50, 50}, { 50, 50}, { 50, 50}, { 50, 50}};
int max_spins=0;
int minspin=10;

int recursion(int spin, int r0c0, int r0c1, int r1c0, int r1c1, int posicao, int operacao)
{
    int i=0, j=0;

    if (spin <= max_spins && spin<6)
    {
        if(spin!=0)
        {
            spins[spin][0]=posicao;
            spins[spin][1]=operacao;
            if (operacao==1)
            {
                if(posicao==1) 
                {
                    r0c0=mat[r0c0][operacao];
                    r0c1=mat[r0c1][operacao];  
                } else {
                    r1c0=mat[r1c0][operacao];
                    r1c1=mat[r1c1][operacao];   
                }
            } else if (operacao==2){
                if(posicao==1) 
                {
                    r0c0=mat[r0c0][operacao];
                    r0c1=mat[r0c1][operacao];  
                } else {
                    r1c0=mat[r1c0][operacao];
                    r1c1=mat[r1c1][operacao];   
                }
            } else if(operacao==3) {
                if(posicao==1)
                {
                    r0c0=mat[r0c0][operacao];
                    r1c0=mat[r1c0][operacao]; 
                } else {
                    r0c1=mat[r0c1][operacao];
                    r1c1=mat[r1c1][operacao];
                }
            } else if(operacao==0) {
                if(posicao==1)
                {
                    r0c0=mat[r0c0][operacao];
                    r1c0=mat[r1c0][operacao]; 
                } else {
                    r0c1=mat[r0c1][operacao];
                    r1c1=mat[r1c1][operacao];
                }
            }      
        }
        
        if (r0c0==1 && r0c1==1 && r1c0==1 && r1c1==1)
        {
            int menor=0;
            if (spin < minspin)
            {
                minspin = spin;
                for (i = 1; i < minspin+1; ++i)
                {
                    minspins[i][0]=spins[i][0];
                    minspins[i][1]=spins[i][1];
                }
            } else if (spin == minspin)
            {
                for (j = 1; j < spin+1; ++j)
                {
                    if (minspins[j][1] >= spins[j][1])
                    {
                        if (minspins[j][0] >= spins[j][0])
                        {
                            menor++;
                            if (menor==spin)
                            {
                                minspin = spin;
                                for (i = 1; i < minspin+1; ++i)
                                {
                                    minspins[i][0]=spins[i][0];
                                    minspins[i][1]=spins[i][1];
                                }
                            }
                        }
                    }
                }
            }
            return minspin;
        } else {
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 1, 1);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 1, 3);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 2, 3);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 2, 1);

            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 1, 2);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 1, 0);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 2, 0);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 2, 2);    
        }
    }
    return minspin;
}

int main()
{
    int i=0, j=0;
    int cube[2][2];
    int moves;

    scanf("%d", &max_spins);

    for (i = 0; i < 2; ++i)
    {
        scanf("%d %d", &cube[i][0], &cube[i][1]);
    }

    moves = recursion(0, cube[0][0], cube[0][1], cube[1][0], cube[1][1], 0, 0);

    for (j = 1; j < moves+1; j++)
    {
        if (minspins[j][0]==1 && minspins[j][1]==1)
        {
            printf("L1 ");
        } else if(minspins[j][0]==2 && minspins[j][1]==1)
        {
            printf("L2 ");
        } else if(minspins[j][0]==1 && minspins[j][1]==2)
        {
            printf("R1 ");
        } else if(minspins[j][0]==2 && minspins[j][1]==2)
        {
            printf("R2 ");
        } else if(minspins[j][0]==1 && minspins[j][1]==3)
        {
            printf("U1 ");
        } else if(minspins[j][0]==2 && minspins[j][1]==3)
        {
            printf("U2 ");
        } else if(minspins[j][0]==1 && minspins[j][1]==0)
        {
            printf("D1 ");
        } else if(minspins[j][0]==2 && minspins[j][1]==0)
        {
            printf("D2 ");
        }
    }
    printf("\n");
    return 0;
}

