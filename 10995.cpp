#include <iostream>
using namespace std;

void print(int n)
{
	for ( int i = 1; i <= n; i++ )
	{
		if ( i % 2 == 1 )
		{
			for ( int i = 1; i <= n; i++ )
			{
				cout << '*';
				cout << ' ';
			}
			cout << '\n';
		}
		else
		{
			for ( int i = 1; i <= n; i++ )
			{
				cout << ' ';
				cout << '*';
			}
			cout << '\n';
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	print(n);
}