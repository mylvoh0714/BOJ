#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	for ( int tt = 0; tt < t; tt++ )
	{
		int n; cin >> n;
		vector<int> a(n);
		for ( int i = 0; i < n; i++ ) cin >> a[i];
		
		int ans = -987654321;
		int psum = 0;
		for ( int i = 0; i < n; i++ ) {
			psum = max(psum, 0) + a[i];
			ans = max(ans, psum);
		}
		cout << ans << '\n';
	}

}