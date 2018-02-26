// BOJ_2579 계단오르기
#include <iostream>
using namespace std;
int N, Arr[301], D[301];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &N);
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &Arr[i]);
		D[i] = max(D[i - 2], D[i - 3] + Arr[i - 1]) + Arr[i];
	}
	printf("%d", D[N]);
	return 0;
}