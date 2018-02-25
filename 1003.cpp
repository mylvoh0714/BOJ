// 1003 피보나치 함수
#include <iostream>
using namespace std;
int fibo[41][2];

int main()
{
	int Testcase, N;

	fibo[0][0] = 1, fibo[0][1] = 0;
	fibo[1][0] = 0, fibo[1][1] = 1;
	for ( int i = 2; i < 41; i++ )
	{
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}

	scanf("%d", &Testcase);
	while ( Testcase-- )
	{
		scanf("%d", &N);
		printf("%d %d\n", fibo[N][0], fibo[N][1]);
	}
}