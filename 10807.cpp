// 10807 개수 세기
#include <cstdio>
int N, num, target;
int count[201];


int main()
{	
	scanf("%d", &N);
	for ( int i = 0; i < N; i++ )
	{
		scanf("%d", &num);
		count[num+100]++; // range = [-100,100]
	}
	scanf("%d", &target);
	printf("%d",count[target + 100]);
	return 0;
}