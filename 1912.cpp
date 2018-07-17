#include <iostream>
using namespace std;
int arr[100001];
int sum[100001];

int main()
{
	int N;
	scanf("%d", &N);
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}

	int min = 0;
	int ans = -0x7fffff;
	for ( int i = 1; i <= N; i++ )
	{
		if ( sum[i] - min > ans ) {
			ans = sum[i] - min;
		}
		if ( sum[i] < min) min = sum[i];
	}
	printf("%d\n", ans);
}