#include <iostream>
using namespace std;

void _main(int num)
{
	int a, b;
	cin >> a >> b;
	int ret = 1;
	for ( int i = 0; i < b; i++ )
	{
		ret *= ( a % 10 );
		if ( ret > 1000 )
			ret %= 10;
	}
	if ( ret % 10 == 0 )
		cout << "10" << '\n';
	else
		cout << ret%10 << '\n';
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for ( int i = 0; i < T; i++ )
	{
		_main(T);
	}
	return 0;
}