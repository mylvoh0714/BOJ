#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
vector<int> dp;
int n, result;

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	scanf("%d", &n);
	arr.resize(n+1); dp.resize(n+1);
	for ( int i = 1; i <= n; i++ ) 
		scanf("%d", &arr[i]);
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j < i; j++ )
		{
			if ( arr[j] < arr[i] )
			{
				if ( dp[i] < dp[j] )
					dp[i] = dp[j];
			}
		}
		dp[i] = dp[i] + 1;
	}

	for ( int i = 1; i <= n; i++ )
	{
		result = max(result, dp[i]);
	}
	printf("%d\n", result);
}