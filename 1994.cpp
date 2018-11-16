#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[2001][2001];
vector<int> arr;

// return dp[i][j]
int go(int i, int j)
{
	if ( i > j ) return 0;
	else if ( i == j ) return 1;

	int &ret = dp[i][j];
	if ( ret != 0 ) return ret;

	int next = arr[j] + ( arr[j] - arr[i] );
	int idx = lower_bound(arr.begin(), arr.end(), next) - arr.begin();

	if ( arr[idx] == next )
		return ret = go(j, idx) + 1;
	else
		return ret = 2;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	arr.resize(n);
	for ( int i = 0; i < n; i++ ) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int ans = 1;
	int cnt = 1;
	for ( int i = 1; i < n; i++ )
	{
		if ( arr[i] == arr[i - 1] ) {
			cnt++;
		}
		else {
			if ( cnt > ans ) ans = cnt;
			cnt = 1;
		}
	}
	if ( cnt > ans ) ans = cnt;
	for ( auto itr = arr.begin()+1 ;itr!=arr.end(); )
	{
		if ( *itr == *( itr - 1 ) ) {
			itr = arr.erase(itr);
		}
		else {
			itr++;
		}
	}
	
	n = arr.size();
	cout << n << endl;
	/*for ( int i = 0; i < n - 1; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			int temp = go(i, j);
			if ( ans < temp ) ans = temp;
		}
	}
	cout << ans << '\n';*/
}