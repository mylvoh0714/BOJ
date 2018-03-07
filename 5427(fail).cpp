// BOJ_5427 불
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
queue<pair<int, int>> q;

char map[1001][1001];
bool visited[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int TestCase, x, y;
int myResult,fireResult;

int bfs(int a, int b) // [a][b]위치에서 출구까지 거리.
{
	int result = 0;
	q.push({ a,b });
	visited[a][b] = true;
	while ( !q.empty() )
	{
		result++;
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if ( a == 1 || a == y || b == 1 || b == x )
			return result;
		for( int i=0;i<4;i++)
		{
			int ma = a + dy[i];
			int mb = b + dx[i];
			if ( map[ma][mb] == '#' || visited[ma][mb] ) continue;
			if ( map[ma][mb] == '.' || map[ma][mb] == '@' || map[ma][mb] == '*')
			{
				q.push({ ma,mb });
				visited[ma][mb] = true;
			}			
		}
	}
}

int main()
{
	scanf("%d", &TestCase);
	while ( TestCase-- )
	{
	
		myResult = fireResult = 0;
		memset(map, 0, sizeof(map));
		scanf("%d %d", &x, &y); // x = 4, y=3
		for ( int i = 1; i <= y; i++ )
		{
			for ( int j = 1; j <= x; j++ )
			{
				scanf(" %c", &map[i][j]);
			}
		}
	
		for ( int i = 1; i <= y; i++ ) // fire거리부터 계산
		{
			for ( int j = 1; j <= x; j++ )
			{
				if ( map[i][j] == '*' )
				{
					if ( fireResult )
					{
						memset(visited, 0, sizeof(visited));
						fireResult = fireResult < bfs(i, j) ? fireResult : bfs(i, j);
					}
					else
						fireResult = bfs(i, j);
				}	
			}
		}
		memset(visited, 0, sizeof(visited));
		for ( int i = 1; i <= y; i++ )
		{
			for ( int j = 1; j <= x; j++ )
			{
				if ( map[i][j] == '@')
					myResult = bfs(i, j);
			}
		}
		if ( myResult < fireResult )
			printf("%d\n", myResult);
		else
			printf("IMPOSSIBLE\n");
	}
}