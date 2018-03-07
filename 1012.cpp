// BOJ 1012 ¿Ø±‚≥Û πË√ﬂ
#include <iostream>
using namespace std;

int visited[51][51], map[51][51];
int TestCase, n, m, k, a, b;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	visited[x][y] = 1;
	for ( int i = 0; i < 4; i++ )
	{
		int mx = x + dx[i];
		int my = y + dy[i];
		if ( visited[mx][my] == 1 || mx < 0 || mx >= n || my < 0 || my >= m ) continue;
		if ( map[mx][my] == 1 ) dfs(mx, my);
	}
}

int main()
{
	scanf("%d", &TestCase);
	for( int Tcase = 0; Tcase<TestCase; Tcase++)
	{
		int result = 0;
		scanf("%d %d %d", &m, &n, &k);
		if ( Tcase >= 1)
		{
			for ( int i = 0; i < n; i++ )
			{
				for ( int j = 0; j < m; j++ )
				{
					visited[i][j] = 0;
					map[i][j] = 0;
				}
			}
		}
		for ( int i = 0; i < k; i++ )
		{
			scanf("%d %d", &a, &b);
			map[b][a] = 1;
		}
		for ( int i = 0; i < n; i++ )
		{
			for ( int j = 0; j < m; j++ )
			{
				if ( !visited[i][j] && map[i][j] == 1)
				{
					dfs(i, j); 
					result++;
				}
			}
		}
		printf("%d\n", result);
	}
}