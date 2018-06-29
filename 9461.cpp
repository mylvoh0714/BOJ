#include <iostream>
using namespace std;
typedef long long ll;
ll dp[101] = { 0,1,1,1,2,2,2, };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;

	for ( int i = 6; i <= 100; i++ )
	{
		dp[i] = dp[i - 1] + dp[i - 5];

	}
	for ( int i = 1; i <= T; i++ )
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}