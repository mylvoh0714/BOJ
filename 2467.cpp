#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int abs(int num) {
	return num >= 0 ? num : -num;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> a(n);
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	int ans = 2000000000;
	vector<int> ansVec;
	for ( int i = 0; i < n; i++ )
	{
		int val = -a[i];
		auto idx1 = lower_bound(a.begin(), a.end(), val) - a.begin();
		for ( int j = idx1-1; j <= idx1+1; j++ )
		{
			if ( j < 0 || j >= n ) continue; // out of index
			if ( i == j ) continue; // equal element

			if ( abs(a[i] + a[j]) < ans ) {
				ans = abs(a[i] + a[j]);
				if ( ansVec.size() > 0 ) 
					ansVec.clear();
				
				ansVec.push_back(a[i]);
				ansVec.push_back(a[j]);
			}
		}
	}
	for ( auto &i : ansVec ) cout << i << ' ';
}