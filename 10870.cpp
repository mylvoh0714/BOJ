#include <iostream>
using namespace std;
long long fibo[101];
int n;

long long fibonacci(int num)
{
	if ( num <= 1 ) return num;
	else
	{
		if ( fibo[num] > 0 ) return fibo[num];
	}
	fibo[num] = fibonacci(num - 1) + fibonacci(num - 2);
	return fibo[num];
}

int main()
{
	scanf("%d", &n);
	printf("%lld\n", fibonacci(n));
}