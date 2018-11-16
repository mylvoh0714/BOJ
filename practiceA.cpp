#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N,i;
	cin >> N;
	for ( i = 0; i <= 100; i++ ) {
		if ( 1 + i + i*i == N ) {
			cout << i << "\n"; return 0;
		}
	}
	return 0;
}