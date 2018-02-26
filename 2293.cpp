// 2283 동전

// dp[] = 0 1 2 3 4 5 6 7 8 9 10
//  1     1 1 1 1 1 1 1 1 1 1 1
//  2     1 1 2 2 3 3 4 4 5 5 6 
//  5     1 1 2 2 3 4 5 6 7 8 10
#include <iostream>
using namespace std;
int N, K;
int coin[101];
int dp[10001];

int main()
{
	scanf("%d %d", &N, &K);
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &coin[i]); // 1,2,5 입력
	}
	dp[0] = 1;
	
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= K; j++ )
		{
			if ( j >= coin[i] ) dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d", dp[K]);
}