#include <iostream>
using namespace std;
int arr_fibo[46];

int fibo(int n)
{
	if ( n <= 1 )
		return n;
	else
	{
		if ( arr_fibo[n] > 0 )
			return arr_fibo[n];
	}

	return arr_fibo[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fibo(n));
}
