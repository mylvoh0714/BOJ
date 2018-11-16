#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int a[1001];

bool cmp(const pair<int, pair<int, int>>p1, const pair<int, pair<int, int>>p2)
{
	return p1.first < p2.first;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int w, n;
	cin >> w >> n;
	for ( int i = 0; i < n; i++ ) cin >> a[i];
	
	vector<pair<int,pair<int,int>>> v;
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			v.push_back({ a[i] + a[j],{i,j}});
		}
	}
	sort(v.begin(), v.end());

	for ( int i = 0; i<(int)v.size();i++ )
	{
		if ( binary_search(v.begin(), v.end(), pair<int, pair<int, int>>({ w - v[i].first, { 0,0 } }),cmp) ) {
			auto lower = lower_bound(v.begin(), v.end(), pair<int, pair<int, int>>({ w - v[i].first, { 0,0 } }),cmp) - v.begin();
			auto upper = upper_bound(v.begin(), v.end(), pair<int, pair<int, int>>({ w - v[i].first, { 0,0 } }),cmp) - v.begin();
			/*cout << "lower : " << lower << endl;
			cout << "upper : " << upper << endl;*/
			for ( int j = lower; j < upper; j++ )
			{
				if ( v[j].second.first == v[i].second.first || v[j].second.first == v[i].second.second || v[j].second.second == v[i].second.first || v[j].second.second == v[i].second.second )
					continue;

				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";

}