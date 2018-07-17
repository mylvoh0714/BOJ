#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[501][501]; // dp[n][m] n번쨰행렬~ m번째행렬 행렬곱 최소 연산 횟수.

struct matrix {
	int row;
	int col;
};
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<matrix> arr(n + 1);
	for ( int i = 1; i <= n; i++ )
		cin >> arr[i].row >> arr[i].col;

	int i = 1;
	for ( int len = 1; len <= n-1; len++ ) 
	{
		for ( i=1; i <= n - len; i++ )
		{
			int j = i + len;
			dp[i][j] = 0x7fffffff;
			for ( int k = i; k < j; k++ )
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i].row*arr[k].col*arr[j].col);
			}
		}
	}
	cout << dp[1][n] << '\n';
}