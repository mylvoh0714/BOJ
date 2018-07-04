#include <cstdio>

int main()
{
	while ( 1 )
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if ( a == 0 && b == 0 )
			break;

		int q = a / b;
		a -= q*b;
		printf("%d %d / %d\n", q, a, b);
	}
	return 0;
}