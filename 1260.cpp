// BOJ_1260 DFS¿Í BFS
#include <iostream>
#include <queue>
using namespace std;
int adj[1001][1001];
int visited[1001];
int N, M, start;
queue<int> q;

void dfs(int u)
{
	if ( visited[u] == 0 )
	{
		visited[u] = 1;
		printf("%d ", u);
	}
	for ( int v = 1; v <= N; v++ )
	{
		if ( visited[v] == 0 && adj[u][v] == 1 )
			dfs(v);
	}
}

void bfs(int pos)
{
	visited[pos] = 1;
	q.push(pos);
	while ( !q.empty() )
	{
		int u = q.front();
		q.pop();
		printf("%d ", u);
		for ( int v = 1; v <= N; v++ )
		{
			if ( visited[v] == 0 && adj[u][v] == 1 )
			{
				visited[v] = 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	
	int u, v;
	scanf("%d %d %d", &N, &M, &start);
	for ( int i = 0; i < M; i++ )
	{
		scanf("%d %d", &u, &v);
		adj[u][v] = adj[v][u] = 1;
	}

	dfs(start);
	printf("\n");
	
	for ( int i = 0; i < 1001; i++ )
	{
		visited[i] = 0;
	}

	bfs(start);
	printf("\n");
	return 0;
}