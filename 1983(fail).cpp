#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[401];
int b[401];
int dp[401][401][401]; // dp[n][m][k] : �� nĭ�� ä����, a�迭�� m������, b�迭�� k������ ��������� max
// a[] = {0,-3,-1,-2,5,-1}
// b[] = {0,-3,2,4,0,5,-2}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N; cin >> N;
	int idxA = 1;
	for ( int i = 1; i <= N; i++ )
	{
		int val;
		cin >> val;
		if ( val != 0 ) {
			a[idxA] = val;
			idxA++;
		}
	}
	int idxB = 1;
	for ( int i = 1; i <= N; i++ )
	{
		int val;
		cin >> val;
		if ( val != 0 ) {
			b[idxB++] = val;
			idxB++;
		}
	}
	

}