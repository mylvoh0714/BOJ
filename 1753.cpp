// BOJ 1753 최단경로
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int INF = 10000;
int n, m;
int start;
int u, v, weight;
int dist[20001]; // start로부터 distance
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{

	scanf("%d %d", &n, &m);
	scanf("%d", &start);
	vector<pair<int, int>> vec[20001]; // (weight,destination) pair
	for ( int i = 0; i < m; i++ )
	{
		scanf("%d %d %d", &u, &v, &weight);
		vec[u].push_back({ weight,v });
	}
	for ( int i = 1; i <= n; i++ )
	{
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ 0,start });

	while ( !pq.empty() )
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for ( int i = 0; i < vec[here].size(); i++ )
		{
			int there = vec[here][i].second;
			int there_cost = vec[here][i].first;
			if ( dist[there] > dist[here] + there_cost )
			{
				dist[there] = dist[here] + there_cost;
				pq.push({ there_cost,there });
			}
		}
	}
	for ( int i = 1; i <= n; i++ )
	{
		if ( dist[i] == INF ) puts("INF");
		else printf("%d\n", dist[i]);
	}
}