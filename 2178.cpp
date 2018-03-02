//BOJ_2178 미로탐색
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int visited[101][101];
int arr[101][101];
int dp[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;


int main()
{
	int N, M;
	scanf("%d %d", &N, &M); // 세로N, 가로M
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= M; j++ )
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	q.push(make_pair(1, 1));
	visited[1][1] = 1;
	while ( !q.empty() )
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for ( int i = 0; i < 4; i++ )
		{
			int my = y + dy[i];
			int mx = x + dx[i];
			
			if ( 1 <= my && my <= N && 1 <= mx && mx <= M )
			{
				if ( visited[my][mx] == 0 && arr[my][mx] == 1 )
				{
					visited[my][mx] = 1;
					arr[my][mx] = arr[y][x] + 1;
					q.push({ my,mx });
				}
			}
		}
	}
	printf("%d\n", arr[N][M]);
}