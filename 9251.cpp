// BOJ_9251 LCS
#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001];
string str1, str2;

int main()
{
	cin >> str1 >> str2;
	for ( int i = 1; i <= str1.size(); i++ )
	{
		for ( int j = 1; j <= str2.size(); j++ )
		{
			if(str1[i-1] == str2[j-1] )
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
			{
				if ( dp[i - 1][j] < dp[i][j - 1] )
				{
					dp[i][j] = dp[i][j - 1];
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[str1.size()][str2.size()] << "\n";
	return 0;	
}