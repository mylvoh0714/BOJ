#include <iostream>
using namespace std;
int arr[1001];
int vote[1001];
int simsa[1001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d", &arr[i]);
	}
	for ( int i = 1; i <= m; i++ )
	{
		scanf("%d", &simsa[i]);
	}

	for ( int j = 1; j <= m; j++ )
	{
		for ( int i = 1; i <= n; i++ )
		{
			if ( simsa[j] >= arr[i] )
			{
				vote[i]++;
				break;
			}
		}
	}
	int maxVote = 0;
	int maxNum;
	for ( int i = 1; i <= n; i++ )
	{
		if ( maxVote < vote[i] )
		{
			maxVote = vote[i];
			maxNum = i;
		}
	}
	printf("%d\n", maxNum);
}