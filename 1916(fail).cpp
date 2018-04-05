// BOJ 1916 최소비용 구하기
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <string>
using namespace std;
const int INF = 100000;
int n, m;
int startP, endP, weight;
vector<pair<int, int>> vec[1001];
int dist[1001];
priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

int main()
{	
	scanf("%d", &n);
	scanf("%d", &m);
	for ( int i = 0; i < m; i++ )
	{
		scanf("%d %d %d", &startP, &endP, &weight);
		vec[startP].push_back({ weight,endP });
	}
	scanf("%d %d", &startP, &endP);
	
	for ( int i = 1; i <= n; i++ )
	{
		dist[i] = INF;
	}
	pq.push({ 0,startP });
	dist[startP] = 0;

	while ( !pq.empty() )
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if ( dist[here] < cost ) continue;

		for ( int i = 0; i < vec[here].size(); i++ )
		{
			int there = vec[here][i].second;
			int t_cost = vec[here][i].first;
			if ( dist[here] != INF && dist[there] > dist[here] + t_cost )
			{
				dist[there] = dist[here] + t_cost;
				pq.push({ there,dist[there] });
			}
		}
	}
	printf("%d\n", dist[endP]);
	return 0;
}