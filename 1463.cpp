// BOJ_1463 1로 만들기
#include <iostream>
using namespace std;
int D[1000001]; // D[500] is minimum number of cost to make 1
int N;

int main()
{
	scanf("%d", &N);
	for ( int i = 2; i <= N; i++ )
	{
		D[i] = D[i - 1] + 1;
		if ( i % 2 == 0 && D[i] > D[i / 2] + 1 )
		{
			D[i] = D[i / 2] + 1;
		}
		if ( i % 3 == 0 && D[i] > D[i / 3] + 1 )
		{
			D[i] = D[i / 3] + 1;
		}
	}
	printf("%d\n", D[N]);
}