// BOJ 1325 효율적인 해킹
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int Start, End;
vector<int> arr[10001];
int visited[10001];
int ans[10001];

int bfs(int start)
{
	int ret = 0;
	queue<int> q;
	q.push(start);
	while ( !q.empty() )
	{
		int here = q.front();
		q.pop();
		if ( visited[here] ) continue;
		visited[here] = 1;
		ret++;
		for ( auto i = 0; i < arr[here].size(); i++ )
		{
			int there = arr[here][i];
			if ( !visited[there] ) {
				q.push(there);
			}
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);
	for ( int i = 0; i<m; i++ )
	{
		scanf("%d %d", &End, &Start);
		arr[Start].push_back(End);
	}
	int mx = 0;
	for ( int i = 1; i <= n; i++ )
	{
		memset(visited, 0, sizeof(visited));
		ans[i] = bfs(i);
		if ( ans[i] > mx ) {
			mx = ans[i];
		}
	}
	for ( int i = 1; i <= n; i++ )
	{
		if ( ans[i] == mx )
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}