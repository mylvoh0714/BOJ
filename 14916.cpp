#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt2, cnt5;
	cnt2 = cnt5 = 0;
	
	if ( n < 5 ) {
		if ( n % 2 != 0 ) {
			cout << -1;
			return 0;
		}
		else {
			cout << n / 2;
			return 0;
		}
	}

	// n이 5이상이라 가정
	cnt5 = n / 5;
	while ( cnt5>=0 )
	{
		if ( ( n - 5 * cnt5 ) % 2 == 0 ) {
			cnt2 = ( n - 5 * cnt5 ) / 2;
			break;
		}
		cnt5--;
	}

	cout << cnt2 + cnt5 << '\n';
	return 0;
}