// BOJ 2606 바이러스
#include <iostream>
#include <vector>
using namespace std;
int adjM[101][101];
int visited[101];
int N,K,result;

void dfs(int u)
{
	if ( visited[u] == 0 )
	{
		visited[u] = 1;
		result++;
	}
	for ( int v = 1; v <= N; v++ )
	{
		if ( !visited[v] && adjM[u][v] == 1 )
			dfs(v);
	}
}

int main()
{
	int u, v;
	scanf("%d %d", &N, &K);
	for ( int i = 0; i < K; i++ )
	{
		scanf("%d %d", &u, &v);
		adjM[u][v] = adjM[v][u] = 1;
	}
	dfs(1);
	printf("%d", result-1); // exclude num1 computer
	return 0;

}
