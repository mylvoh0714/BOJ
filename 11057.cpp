#include <iostream>
using namespace std;
int dp[1001][10]; // dp[n][k] 길이가 n이고 끝자리수가 k.
int main()
{
	int n;
	scanf("%d", &n);
	for ( int i = 0; i <= 9; i++ )
	{
		dp[1][i] = 1;
	}
	for ( int i = 1; i <= n; i++ )
	{
		dp[i][0] = 1;
	}
	for ( int i = 2; i <= n; i++ )
	{
		for ( int j = 1; j <= 9; j++ )
		{
			for ( int k = 0; k <= j; k++ )
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] = dp[i][j] % 10007;
			}
		}
	}
	int result = 0;
	for ( int i = 0; i <= 9; i++ )
	{
		result += dp[n][i] % 10007;
		result = result % 10007;
	}
	printf("%d\n", result);

	return 0;
}