#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> vec[32001];
queue<int> q;
int indegree[32001]; // array that stores topological info
int n, m;
int a, b;

int main()
{
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < m; i++ )
	{
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		indegree[b]++;
	}
	for ( int i = 1; i <= n; i++ )
	{
		if ( indegree[i] == 0 ) q.push(i);
	}

	for ( int i = 0; i < n; i++ )
	{
		int here = q.front();
		q.pop();
		printf("%d ", here);
		for ( int j = 0; j < vec[here].size(); j++ )
		{
			int there = vec[here][j];
			indegree[there]--;
			if ( indegree[there] == 0 ) q.push(there);
		}
	}
	printf("\n");
	return 0;
}