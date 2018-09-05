// BOJ 2616 ���������
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[50001][4]; // dp[n][j] : n��° ��������, ����� j�밡 �ִ� ����Ҽ��ִ� �մ��� ��
int a[50001];
int s[50001];

int subSum(int x, int y) // x <= y
{
	return s[y] - s[x - 1];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	int m; cin >> m;
	for ( int j = 1; j <= 3; j++ )
	{
		for ( int i = m; i <= n; i++ )
		{
			dp[i][j] = max(dp[i-1][j],dp[i - m][j - 1]+subSum(i-m+1,i));
		}
	}
	cout << dp[n][3] << endl;
}