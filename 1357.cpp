#include <cstdio>

int main()
{
	int x, y;
	scanf("%d %d", &x,&y);
	
	const int r = 10;
	int sumX = 0;
	while ( x > 0 )
	{
		sumX *= r;
		sumX += x % 10;
		x /= 10;
	}
	int sumY = 0;
	while ( y > 0 )
	{
		sumY *= r;
		sumY += y % 10;
		y /= 10;
	}

	int sumZ = sumX + sumY;
	int ans = 0;
	while ( sumZ > 0 )
	{
		ans *= r;
		ans += sumZ % 10;
		sumZ /= 10;
	}
	printf("%d\n", ans);
}