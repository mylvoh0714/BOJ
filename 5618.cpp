#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
	if ( b == 0 )
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int n;
	scanf("%d", &n);

	int GCD;
	if ( n == 2 )
	{
		int a, b;
		scanf("%d %d", &a, &b);
		GCD = gcd(a, b);
	}
	else
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		GCD = gcd(a, b);
		GCD = gcd(GCD, c);
	}

	double root = sqrt(GCD);
	for ( int i = 1; i <= GCD; i++ )
	{
		if ( GCD%i == 0 )
			printf("%d\n", i);
	}
	return 0;
}