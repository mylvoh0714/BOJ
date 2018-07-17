#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[501][501];
int dp[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int go(int i, int j)
{
	if ( dp[i][j] != 0 ) {
		return dp[i][j];
	}
	dp[i][j] = 1;
	for ( int k = 0; k < 4; k++ )
	{
		int mi = i + dx[k];
		int mj = j + dy[k];
		if ( arr[i][j] < arr[mi][mj] && 1 <= mi && mi <= n && 1 <= mj && mj <= n ) {
			dp[i][j] = max(dp[i][j], go(mi, mj) + 1);
		}
	}
	return dp[i][j];
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			ans = max(ans, go(i, j));
		}
	}
	cout << ans << '\n';
}