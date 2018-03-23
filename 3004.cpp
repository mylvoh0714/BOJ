#include <iostream>
using namespace std;

int n, result;

int main()
{
	scanf("%d", &n);
	if ( n % 2 == 1 )
	{
		for ( int i = 1; i <= n / 2 + 1; i++ )
		{
			result += i;
		}
		result *= 2;
	}
	else
	{
		for ( int i = 1; i <= n / 2 + 1; i++ )
		{
			result += i;
		}
		result = result * 2 - ( n / 2 + 1 );
	}
	printf("%d\n", result);
}