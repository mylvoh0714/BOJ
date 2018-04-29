// BOJ 1780 종이의 개수
#include <iostream>
#include <vector>
using namespace std;
int cnt[3]; // cnt[0] = numof(-1), cnt[1] = numof(0), cnt[2] = numof(1)
int arr[2500][2500]; // 3^7 < 2500

// return true if Matrix(=arr) entries are all same.
bool allSame(int rowStart, int colStart, int size)
{
	int temp = arr[rowStart][colStart];
	for ( int i = rowStart; i < rowStart + size; i++ )
	{
		for ( int j = colStart; j < colStart + size; j++ )
		{
			if ( temp != arr[i][j] )
				return false;
			temp = arr[i][j];
		}
	}
	return true;
}

void solve(int rowStart, int colStart, int size)
{
	if ( allSame(rowStart, colStart, size) == true )
	{
		cnt[arr[rowStart][colStart] + 1] ++;
		return;
	}
	int n = size / 3;
	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
		{
			solve(rowStart + i*n, colStart + j*n, n);
		}
	}
		
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			cin >> arr[i][j];
		}
	}
	solve(1, 1, n);
	for ( int i = 0; i < 3; i++ )
	{
		cout << cnt[i] << '\n';
	}
}