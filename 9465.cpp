#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001][2];
int dp[100001][2];
int TestCase,n;

int main()
{
	scanf("%d", &TestCase);
	while ( TestCase-- )
	{
		scanf("%d", &n);
		for ( int i = 1; i <= n; i++ )
		{
			scanf("%d", &arr[i][0]);
		}
		for ( int i = 1; i <= n; i++ )
		{
			scanf("%d", &arr[i][1]);
		}
		dp[1][0] = arr[1][0];  dp[1][1] = arr[1][1];
		for ( int i = 2; i <= n; i++ )
		{
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + arr[i][0];
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + arr[i][1];
		}
		printf("%d\n", max(dp[n][0], dp[n][1]));
	}
}