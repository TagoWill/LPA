#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BANKS_MAX 5000
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

struct Stack {
	int     data[BANKS_MAX];
	int     size;
};
typedef struct Stack Stack;

void Stack_Init(Stack *S)
{
	S->size = 0;
}

int Stack_Top(Stack *S)
{
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return -1;
	}
	return S->data[S->size - 1];
}

void Stack_Push(Stack *S, int d)
{
	if (S->size < BANKS_MAX)
		S->data[S->size++] = d;
	else
		fprintf(stderr, "Error: stack full\n");
}

void Stack_Pop(Stack *S)
{
	if (S->size == 0)
		fprintf(stderr, "Error: stack empty\n");
	else
		S->size--;
}

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

Bank b[BANKS_MAX];
Stack st;
int maxmoney = 0, max=0;

void debtclusters(int i, Stack st)
{
	int j;
	int index = 1;
	
	b[i].dfs_index = index;
	b[i].lowlink = index;
	index = index + 1;
	Stack_Push(&st, b[i].id);
	b[i].audited = 1;

	for (j = 0; j < b[i].n_debts; j++)
	{
		int d = b[i].id_bank_lent_money[j];
		if (b[d].dfs_index == 0)
		{
			maxmoney = maxmoney + b[d].debt[j];
			debtclusters(b[i].id_bank_lent_money[j], st);
			b[i].lowlink = MIN(b[i].lowlink, b[b[i].id_bank_lent_money[j]].lowlink);
		}
		else if (b[b[i].id_bank_lent_money[j]].audited == 1)
		{
			b[i].lowlink = MIN(b[i].lowlink, b[b[i].id_bank_lent_money[j]].dfs_index);
		}
	}
	
	if (b[i].lowlink == b[i].dfs_index)
	{
		while (Stack_Top(&st) != i && Stack_Top(&st) != 0)
		{
			j = (int)Stack_Top(&st);
			b[j].audited = 0;
			Stack_Pop(&st);
		}
		if (j == 0)
			maxmoney = 0;
		else
			max = maxmoney;
	}
}

int main()
{
	int n_banks, i;

	while (scanf("%d", &n_banks) != EOF)
	{
		max = 0;
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

		Stack_Init(&st);
		for (i = 1; i < n_banks+1; i++)
		{
			if (b[i].audited == 0)
				debtclusters(i, st);
		}

		if (max == 0)
		{
			printf("No cluster\n");
		}else{
			printf("%d", max);
		}
	}
	return 0;
}

