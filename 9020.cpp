#include <iostream>
using namespace std;
bool NonPrimeSet[10001] = { false };
int input,TestCase;

void Make_Prime_Array()
{
	for ( int i = 2; i < 10001; i++ )
	{
		if ( NonPrimeSet[i] == false )
		{
			for ( int j = i + i; j < 10001; j += i )
			{
				NonPrimeSet[j] = true;
			}
		}
	}
}

bool isNonPrime(int num)
{
	if ( num == 1 )
		return true;
	return NonPrimeSet[num];
}

int main()
{
	scanf("%d", &TestCase);
	while ( TestCase-- )
	{
		int a, b;
		int temp = 10000;
		Make_Prime_Array();
		scanf("%d", &input);
		for ( int i = 2; i < input; i++ )
		{
			if ( isNonPrime(i) == false && isNonPrime(input - i) == false )
			{
				if ( temp >(input - i) - i && ( input - i ) - i >= 0 )
				{
					a = i;
					b = input - i;
					temp = ( input - i ) - i;
				}
			}
		}
		printf("%d %d\n", a, b);
	}
}