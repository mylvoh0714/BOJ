// BOJ 2357 최소값과 최대값
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	vector<vector<int>> maxdp(n,vector<int>(n));
	vector<vector<int>> mindp(n,vector<int>(n));
	for ( int i = 0; i < n; i++ )
	{
		cin >> arr[i];
	}
	for ( int i = 0; i < n; i++ )
	{
		maxdp[i][i] = arr[i];
		mindp[i][i] = arr[i];
		for ( int j = i+1; j < n; j++ )
		{
			maxdp[i][j] = max(maxdp[i][j - 1], arr[j]);
			mindp[i][j] = min(mindp[i][j - 1], arr[j]);
		}
	}
	while ( m-- )
	{
		int a, b;
		cin >> a >> b;
		a--; b--; // order index -> array index
		cout << mindp[a][b] << ' ' << maxdp[a][b] << '\n';
	}

	return 0;
}
