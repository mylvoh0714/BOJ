#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if ( b == 0 )
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for ( int i = 0; i < t; i++ )
	{
		int a, b;
		cin >> a >> b;
		int GCD = gcd(a, b);
		int ga = a / GCD;
		int gb = b / GCD;
		long long ans = GCD*ga*gb;
		cout << ans << '\n';
	}

}