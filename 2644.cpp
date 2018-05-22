#include <iostream>
#include <queue>
using namespace std;
int n, k;
int src, des;
bool adjMat[101][101];
int visited[101];
int result;

queue<int> q;
void bfs(int u)
{
	q.push(u);
	visited[u] = 1;
	while ( !q.empty() )
	{
		int here = q.front();
		q.pop();
		for ( int there = 1; there <= n; there++ )
		{
			if ( !visited[there] && adjMat[here][there] )
			{
				q.push(there);
				visited[there] = visited[here] + 1;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> src >> des;
	cin >> k;
	
	int a, b;
	for ( int i = 0; i < k; i++ )
	{
		cin >> a >> b;
		adjMat[a][b] = true;
		adjMat[b][a] = true;
	}
	// ------위에까지 입력부분---------
	bfs(src);
	cout << visited[des] - 1;
	return 0;
	
}