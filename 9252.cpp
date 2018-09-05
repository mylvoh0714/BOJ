// BOJ 9252 LCS2
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int trace[1001][1001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s1, s2;
	cin >> s1;
	cin >> s2;
	int len1 = s1.size();
	int len2 = s2.size();
	for ( int i = 0; i < len1; i++ )
	{
		for ( int j = 0; j < len2; j++ )
		{
			if ( s1[i] == s2[j] ) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				trace[i][j] = 1;
			}
			else {
				if ( dp[i - 1][j] > dp[i][j - 1] ) {
					dp[i][j] = dp[i - 1][j];
					trace[i][j] = 2;
				}
				else {
					dp[i][j] = dp[i][j - 1];
					trace[i][j] = 3;
				}
			}
		}
	}
	len1--; len2--;
	cout << dp[len1][len2] << '\n';
	string ans = "";
	while ( len1 >= 0 && len2 >= 0 )
	{
		if ( trace[len1][len2] == 1 ) {
			ans = s1[len1] + ans;
			len1--; len2--;
		}
		else if ( trace[len1][len2] == 2 ) {
			len1--;
		}
		else
			len2--;
	}
	cout << ans << '\n';
}