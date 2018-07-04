#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<long long> s(n+1);
	vector<long long> cnt(m);
	for ( int i = 1; i <= n; i++ )
	{
		long long temp;
		cin >> temp;
		s[i] = s[i - 1] + temp;
	}
	for ( int i = 1; i <= n; i++ )
	{
		s[i] = s[i] % m;
	}
	for ( int i = 0; i <= n; i++ )
	{
		long long index = s[i];
		cnt[index] += 1;
	}

	long long ans = 0;
	for ( int i = 0; i < m; i++ )
	{
		if ( cnt[i] > 0 ) {
			long long val = cnt[i] * ( cnt[i] - 1 ) / 2;
			ans += val;
		}
	}
	cout << ans << '\n';
	return 0;
}