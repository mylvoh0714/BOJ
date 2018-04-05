#include <iostream>
using namespace std;
long long dp[91][2]; // dp[n][0]은 n자리숫자 끝이 0인 이친수, dp[n][1]은 n자리숫자 끝이 1인 이친수

int main()
{
	int n;
	scanf("%d", &n);
	dp[1][0] = 0;
	dp[1][1] = 1;
	for ( int i = 2; i <= n; i++ )
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	long long result = dp[n][0] + dp[n][1];
	printf("%lld\n", result);
}