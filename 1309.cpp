#include <iostream>
using namespace std;

int dp[100001][3]; // dp[n][0]:n번째줄 not exist, dp[n][1]: n번째 왼쪽에 사자 exist, dp[n][2]: n번째 오른쪽에 사자exist

int main()
{
	int n; scanf("%d", &n);
	dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;
	for ( int i = 2; i <= n; i++ )
	{
		dp[i][0] = ( dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] ) % 9901;
		dp[i][1] = ( dp[i - 1][0] + dp[i - 1][2] ) % 9901;
		dp[i][2] = ( dp[i - 1][0] + dp[i - 1][1] ) % 9901;
	}
	int ans = 0;
	ans = dp[n][0] + dp[n][1] + dp[n][2];
	ans %= 9901;
	cout << ans << '\n';
}
