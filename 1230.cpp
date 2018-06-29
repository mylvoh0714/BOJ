// BOJ 1230 문자열거리
#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001];

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	
	int len1 = str1.size();
	int len2 = str2.size();
	str1 = " " + str1;
	str2 = " " + str2;
	for ( int i = 0; i <= len1; i++ )
	{
		for ( int j = 0; j <= str2.size(); j++ ) 
		{
			dp[i][j] = 9999999999;
		}
	}

	dp[0][0] = 0;
	for ( int i = 1; i <= len2; i++ ) {
		dp[0][i] = 1;
	}

	for ( int j = 1; j <= str2.size(); j++ )
	{
		for ( int i = 1; i <= str1.size(); i++ ) 
		{
			if ( str1[i] == str2[j] ) {
				dp[i][j] = dp[i - 1][j - 1];
			}

			for ( int k = 1; k <= j - 1; k++ ) 
			{
				if ( dp[i][j] > dp[i][k] + 1 ) {
					dp[i][j] = dp[i][k] + 1;
				}
			}
		}
	}
	if ( dp[len1][len2] > len1 + len2 ) {
		cout << -1 << '\n';
	}
	else {
		cout << dp[len1][len2] << '\n';
	}

	return 0;
}