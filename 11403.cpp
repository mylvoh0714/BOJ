#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> mat(n + 1, vector<int>(n + 1));
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			cin >> mat[i][j];
			dp[i][j] = mat[i][j];
		}
	}

	for ( int k = 1; k <= n; k++ )
	{
		for ( int i = 1; i <= n; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				if ( dp[i][k] && dp[k][j] )
					dp[i][j] = 1;
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