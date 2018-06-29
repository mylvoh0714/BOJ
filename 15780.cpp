#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for ( int i = 1; i <= k; i++ )
	{
		int temp;
		cin >> temp;
		sum += ( temp + 1 ) / 2;
	}
	if ( sum >= n )
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	
}