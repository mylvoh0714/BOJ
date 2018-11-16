#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1000001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		cin >> a[i];
	}
	vector<int> lis;
	lis.push_back(a[0]);
	int ans = 1;

	for ( int i = 1; i < n; i++ )
	{
		int itr = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if ( itr == lis.size() ) lis.push_back(a[i]);
		else {
			lis[itr] = a[i];
		}
	}
	cout << lis.size() << '\n';
}