// BOJ_1065 ÇÑ¼ö
#include <iostream>
using namespace std;
int n, cnt;

bool isHanNumber(int num)
{
	if ( num < 100 )
		return true;
	else if(num == 1000)
		return false;
	// 1<=num<=1000
	int a, b, c; // 341
	a = num / 100; num -= 100 * a;
	b = num / 10; num -= 10 * b;
	c = num / 1;
	if ( a - b == b-c )
		return true;
	else
		return false;
}

int main()
{
	scanf("%d", &n);

	for ( int i = 1; i <= n; i++ )
	{
		if ( isHanNumber(i) )
			cnt++;
	}
	printf("%d", cnt);
}