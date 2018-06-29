#include <iostream>
#include <cmath>
using namespace std;
bool isNonPrime[246913]; 

// Make Eratosthenes arr in range [2,num]
void MakePrimeArr(int num)
{
	isNonPrime[1] = true;
	for ( int i = 2; i <= num; i++ )
	{
		int root = sqrt(i);
		for ( int j = 2; j <= root; j++ )
		{
			if ( i%j == 0 ) {
				isNonPrime[i] = true;
				break;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	MakePrimeArr(246912); // 246912 = 123456 * 2
	int n;
	while ( cin >> n && n != 0 )
	{
		int cnt = 0;
		for ( int i = n + 1; i <= 2 * n; i++ )
		{
			if ( isNonPrime[i] == false )
				cnt += 1;
		}
		cout << cnt << '\n';
	}
}