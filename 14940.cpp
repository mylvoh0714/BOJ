#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<pair<int,int>> q;
int n, m;
int arr[1001][1001];
int dist[1001][1001]; // distance from start point ~ to [n][m]
int num;

void bfs(int row, int col)
{
	q.push({ row,col });
	while ( !q.empty() )
	{

		int _row = q.front().first;
		int _col = q.front().second;

		q.pop();

		if ( !dist[_row + 1][_col] && arr[_row+1][_col] == 1) {
			q.push({ _row + 1, _col });
			dist[_row+1][_col] = dist[_row][_col]+1;
		}

		if ( !dist[_row - 1][_col] && arr[_row - 1][_col] == 1 ) {
			q.push({ _row - 1, _col });
			dist[_row - 1][_col] = dist[_row][_col] + 1;
		}

		if ( !dist[_row][_col + 1] && arr[_row][_col + 1] == 1 ) {
			q.push({ _row, _col + 1 });
			dist[_row][_col+1] = dist[_row][_col] + 1;
		}

		if ( !dist[_row][_col - 1] && arr[_row][_col - 1] == 1 ) {
			q.push({ _row, _col - 1 });
			dist[_row][_col-1] = dist[_row][_col] + 1;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			if ( arr[i][j] == 2 ) {
				bfs(i, j);
				break;
			}
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			if ( dist[i][j] == 0 && arr[i][j] == 1 )
				printf("-1 ");
			else
				printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}