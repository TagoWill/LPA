#include <stdio.h>
#include <stdlib.h>
#include <set>

#define MAXPLACES 30
#define MAXCENTROIDS 22

int matriz[MAXPLACES][MAXPLACES + 1];
int used[MAXPLACES];

class Ligacao
{
public:
	int point1;
	int point2;
	int distance;
};


class Comparacao
{
public:
	bool operator () (Ligacao L1, Ligacao L2) {
		if (L1.distance > L2.distance){
			return true;
		}
		else if (L1.distance == L2.distance){
			if (L1.point1 < L2.point1){
				return true;
			}
		}
		return false;
	}
};

std::set<Ligacao, Comparacao> listagem;

int intcmp(const void *aa, const void *bb)
{
	int *a = (int*)aa, *b = (int*)bb;
	return (*a < *b) ? -1 : (*a > *b);
}


int branchandbound(int *ids, int i, int k, int n, int fim)
{
	int h, j, z, total = 0, aux = 0;
	std::set<Ligacao, Comparacao>::iterator count;
	if (fim == 1){
		qsort(ids, i, sizeof(int), intcmp);
		for (h = 0; h < n; h++){
			for (j = 0; j < i; j++){
				if (ids[j] == h)
				{
					total += matriz[h][h + 1];
					for (z = 0; z < i; z++){
						if (ids[z] != h)
						{
							total += matriz[h][ids[z] + 1];
						}
					}
				}
			}
		}
		return total;
	}
	else {
		i = 0;
		for (count = listagem.begin(); count != listagem.end(); count++){
			if (count->distance <= k && used[count->point1] == 0)
			{
				ids[i] = count->point1;
				//soma += count->pontos;
				//k = k - count->preco;
				//i++;
				used[count->point1] = 1;
				if (std::next(count, 1) == listagem.end())
				{
					fim = 1;
				}
				aux = branchandbound(ids, i++, k - count->distance, n, fim);
				used[count->point1] = 0;
				fim = 0;
				ids[i] = 0;
			}
			else if (std::next(count, 1) == listagem.end()){
				aux = branchandbound(ids, i, k, n, 1);
			}
			if (total < aux)
			{
				total = aux;
			}
		}
		return total;
	}
}

int main(){
	int i, n, k, p1, p2, d, result = 0;
	int ids[MAXPLACES];
	memset(ids, 0, MAXPLACES);

	scanf("%d %d", &n, &k);

	int p = n*(n - 1) / 2;

	for (i = 0; i < p; i++){
		scanf("%d %d %d", &p1, &p2, &d);
		matriz[p1-1][p2-1] = d;
		matriz[p2-1][p1-1] = d;
		Ligacao l;
		l.point1 = p1;
		l.point2 = p2;
		l.distance = d;
		listagem.insert(l);
	}

	result = branchandbound(ids, 0, k, n, 0);

	printf("%d\n", result);

	system("PAUSE");
	return 0;
}
