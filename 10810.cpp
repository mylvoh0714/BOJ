// 10810 °ø ³Ö±â
#include <iostream>
int Arr[101];

int main()
{
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	
	while ( M-- )
	{
		scanf("%d %d %d", &i, &j, &k);
		while ( i <= j )
			Arr[i++] = k;
	}
	
	for ( i = 1; i <= N; i++ ) // print
	{
		printf("%d ", Arr[i]);
	}
}