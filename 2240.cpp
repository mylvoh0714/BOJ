#include <iostream>
#include <algorithm>
using namespace std;
int t, w;
int arr[1001];
int dp[1001][31]; // dp[sec][move] = sec초에 move번만큼 움직였을때 받은 자두의 개수
int main()
{
	
	scanf("%d %d", &t, &w);
	for ( int i = 1; i <= t; i++ )
	{
		scanf("%d", &arr[i]);
	}
	if ( arr[1] == 1 )
		dp[1][0] = 1;
	else if ( arr[1] == 2 )
		dp[1][1] = 1;

	for ( int i = 2; i <= t; i++ )
	{
		dp[i][0] = arr[i] == 1 ? dp[i - 1][0] + 1 : dp[i - 1][0];
		for ( int j = 1; j <= w; j++ )
		{
			if ( j > i )
				break;
			int pos = j % 2 == 0 ? 1 : 2;
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + ( arr[i] == pos );
		}
	}
	
	int result = 0;
	for ( int i = 0; i <= w; i++ )
	{
		if ( result < dp[t][i] )
			result = dp[t][i];
	}
	printf("%d\n", result);
	
	return 0;
}