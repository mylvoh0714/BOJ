// BOJ_2667 단지번호붙이기
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<pair<int, int>> q;
vector<int> part_result;
int result;
int visited[26][26];
int map[26][26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int N;

bool line_check(int x, int y,int N)
{
	return ( 1 <= x ) && (x <= N ) && (1<= y) && ( y <= N );
}

int bfs(int a, int b) // map[a][b]에서 bfs
{
	int num = 1;
	q.push({ a,b });
	visited[a][b] = 1;
	while ( !q.empty() )
	{
		int y = q.front().second;
		int x = q.front().first;
		q.pop();
		for ( int i = 0; i < 4; i++ )
		{
			int my = y + dy[i];
			int mx = x + dx[i];
			if ( line_check(mx, my, N) && visited[my][mx] == 0 && map[my][mx] == 1 )
			{
				visited[my][mx] = 1;
				q.push({ my,mx });
				num++;
			}
		}
	}
	return num;
}

int main()
{
	
	scanf("%d", &N);
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for ( int i = 1; i <= N; i++ )
	{
			for ( int j = 1; j <= N; j++ )
		{
			if ( map[i][j] == 1 && visited[i][j] == 0 )
			{
				result++;
				int temp = bfs(i, j);
				part_result.push_back(temp);
			}
		}
	}
	sort(part_result.begin(), part_result.end());
	printf("%d\n", result);
	for ( int i = 0; i < part_result.size(); i++ )
	{
		printf("%d\n", part_result[i]);
	}
	
}