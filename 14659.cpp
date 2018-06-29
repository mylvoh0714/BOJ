#include <iostream>
using namespace std;
int a[30001];
int b[30001];
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = i + 1; j <= n; j++ )
		{
			if ( a[i] > a[j] )
				b[i]++;
			else if ( a[i] < a[j] )
				break;
		}
	}

	int result = 0;
	for ( int i = 1; i <= n; i++ )
	{
		if ( result < b[i] )
			result = b[i];
	}
	cout << result << '\n';
	return 0;
}