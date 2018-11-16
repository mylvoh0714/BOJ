#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


inline long long max(int n)
{
	return n >= 0 ? n : -n;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<long long> a(n);
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	sort(a.begin(), a.end());

	long long min = 3000000000;
	vector<long long> ans;
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			auto idx = lower_bound(a.begin(), a.end(), -a[i] - a[j]) - a.begin();
			for ( int k = idx - 2; k <= idx + 2; k++ )
			{
				if ( k < 0 || k >= n ) continue; // out of index
				if ( k == i || k == j ) continue; // duplicate

				if ( min > abs(a[i] + a[j] + a[k]) ) {
					min = abs(a[i] + a[j] + a[k]);
					if ( !ans.empty() ) ans.clear();
					
					ans.push_back(a[i]);
					ans.push_back(a[j]);
					ans.push_back(a[k]);
				}
			}
		}
	}
	for ( long long &i : ans ) cout << i << ' ';
}