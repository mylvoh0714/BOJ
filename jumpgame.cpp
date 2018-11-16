#include <iostream>
#include <cstring>
using namespace std;
int map[101][101];
int dp[101][101];
int n;

int go(int row, int col) {
	if ( row< 1 || row > n || col < 1 || col > n )
		return 0;
	
	if ( row == n && col == n )
		return 1;

	int &ret = dp[row][col];
	if ( ret != -1 ) return ret;
	return ret = (go(row + map[row][col], col) || go(row, col + map[row][col]));
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while ( t-- )
	{
		cin >> n;
		memset(dp, -1, sizeof(dp));
		//memset(map, 0, sizeof(map));
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				cin >> map[i][j];
			}
		}
		if ( go(1, 1) == 1 ) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";
		
	}
}