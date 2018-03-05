#include <iostream>
using namespace std;
char arr[101][101];
int visited[101][101];
int n;
int normal_ret, abnormal_ret;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


void dfs(int x, int y)
{
	visited[x][y] = 1;
	for ( int i = 0; i < 4; i++ )
	{
		int mx = x + dx[i];
		int my = y + dy[i];
		if ( mx<1 || mx > n || my <1 || my > n )
			continue;
		if ( !visited[mx][my] && arr[mx][my] == arr[x][y] )
			dfs(mx, my);
	}
}

int main()
{
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			scanf(" %c", &arr[i][j]);
		}
	}
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			if ( visited[i][j] == 0 )
			{
				dfs(i, j);
				normal_ret++;
			}
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			visited[i][j] = 0;
			if ( arr[i][j] == 'G' )
				arr[i][j] = 'R';
		}
	}
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			if ( visited[i][j] == 0 )
			{
				dfs(i, j);
				abnormal_ret++;
			}
		}
	}
	printf("%d %d\n",normal_ret,abnormal_ret);
}