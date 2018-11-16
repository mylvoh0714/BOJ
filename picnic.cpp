#include <iostream>
#include <cstring>
using namespace std;
int adj[11][11];
bool taken[11];
int t, n, m;

int countPairings(bool taken[10]) {
	int firstFree = -1;

	for ( int i = 0; i < n; ++i ) {
		if ( !taken[i] ) {
			firstFree = i;
			break;
		}
	}
	// base case
	if ( firstFree == -1 ) return 1;
	int ret = 0;

	for ( int pairWith = firstFree + 1; pairWith < n; ++pairWith ) {
		if ( !taken[pairWith] && adj[firstFree][pairWith] ) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	for ( int testcase = 0; testcase < t; testcase++ )
	{
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));
		memset(taken, false, sizeof(taken));
		for ( int i = 0; i < m; i++ )
		{
			int a, b;
			cin >> a >> b;
			adj[a][b] = adj[b][a] = 1;
		}
		cout << countPairings(taken) << '\n';

	}
}