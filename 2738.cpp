#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrixA(n+1);
	vector<vector<int>> matrixB(n+1);
	for ( int i = 1; i <= n; i++ )
	{
		matrixA[i].resize(m + 1);
		matrixB[i].resize(m + 1);
	}
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			cin >> matrixA[i][j];
		}
	}
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			cin >> matrixB[i][j];
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			matrixB[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
		{
			cout << matrixB[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}