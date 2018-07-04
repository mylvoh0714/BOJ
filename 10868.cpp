// BOJ 10868 ÃÖ¼Ò°ª
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> arr;
vector<int> min_g;

int sqrt(int num)
{
	for ( int i = 1; i <= num; i++ )
	{
		if ( ( i + 1 )*( i + 1 ) > num )
			return i;
	}
	return -1;
}

int minquery(int s, int e, int r) // start ,end, root
{
	int ans = 1000000001;
	if ( s / r == e / r ) { // same group
		for ( int i = s; i <= e; i++ )
			ans = min(ans, arr[i]);
	}
	else {
		while ( true ) {
			ans = min(ans, arr[s]);
			s++;
			if ( s%r == 0 ) {
				break;
			}
		}
		while ( true ) {
			ans = min(ans, arr[e]);
			e--;
			if ( e%r == r - 1 ) {
				break;
			}
		}
		for ( int i = ( s / r ); i <= ( e / r ); i++ )
		{
			ans = min(ans, min_g[i]);
		}
	}
	return ans;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	arr.resize(n);
	for ( int i = 0; i < n; i++ )
	{
		cin >> arr[i];
	}

	int root = sqrt(n);
	min_g.resize(root + 1);

	for ( int i = 0; i < n; i++ )
	{
		if ( i%root == 0 ) {
			min_g[i / root] = arr[i];
		}
		else {
			min_g[i / root] = min(min_g[i / root], arr[i]);
		}
	}

	while ( m-- )
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << minquery(a, b, root) << '\n';
	}
	return 0;
}
