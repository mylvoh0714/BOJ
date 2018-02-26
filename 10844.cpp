// 10844_���� ��ܼ�
#include <iostream>
#define mod 1000000000;
using namespace std;

int N;
int d[101][10]; // d[101][6]�� ���̰� 101�̰� ���������ڰ� 6�� ������ ��� ��
int main()
{
	scanf("%d", &N);
	for ( int i = 1; i <= 9; i++ )
	{
		d[1][i] = 1;
	}
	for ( int i = 2; i <= N; i++ )
	{
		for ( int j = 0; j <= 9; j++ )
		{
			if ( j == 0 ) d[i][j] = d[i - 1][j + 1];
			else if ( j == 9 ) d[i][j] = d[i - 1][j - 1];
			else d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}
	long long result = 0;
	for ( int i = 0; i <= 9; i++ )
	{
		result += d[N][i];
	}
	result = result % mod;
	printf("%lld", result);
}