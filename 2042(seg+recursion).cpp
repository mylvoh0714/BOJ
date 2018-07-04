#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
vector<ll> a;
vector<ll> tree;
ll init(int node, int s, int e)
{
	if ( s == e ) {
		return tree[node] = a[s];
	}
	else {
		return tree[node] = 
			init(node * 2, s, ( s + e ) / 2) + 
			init(node * 2 + 1, ( s + e ) / 2 + 1, e);
	}
}

void update(int node, int s, int e, int i, long long diff)
{
	if ( i < s || i > e )
		return;
	tree[node] = tree[node] + diff;
	if ( s != e ) {
		update(node * 2, s, ( s + e ) / 2, i, diff);
		update(node * 2 + 1, ( s + e ) / 2 + 1, e, i, diff);
	}
}

long long sum(int node, int s, int e, int i, int j)
{
	if ( i > e || j < s ) {
		return 0;
	}
	if ( i <= s && e <= j ) {
		return tree[node];
	}
	return sum(node * 2, s, ( s + e ) / 2, i, j) + 
			sum(node * 2 + 1, ( s + e ) / 2 + 1, e, i, j);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	m += k;
	a.resize(1000000+1);
	tree.resize(1048576*2+1);
	for ( int i = 0; i < n; i++ )
	{
		cin >> a[i];
	}
	init(1, 0, n - 1);
	while ( m-- )
	{
		int t1, t2;
		long long t3;
		cin >> t1;
		if ( t1 == 1 ) {
			cin >> t2 >> t3;
			t2 -= 1;
			long long diff = t3 - a[t2];
			a[t2] = t3;
			update(1, 0, n - 1, t2, diff);
		}
		else if ( t1 == 2 ) {
			cin >> t2 >> t3;
			cout << sum(1, 0, n - 1, t2 - 1, t3 - 1) << '\n';
		}
	}
	return 0;
}