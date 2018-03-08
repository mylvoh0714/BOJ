// BOJ_2589 보물섬
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int map[51][51]; // Land는 1, W(sea)는 0으로 저장
int visited[51][51]; // check배열이자 최단거리를 정수로 표시
int n, m, temp, result;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char input;
queue<pair<int, int>> q;

int bfs(int start_i, int start_j)
{
	q.push({ start_i, start_j });
	visited[start_i][start_j] = 1;
	int ret = 0;
	while ( !q.empty() )
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if ( ret < visited[i][j] ) ret = visited[i][j];
		for ( int k = 0; k < 4; k++ )
		{
			int mi = i + dx[k];
			int mj = j + dy[k];
			if ( ( 1 <= mi && mi <= n ) && ( 1 <= mj && mj <= m ) && (map[mi][mj] == 1) && (!visited[mi][mj]) )
			{
				q.push({ mi, mj });
				visited[mi][mj] = visited[i][j] + 1;
			}
		}
	}
	return ret - 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			scanf(" %c", &input);
			if ( input == 'L' )
				map[i][j] = 1;
			else if ( input == 'W' )
				map[i][j] = 0;
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			if ( map[i][j] == 1)
			{
				temp = bfs(i, j);
				if ( result < temp )
					result = temp;
				memset(visited, 0, sizeof(visited));
			}			
		}
	}
	printf("%d\n", result);
}