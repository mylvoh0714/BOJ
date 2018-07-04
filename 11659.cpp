#include <iostream>
using namespace std;
int a[100001];
int s[100001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}

	s[1] = a[1];
	for ( int i = 2; i <= n; i++ )
	{
		s[i] = s[i - 1] + a[i];
	}

	for ( int i = 1; i <= m; i++ )
	{
		int a, b;
		cin >> a >> b;
		cout << s[b] - s[a - 1] << '\n';
	}
	return 0;
}