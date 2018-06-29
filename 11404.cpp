#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for ( int i = 0; i < m; i++ )
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		if ( dp[start][end] == 0 )
			dp[start][end] = cost;
		else
			dp[start][end] = min(dp[start][end], cost);
	}

	for ( int k = 1; k <= n; k++ )
	{
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				if ( i == j )
					continue;

				if ( dp[i][k] != 0 && dp[k][j] != 0 ) {
					if ( dp[i][j] == 0 )
						dp[i][j] = dp[i][k] + dp[k][j];
					else {
						if ( dp[i][j] > dp[i][k] + dp[k][j] )
							dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}	