#include <stdio.h>
#include <stdlib.h>

int caminhos;
int matriz[100][100];

void branchandbound(int w, int h, int x, int y)
{
	int i, j;

	if (x==w && y==h)
	{
		caminhos++;
	} else if (matriz[x][y]==0)
	{
		if (x<w)
		{
			if (matriz[x+1][y]==1)
			{
				for (i = y+1; i < h; ++i)
				{
					if (matriz[x+1][i]==0)
					{
						branchandbound(w, h, x+1, i);
					}
				}
			} else{
				branchandbound(w, h, x+1, y);
			}
		}

		if (y<h)
		{
			if(matriz[x][y+1]==1)
			{
				for (j = x+1; j < w; j++)
				{
					if (matriz[j][y+1]==0)
					{
						branchandbound(w, h, j, y+1);
					}
				}
			} else {
				branchandbound(w, h, x, y+1);
			}
		}
	}
}

int main()
{
	int i, j=0, k, e, h=1, w=1, n_wolfs, x, y;

	while(j==0)
	{
		scanf("%d %d", &w, &h);
		if (w!=0 && h!=0)
		{
			scanf("%d", &n_wolfs);
			for (i = 0; i < n_wolfs; ++i)
			{
				scanf("%d %d", &x, &y);
				matriz[x][y] = 1;
			}
			branchandbound(w, h, 0, 0);	
			if (caminhos==0)
			{
				printf("There is no path\n");
			} else if(caminhos==1){
				printf("There is one path from Little Red Riding Hood's house to her grandmother's house\n");
				caminhos=0;
			} else {
				printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house\n", caminhos);
				caminhos=0;
			}
			for (e = 0; e < 100; e++)
			{
				for (k = 0; k < 100; k++)
				{
					matriz[e][k]=0;
				}
			}
		} else {
			j=1;
		}
	}
	return 0;
}
