#include <stdio.h>
#include <algorithm>

using namespace std;


#define inf (1<<20)

int c[1001][1001];
int n;


int tsp(int a[])
{
	int i, u, v, cost;
	cost = 0;
	for ( i = 0; i < n-1; i ++ )
	{
		u = a[i];
		v = a[i+1];
		cost += c[u][v];
	}
	cost += c[a[n-1]][a[0]];
	return cost;
}

int main()
{
	int i, j, maxCost, cost;
	int solution[100],result[100];
	scanf("%d",&n);
	for ( i = 0; i < n; i ++ )
		for ( j = 0; j < n; j ++)
			scanf("%d",&c[i][j]);
	for ( i = 0; i < n; i++ )
		solution[i] = i;
	maxCost = inf;
	do
	{
		cost = tsp(solution);
		if ( cost < maxCost )
		{
			maxCost = cost;
			for ( j = 0; j < n; j ++ )
				result[j] = solution[j];
		}
	}while ( next_permutation(solution, solution+n));
	printf("TSP# %d\n",maxCost);
	printf("%d",result[0]+1);
	for ( i = 1; i < n; i ++ )
		printf("-->%d",result[i]+1);
	printf("-->%d\n",result[0]+1);
	return 0;
}