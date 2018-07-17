#include <iostream>
using namespace std;
int arr[322582];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		int val;
		cin >> val; 
		if ( (arr[val/31] & (1<<(val%31)) ) != 0) {
			cout << val << '\n';
			return 0;
		}
		else
			arr[val / 31] |= 1 << ( val % 31 );
	}
	return 0;
}