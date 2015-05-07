#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct Bank
{
	int id;
	int n_debts;
	int debt[50];
	int id_bank_lent_money[50];
	int audited;
	int dfs_index;
	int lowlink;
	int dead;
}Bank;

Bank b[5000];
int banks_audited[5000];
int maxmoney = 0;
int index = 0;

void debtclusters(int i)
{
	int j;
	
	b[i].dfs_index = index;
	b[i].lowlink = index;
	index = index + 1;
	banks_audited[b[i].id] = 1;
	b[i].audited = 1;

	for (j = 0; j < b[i].n_debts; j++)
	{
		if (b[b[i].id_bank_lent_money[j]].audited == 0)
		{
			debtclusters(b[i].id_bank_lent_money[j]);
			b[i].lowlink = MIN(b[i].lowlink, b[b[i].id_bank_lent_money[j]].lowlink);
		}
		else if (banks_audited[b[i].id_bank_lent_money[j]] == 1)
		{
			b[i].lowlink = MIN(b[i].lowlink, b[b[i].id_bank_lent_money[j]].dfs_index);
		}
	}
	
	if (b[i].lowlink == b[i].dfs_index)
	{
		j = b[i].id_bank_lent_money[0];
		if (j != 0 && b[j].dead ==0)
		{
			do{
				banks_audited[j] = 0;
				b[j].audited = 0;
				maxmoney = maxmoney + b[j].debt[0];
				j = b[j].id_bank_lent_money[0];
			} while (i != j && j>0);
		}
		else {
			b[i].dead = 1;
		}
	}
}

int main()
{
	int n_banks, i;

	while (scanf("%d", &n_banks) != EOF)
	{
		maxmoney = 0;
		memset(&b, 0, sizeof b);
		for (i = 1; i < n_banks+1; i++)
		{
			int termina = 0;
			scanf("%d", &b[i].id);
			while (termina==0)
			{
				scanf("%d", &b[i].debt[b[i].n_debts]);
				if (b[i].debt[b[i].n_debts] == 0)
				{
					termina = 1;
				}
				else{
					scanf("%d", &b[i].id_bank_lent_money[b[i].n_debts]);
					b[i].n_debts++;
				}
			}
		}

		memset(banks_audited, 0, sizeof(banks_audited));
		index = 0;
		for (i = 1; i < n_banks+1; i++)
		{
			if (b[i].audited == 0)
				debtclusters(i);
		}

		if (maxmoney == 0)
		{
			printf("No cluster\n");
		}else{
			printf("%d", maxmoney);
		}
	}
	return 0;
}