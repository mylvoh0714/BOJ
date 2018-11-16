#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[100004];
int minldp[100004];
int minrdp[100004];
int maxldp[100004];
int maxrdp[100004];
int r_minldp[100004];
int r_minrdp[100004];
int r_maxldp[100004];
int r_maxrdp[100004];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for ( int i = 1; i <= n; i++ ) cin >> arr[i];
	for ( int i = 1; i <= n; i++ )
	{
		minldp[i] = min(arr[i], minldp[i - 1] + arr[i]);
		maxldp[i] = max(arr[i], maxldp[i - 1] + arr[i]);
	}
	for ( int i = n; i >= 1; i-- )
	{
		minrdp[i] = min(arr[i], minrdp[i + 1] + arr[i]);
		maxrdp[i] = max(arr[i], maxrdp[i + 1] + arr[i]);
	}
	r_minldp[1] = r_maxldp[1] = arr[1];
	for ( int i = 2; i <= n; i++ )
	{
		r_minldp[i] = min(r_minldp[i - 1], minldp[i]);
		r_maxldp[i] = max(r_maxldp[i - 1], maxldp[i]);
	}
	r_minrdp[n] = r_maxrdp[n] = arr[n];
	for ( int i = n-1; i >= 1; i-- )
	{
		r_minrdp[i] = min(r_minrdp[i + 1], minrdp[i]);
		r_maxrdp[i] = max(r_maxrdp[i + 1], maxrdp[i]);
	}
	long long ans = -987654321;
	for ( int i = 1; i <= n-1; i++ )
	{
		ans = max(ans, (ll)r_minldp[i] * r_minrdp[i+1]);
		ans = max(ans, (ll)r_minldp[i] * r_maxrdp[i+1]);
		ans = max(ans, (ll)r_maxldp[i] * r_minrdp[i+1]);
		ans = max(ans, (ll)r_maxldp[i] * r_maxrdp[i+1]);
	}
	cout << ans << '\n';
}