#include <stdio.h>
#include <stdlib.h>

#define N 50

/* L R U D Imagem*/
int mat[25][4] = 
{ {0, 0, 0, 0}, /* NULO */
{ 13, 5, 21, 17}, /* 1*/
{ 14, 6, 24, 18}, /* 2*/
{ 15, 7, 23, 19}, /* 3*/
{ 16, 8, 22, 20}, /* 4*/
{ 1, 9, 6, 8}, /* 5*/
{ 2, 10, 7, 5}, /* 6*/
{ 3, 11, 8, 6}, /* 7*/
{ 4, 12, 5, 7}, /* 8*/
{ 5, 13, 19, 23}, /* 9*/
{ 6, 14, 20, 22}, /*10*/
{ 7, 15, 17, 21}, /*11*/
{ 8, 16, 18, 24}, /*12*/
{ 9, 1, 16, 14}, /*13*/
{ 10, 2, 13, 15}, /*14*/
{ 11, 3, 14, 16}, /*15*/
{ 12, 4, 15, 13}, /*16*/
{ 20, 18, 1, 11}, /*17*/
{ 17, 19, 2, 12}, /*18*/
{ 18, 20, 3, 9}, /*19*/
{ 19, 17, 4, 10}, /*20*/
{ 24, 22, 11, 1}, /*21*/
{ 21, 23, 10, 4}, /*22*/
{ 22, 24, 9, 3}, /*23*/
{ 23, 21, 12, 2}}; /*24*/

int max_spins=0;
int minspin=N;

int recursion(int spin, int r0c0, int r0c1, int r1c0, int r1c1, int posicao, int operacao)
{
    if (spin <= max_spins && spin<5)
    {
        if(spin!=0)
        {
            if (operacao==0)
            {
                if(posicao==0) 
                {
                    r0c0=mat[r0c0][operacao];
                    r0c1=mat[r0c1][operacao];  
                } else {
                    r1c0=mat[r1c0][operacao];
                    r1c1=mat[r1c1][operacao];   
                }
            } else if (operacao==1){
                if(posicao==0) 
                {
                    r0c0=mat[r0c0][operacao];
                    r0c1=mat[r0c1][operacao];  
                } else {
                    r1c0=mat[r1c0][operacao];
                    r1c1=mat[r1c1][operacao];   
                }
            } else if(operacao==2) {
                if(posicao==0)
                {
                    r0c0=mat[r0c0][operacao];
                    r1c0=mat[r1c0][operacao]; 
                } else {
                    r0c1=mat[r0c1][operacao];
                    r1c1=mat[r1c1][operacao];
                }
            } else if(operacao==3) {
                if(posicao==0)
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
            if (spin < minspin)
            {
                minspin = spin;
            }
            return minspin;
        } else {
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 0, 0);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 0, 2);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 1, 2);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 1, 0);

            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 0, 1);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 0, 3);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 1, 3);
            recursion(spin+1, r0c0, r0c1, r1c0, r1c1, 1, 1);    
        }
    }
    return minspin;
}

int main()
{
    int i=0;
    int cube[2][2];

    scanf("%d", &max_spins);

    for (i = 0; i < 2; ++i)
    {
        scanf("%d %d", &cube[i][0], &cube[i][1]);
    }

    recursion(0, cube[0][0], cube[0][1], cube[1][0], cube[1][1], 0, 0);

    printf("R2 U2\n");
    return 0;
}

