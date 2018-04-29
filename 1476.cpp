#include <iostream>
using namespace std;

int main()
{
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);
	int result = 1;
	int i, j, k;
	i = j = k = 1;
	
	while ( i != e || j != s || k != m )
	{
		result++;
		i++; j++; k++;
		if ( i == 16 ) i = 1;
		if ( j == 29 ) j = 1;
		if ( k == 20 ) k = 1;
	}
	printf("%d\n", result);
}