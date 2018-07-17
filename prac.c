#include <stdio.h>
#include <stdlib.h>

struct Univer {
	char name[101];
	int drink;
};

int main()
{
	int T;
	scanf("%d", &T);
	for ( int TestCase = 0; TestCase < T;TestCase++ )
	{
		int ans_drink = 0;
		const char* ans_name;
		int n;
		scanf("%d", &n);
		struct Univer *Uarr = ( struct Univer* )malloc(sizeof(struct Univer)*n);
		for ( int i = 0; i < n; i++ )
		{
			scanf("%s %d", Uarr[i].name, &Uarr[i].drink);
			if ( Uarr[i].drink > ans_drink ) {
				ans_drink = Uarr[i].drink;
				ans_name = Uarr[i].name;
			}
		}
		printf("%s\n", ans_name);
		free(Uarr);
	}
}