#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m, k;
	cin >> n >> m;
	vector<vector<int>> matrixA(n + 1); // matrixA = n by m 
	
	for ( int i = 1; i <= n; i++ )
	{
		matrixA[i].resize(m + 1);
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			cin >> matrixA[i][j];
		}
	}

	cin >> m >> k;
	vector<vector<int>> matrixB(m + 1); // matrixB = m by k
	
	for ( int i = 1; i <= m; i++ )
	{
		matrixB[i].resize(k + 1);
	}

	for ( int i = 1; i <= m; i++ )
	{
		for ( int j = 1; j <= k; j++ )
		{
			cin >> matrixB[i][j];
		}
	}

	vector<vector<int>> resultM(n + 1);

	for ( int i = 1; i <= n; i++ )
	{
		resultM[i].resize(k + 1);
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= k; j++ )
		{
			for ( int l = 1; l <= m; l++ )
			{
				resultM[i][j] += matrixA[i][l] * matrixB[l][j];
			}
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= k; j++ )
		{
			cout << resultM[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}