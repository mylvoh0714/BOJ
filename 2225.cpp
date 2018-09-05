//BOJ 2225 합분해
#include <iostream>
using namespace std;
long long dp[201][201]; // dp[n][k] : 합이 n, k개 사용
const int MOD = 1000000000;

int main()
{
	int n, k;
	cin >> n >> k;
	for ( int i = 0; i <= 200; i++ )
	{
		dp[i][1] = 1;
	}
	for ( int j = 1; j <= k; j++ )
	{
		for ( int i = 0; i <= n; i++ )
		{
			for ( int l = 0; l <= i; l++ )
			{
				dp[i][j] += dp[i - l][j - 1] % MOD;
			}
		}
	}
	cout << dp[n][k] % MOD << '\n';	
	
}