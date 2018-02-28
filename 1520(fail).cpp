// BOJ_1520 내리막길
#include <iostream>
using namespace std;
int Arr[501][501], dp[501][501];
int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	for ( int i = 1; i <= M; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			scanf("%d", &Arr[i][j]);
		}
	}
	dp[1][1] = 1;
	for ( int i = 1; i <= M; i++ )
	{
		for ( int j = 1; j <= N; j++ )
		{
			if ( Arr[i + 1][j] > Arr[i][j] )
				dp[i + 1][j] += dp[i][j];
			else
				dp[i][j] += dp[i + 1][j];
			if ( Arr[i][j + 1] > Arr[i][j] )
				dp[i][j + 1] += dp[i][j];
			else
				dp[i][j] += dp[i][j + 1];
			
		}
	}
	printf("%d", Arr[M][N]);
}