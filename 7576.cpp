#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int map[1001][1001];
int visited[1001][1001];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int col, row;
bool check(int i, int j)
{
	return ( 1 <= i ) && ( i <= row ) && ( 1 <= j ) && ( j <= col );
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> col >> row;
	int cnt = 0; // 남아있는 익지않은 토마토의 수
	queue<pair<int, int>> q;
	for ( int i = 1; i <= row; i++ )
	{
		for ( int j = 1; j <= col; j++ )
		{
			cin >> map[i][j];
			if ( map[i][j] == 0 ) cnt++;
			else if ( map[i][j] == 1 ) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	int ans = 0;
	while ( !q.empty() )
	{
		int h_row = q.front().first;
		int h_col = q.front().second;
		q.pop();
		for ( int i = 0; i < 4; i++ )
		{
			int t_row = h_row + dy[i];
			int t_col = h_col + dx[i];
			if ( !visited[t_row][t_col] && check(t_row, t_col) && map[t_row][t_col] == 0 ) {
				q.push({ t_row,t_col });
				visited[t_row][t_col] = visited[h_row][h_col] + 1;
				cnt -= 1;
				ans = max(ans, visited[t_row][t_col]);
			}
		}
	}
	if ( cnt != 0 ) cout << -1;
	else if ( ans == 0 ) cout << 0;
	else cout << ans - 1;
	
	
	
}