// BOJ 2248 ������ ã��
#include <iostream>
using namespace std;
int dp[32][32]; // dp[N][L] : n�ڸ�, 1�ǰ����� L���� �������� ����
				// dp[N][L] = dp[N-1][L] + dp[N-1][L-1]
int main()
{
	int n, l, k;
	cin >> n >> l >> k;
	dp[1][0] = 1; dp[1][1] = 1;

	for ( int j = 0; j <= l; j++ )
	{
		for ( int i = 2; i <= n; i++ )
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	for ( int i = 0; i <= l; i++ )
	{
		cout << dp[n][i] << endl;
	}
}