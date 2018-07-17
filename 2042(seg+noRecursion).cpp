#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> tree;
int tSize = 1; // number of treeNode size
				// n(treeNode) = n(leafNode)-1;
				// total tree size = 2*tSize+1;

void update(int target, ll diff)
{
	target += tSize;
	tree[target] += diff;
	while ( target > 1 )
	{
		tree[target / 2] += diff;
		target /= 2;
	}
}

ll sum(int l, int r) // left index, right index
{
	l += tSize;
	r += tSize;
	ll ret = 0;
	while ( l < r )
	{
		// process l.
		if ( l % 2 == 0 ) { // if left child node
			l /= 2;
		}
		else {
			ret += tree[l];
			l += 1; // go right
			l /= 2; // go up
		}

		// process r.
		if ( r % 2 == 1 ) { // if right child node
			r /= 2;
		}
		else {
			ret += tree[r];
			r -= 1;
			r /= 2;
		}
	}
	if ( l == r ) {
		ret += tree[l];
	}
	return ret;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	m += k;
	while ( tSize <= n )
	{
		tSize *= 2;
	}
	tree.resize(tSize * 2+1);
	tSize -= 1;
	for ( int i = 1; i <= n; i++ )
	{
		ll temp;
		cin >> temp;
		update(i, temp);
	}
	while ( m-- )
	{
		int t1, t2;
		ll t3;
		cin >> t1;
		if ( t1 == 1 ) {
			cin >> t2 >> t3;
			update(t2, t3 - tree[tSize + t2]);
		}
		else if ( t1 == 2 ) {
			cin >> t2 >> t3;
			cout << sum(t2, t3) << '\n';
		}
	}
	return 0;
}