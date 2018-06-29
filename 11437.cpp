#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visited[50001];
int depth[50001];
int parent[50001];

int LCA(int lowlevel, int highlevel)
{
	// setting for highlevel = (more depth level)
	if ( depth[lowlevel] > depth[highlevel] ) {
		int temp = highlevel;
		highlevel = lowlevel;
		lowlevel = temp;
	}

	while ( depth[lowlevel] != depth[highlevel] )
	{
		highlevel = parent[highlevel];
	}

	while ( lowlevel != highlevel )
	{
		lowlevel = parent[lowlevel];
		highlevel = parent[highlevel];
	}

	return highlevel;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for ( int i = 0; i < n - 1; i++ )
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q;
	parent[1] = 0;
	depth[1] = 0;
	visited[1] = true;
	q.push(1);

	while ( !q.empty() )
	{
		int here = q.front();
		q.pop();
		for ( int i = 0; i < adj[here].size(); i++ )
		{
			int there = adj[here][i];
			if ( !visited[there] ) {
				parent[there] = here;
				depth[there] = depth[here] + 1;
				visited[there] = true;
				q.push(there);
			}
		}
	}
	int m;
	cin >> m;
	for ( int i = 0; i < m; i++ )
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}