#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		int val = i;
		int sum = i;
		sum += val / 100000;
		val -= ( val / 100000 ) * 100000;
		sum += val / 10000;
		val -= ( val / 10000 ) * 10000;
		sum += val / 1000;
		val -= ( val / 1000 ) * 1000;
		sum += val / 100;
		val -= ( val / 100 ) * 100;
		sum += val / 10;
		val -= ( val / 10 ) * 10;
		sum += val;
		if ( sum == n ) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
}