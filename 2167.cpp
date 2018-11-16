#include <iostream>
using namespace std;

int dp[301][301];
int a[301][301];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			cin >> a[i][j];
		}
	}
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			dp[i][j] = a[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	int k; cin >> k;
	for ( int i = 0; i < k; i++ )
	{
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1] << '\n';
	}
}