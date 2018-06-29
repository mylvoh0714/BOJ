#include <iostream>
using namespace std;
int arr[21];
int n, m;
int result = 0;

void go(int i, int sum)
{
	if ( i == n+1 ) {
		if ( sum == m ) {
			result++;
		}
		return;
	}
	go(i + 1, sum + arr[i]);
	go(i + 1, sum);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for ( int i = 1; i <= n; i++ )
	{
		cin >> arr[i];
	}
	go(1, 0);
	if ( m == 0 )
		result--;
	cout << result << '\n';
	return 0;
}