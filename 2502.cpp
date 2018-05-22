//BOJ 2502 ถฑ ธิดย ศฃถ๛ภฬ
#include <iostream>
using namespace std;
typedef long long ll;
ll arr[31];

int main()
{
	int day;
	int n;
	scanf("%d %d", &day, &n);
	arr[1] = arr[2] = 1;
	for ( int i = 3; i <= day; i++ )
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	ll a, b;
	ll coef_a = arr[day - 2];
	ll coef_b = arr[day - 1];
	
	for ( int i = 1; coef_a * i < n; i++ )
	{
		if ( ( n - coef_a*i ) % coef_b == 0 )
		{
			a = i;
			b = ( n - coef_a*a ) / coef_b;
			break;
		}
	}
	printf("%lld\n", a);
	printf("%lld\n", b);

	return 0;
}