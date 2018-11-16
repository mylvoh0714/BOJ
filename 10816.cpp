// 10816_숫자카드2
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[500001];
int b[500001];
int main()
{
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ ) scanf("%d", a + i);
	scanf("%d", &m);
	for ( int i = 0; i < m; i++ ) scanf("%d", b + i);
	sort(a, a + n);
	for ( int i = 0; i < m; i++ ) {
		int tar = b[i];
		auto itr1 = lower_bound(a, a + n, tar) - a;
		auto itr2 = upper_bound(a, a + n, tar) - a;
		cout << itr2 - itr1 << ' ';
	}
}