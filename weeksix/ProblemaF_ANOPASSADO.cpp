#include <stdio.h>
#include <stdlib.h>
#include <set>

#define MAXPLAYERS 45
#define MAXBUDGET 1000

int matriz[MAXPLAYERS][MAXPLAYERS + 1];
int used[MAXPLAYERS];

class Jogador
{
public:
	int id;
	int preco;
	int pontos;
};


class Comparacao
{
public:
	bool operator () (Jogador Jog1, Jogador Jog2) {
		if (Jog1.pontos > Jog2.pontos){
			return true;
		}
		else if (Jog1.pontos == Jog2.pontos){
			if (Jog1.id < Jog2.id){
				return true;
			}
		}
		return false;
	}
};

std::set<Jogador, Comparacao> listagem;

int intcmp(const void *aa, const void *bb)
{
	int *a = (int*)aa, *b = (int*)bb;
	return (*a < *b) ? -1 : (*a > *b);
}


int branchandbound(int *ids, int i, int k, int n, int fim)
{
	int h, j, z, total=0, aux=0;
	std::set<Jogador, Comparacao>::iterator count;
	if (fim==1){
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
	} else {
		i = 0;
		for (count = listagem.begin(); count != listagem.end(); count++){
			if (count->preco <= k && used[count->id] == 0)
			{
				ids[i] = count->id;
				//soma += count->pontos;
				//k = k - count->preco;
				//i++;
				used[count->id] = 1;
				if (std::next(count, 1) == listagem.end())
				{
					fim = 1;
				}
				aux = branchandbound(ids, i++, k-count->preco, n, fim);
				used[count->id] = 0;
				fim = 0;
				ids[i] = 0;
			} else if (std::next(count, 1) == listagem.end()){
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
	int i, j, n, k, points, price, result=0;
	int ids[MAXPLAYERS];
	memset(ids, 0, MAXPLAYERS);

	while (scanf("%d %d", &n, &k) > 0){
		for (i = 0; i < n; i++){
			points = 0;
			for (j = 0; j < n + 1; j++){
				scanf("%d ", &matriz[i][j]);
				if (j != 0){
					points += matriz[i][j];
				} else {
					price = matriz[i][j];
				}
			}
			Jogador player;
			player.id = i;
			player.preco = price;
			player.pontos = points;
			listagem.insert(player);
		}
	}

	result = branchandbound(ids, 0, k, n, 0);

	printf("%d\n", result);

	system("PAUSE");
	return 0;
}
