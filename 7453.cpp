#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	vector<int> c(n + 1);
	vector<int> d(n + 1);

	vector<int> ab;
	vector<int> cd;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			ab.push_back(a[i] + b[j]);
			cd.push_back(-(c[i] + d[j]));
		}
	}
	
	sort(cd.begin(), cd.end());

	long long ans = 0;
	for ( int i : ab )
	{
		if ( binary_search(cd.begin(), cd.end(), i) )
		{
			auto lower = lower_bound(cd.begin(), cd.end(), i) - cd.begin();
			auto upper = upper_bound(cd.begin(), cd.end(), i) - cd.begin();
			ans += upper - lower;
		}
	}
	cout << ans << '\n';

	return 0;
}