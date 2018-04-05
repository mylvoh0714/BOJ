// BOJ 11779 최소비용구하기2
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
long long INF = 10000000000;
int visited[1001];
long long dist[1001];
int find_parent[1001];
vector< pair<int, int> > vec[1001];
stack< pair<int,int> > st;
priority_queue<pair<int, int>> pq;
int n, m;
int start, des, cost;
int num;

int main()
{
	
	scanf("%d", &n);
	scanf("%d", &m);
	for ( int i = 0; i < m; i++ )
	{
		scanf("%d %d %d", &start, &des, &cost);
		vec[start].push_back({ cost,des });
	}
	scanf("%d %d", &start, &des);

	for ( int i = 1; i <= n; i++ ) // set dist[] = INF
	{
		dist[i] = INF;
	}

	dist[start] = 0;
	pq.push({ 0,start });
	find_parent[start] = 0;

	while ( !pq.empty() )
	{
		int here = pq.top().second;
		pq.pop();
		if ( visited[here] ) 
			continue;
		visited[here] = 1;
		
		for ( int i = 0; i < vec[here].size(); i++ )
		{
			int there = vec[here][i].second;
			if ( dist[there] > dist[here] + vec[here][i].first )
			{
				dist[there] = dist[here] + vec[here][i].first;
				pq.push({ -dist[there],there });
				find_parent[there] = here;
			}
		}
	}

	stack<int> st;
	int pos = des;
	while ( pos != 0 )
	{
		st.push(pos);
		pos = find_parent[pos];
	}

	printf("%lld\n", dist[des]);
	printf("%d\n", st.size());
	while ( !st.empty() )
	{
		printf("%d ", st.top());
		st.pop();
	}
	printf("\n");
	return 0;
}
