// BOJ 10871 X보다 작은 수
#include <iostream>
using namespace std;
int Arr[10001];

int main()
{
	int N, target;
	scanf("%d %d", &N,&target);
	for(int i=0; i<N;i++)
	{
		scanf("%d", &Arr[i]);
	}
	for ( int i = 0; i < N; i++ )
	{
		if ( Arr[i] < target )
			printf("%d ", Arr[i]);
	}
	return 0;
}