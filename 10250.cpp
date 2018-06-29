#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for ( int i = 1; i <= T;i++ )
	{
		int h, w, n;
		cin >> h >> w >> n;
		n--;
		printf("%d%02d\n", n%h + 1, n / h + 1);
	}

	return 0;
}