// BOJ_1932 숫자 삼각형
#include <iostream>
#include <algorithm>
using namespace std;

int N; 
int Arr[501][501], D[501][501]; // Arr = data input Arr, D[i][j] = i.row + j.column max dp Arr
 
int main()
{
	scanf("%d", &N);
	for ( int i = 1; i <= N; i++ )
	{
		for ( int j = 1; j <= i; j++ )
		{
			scanf("%d", &Arr[i][j]);
		}
	}
	D[1][1] = Arr[1][1];
	for ( int i = 2; i <= N; i++ )
	{
		for ( int j = 1; j <= i; j++ )
		{
			D[i][j] = max(D[i - 1][j - 1], D[i - 1][j]) + Arr[i][j];
		}
	}
	int result = 0;
	for ( int i = 1; i <= N; i++ )
	{
		if ( D[N][i] > result )
			result = D[N][i];
	}
	printf("%d\n", result);
}