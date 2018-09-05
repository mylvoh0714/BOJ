#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int visited[1001];
int dist[1001];
const int INF = 1024 * 1024 * 1024;
int main()
{
	int n; cin >> n;
	int m; cin >> m;
	vector<pair<int,int>> adj[1001];
	for ( int i = 0; i < m; i++ )
	{
		int src, des, cost;
		cin >> src >> des >> cost;
		adj[src].push_back({ cost,des });
	}
	for ( int i = 1; i <= 1000; i++ )
	{
		dist[i] = INF;
	}
	int s, e;
	cin >> s >> e;
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
	pq.push({ 0,s });
	dist[s] = 0;
	while ( !pq.empty() )
	{
		int here = pq.top().second;
		pq.pop();
		if ( visited[here] ) continue;
		visited[here] = 1;
		for ( int i = 0; i < adj[here].size(); i++ )
		{
			int there = adj[here][i].second;
			int there_c = adj[here][i].first;
			if ( dist[there] > dist[here] + there_c ) {
				dist[there] = dist[here] + there_c;
				pq.push({ -dist[there],there });
			}
		}
	}
	cout << dist[e] << '\n';
}