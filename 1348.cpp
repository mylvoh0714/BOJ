#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int map[51][51];
int visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int r, c;

int bfs(int row, int col)
{
	visited[row][col] = 1;
	queue<pair<int,int>> q;
	q.push({ row,col });
	while ( !q.empty() )
	{
		int here_row = q.front().first;
		int here_col = q.front().second;
		q.pop();

		if ( map[here_row][here_col] == 4 ) {
			int ret = visited[here_row][here_col] - 1;
			memset(visited, 0, sizeof(visited));
			return ret;
		}		
		for ( int i = 0; i < 4; i++ )
		{
			int my = here_row + dy[i];
			int mx = here_col + dx[i];
			if ( !visited[my][mx] && map[my][mx] != 1 && 1 <= my && my <= r && 1 <= mx && mx <= c ) {
				q.push({ my,mx });
				visited[my][mx] = visited[here_row][here_col] + 1;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	return -1;
}

int main()
{
	scanf("%d %d", &r, &c);
	for ( int i = 1; i <= r; i++ )
	{
		for ( int j = 1; j <= c; j++ )
		{
			char ch;
			scanf(" %c", &ch);
			if ( ch == 'C' ) {
				map[i][j] = 3; // start = 3
			}
			else if ( ch == 'P' ) {
				map[i][j] = 4; // exit = 4
			}
			else if ( ch == '.' ) {
				map[i][j] = 0; // path = 0
			}
			else if ( ch == 'X' ) {
				map[i][j] = 1; // wall = 1
			}
		}
	}

	int result = 0;

	bool break_f = false;
	for ( int i = 1; i <= r; i++ )
	{
		for ( int j = 1; j <= c; j++ )
		{
			if ( map[i][j] == 3 ) {
				if ( result == 0 ) {
					result = bfs(i, j);
				}
				else {
					int temp = bfs(i, j);
					if ( result == -1 || temp == -1 ) {
						break_f = true;
						result = -1;
						break;
					}
					result = max(result, temp);
				}
			}
		}
		if ( break_f == true )
			break;
	}
	printf("%d\n", result);

	return 0;
}