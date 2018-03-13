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
int temp, result;
queue<int> idx;

int bfs(int start)
{
	int ret = 1;
	queue<int> q;
	visited[start] = 1;
	q.push(start);
	while ( !q.empty() )
	{
		int here = q.front();
		q.pop();
		for ( auto i = 0; i < arr[here].size(); i++ )
		{
			int there = arr[here][i];
			if ( !visited[there] )
			{
				ret++;
				visited[there] = 1;
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
	for ( int i = 1; i <= n; i++ )
	{
		memset(visited, 0, sizeof(visited));
		temp = bfs(i);
		if ( result < temp )
		{
			result = temp;
			if ( !idx.empty() ) idx.pop();
			idx.push(i);
		}
		else if ( result == temp ) idx.push(i);
		//cout << "i : " << i << "일때의 bfs의 값 : " << result << endl;
	}
	while ( !idx.empty() )
	{
		printf("%d ", idx.front());
		idx.pop();
	} 
	return 0;
}