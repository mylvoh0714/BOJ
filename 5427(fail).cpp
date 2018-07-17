#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
char arr[1001][1001];
int visited[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int w, h;

int f_bfs(int row, int col)
{
	int ret = -1;
	queue<pair<int, int>> q;
	q.push({ row,col });
	visited[row][col] = 1;
	while ( !q.empty() )
	{
		int here_y = q.front().first;
		int here_x = q.front().second;
		q.pop();
		for ( int i = 0; i < 4; i++ )
		{
			int my = here_y + dy[i];
			int mx = here_x + dx[i];
			if ( 1 <= my && my <= h && 1 <= mx && mx <= w && ( arr[my][mx] == '.' || arr[my][mx] == '@' )
				&&(!visited[my][mx] || visited[my][mx] > visited[here_y][here_x] + 1) ) 
			{
				q.push({ my,mx });
				visited[my][mx] = visited[here_y][here_x] + 1;
				if ( h == 1 && w == 1 ) {
					return 0;
				}
				else if ( h == 1 ) {
					if ( mx == 1 || mx == w ) {
						return ret = visited[my][mx];
					}
				}
				else if ( w == 1 ) {
					if ( my == 1 || my == h ) {
						return ret = visited[my][mx];
					}
				}
				else {
					if ( mx == 1 || mx == w || my == 1 || my == h ) {
						return ret = visited[my][mx];
					}
				}
			}
		}
	}
}

int bfs(int row, int col)
{
	int ret = -1;
	queue<pair<int, int>> q;
	q.push({ row,col });
	visited[row][col] = 1;
	while ( !q.empty() )
	{
		int here_y = q.front().first;
		int here_x = q.front().second;
		q.pop();
	
		for ( int i = 0; i < 4; i++ )
		{
			int my = here_y + dy[i];
			int mx = here_x + dx[i];
			if ( 1 <= my && my <= h && 1 <= mx && mx <= w && !visited[my][mx] && (arr[my][mx] == '.' || arr[my][mx] == '@') ) {
				q.push({ my,mx });
				visited[my][mx] = visited[here_y][here_x] + 1;
				if ( h == 1 && w == 1 ) {
					return 1;
				}
				else if ( h == 1 ) {
					if ( mx == 1 || mx == w ) {
						return ret = visited[my][mx];
					}
				}
				else if ( w == 1 ) {
					if ( my == 1 || my == h ) {
						return ret = visited[my][mx];
					}
				}
				else {
					if ( mx == 1 || mx == w || my == 1 || my == h ) {
						return ret = visited[my][mx];
					}
				}
			}
		}
	}
}

void _main(int TestCase)
{
	scanf("%d %d", &w, &h);
	for ( int i = 1; i <= h; i++ )
	{
		for ( int j = 1; j <= w; j++ )
		{
			scanf(" %c", &arr[i][j]);
		}
	}
	int man_cnt = 0;
	int fire_cnt = 10000; // INF
	int man_start_row, man_start_col;
	for ( int i = 1; i <= h; i++ )
	{
		for ( int j = 1; j <= w; j++ )
		{
			if ( arr[i][j] == '*' ) {
				fire_cnt = min(fire_cnt, f_bfs(i, j));
				cout << "fire_bfs : " << fire_cnt << endl;
			}
			else if ( arr[i][j] == '@' ) {
				man_start_row = i;
				man_start_col = j;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	man_cnt = bfs(man_start_row, man_start_col);
	cout << "man_bfs : " << man_cnt << endl;
	if ( man_cnt < fire_cnt && man_cnt != -1 ) {
		printf("%d\n", man_cnt);
	}
	else {
		printf("IMPOSSIBLE\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for ( int TestCase = 1; TestCase <= T; TestCase++ )
	{
		_main(TestCase);
	}
}