#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, cost, num_pre;
int num_pre_task[10001]; // num_pre_task[k] is number of pre-task in order to do k-th task
int cost_arr[10001];
int dist[10001];
int result;

int main()
{
	scanf("%d", &n);
	vector<int> vec[10001];
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d %d", &cost, &num_pre);
		cost_arr[i] = cost;
		for ( int j = 0; j < num_pre; j++ )
		{
			int pre_task;
			scanf("%d", &pre_task);
			vec[pre_task].push_back(i);
			num_pre_task[i]++;
		}
	}

	// algorithm
	queue<int> q;
	for ( int i = 1; i <= n; i++ )
	{
		if ( num_pre_task[i] == 0 )
		{
			q.push(i);
			dist[i] = cost_arr[i];
		}
	}
	for ( int i = 0; i < n; i++ )
	{
		int here = q.front();
		q.pop();
		for ( int j = 0; j < vec[here].size(); j++ )
		{
			int there = vec[here][j];
			num_pre_task[there]--;
			if ( dist[there] < dist[here] + cost_arr[there] )
				dist[there] = dist[here] + cost_arr[there];
			if ( num_pre_task[there] == 0 )
				q.push(there);
		}
	}

	for ( int i = 1; i <= n; i++ )
	{
		if ( result < dist[i] ) result = dist[i];
	}
	
	printf("%d\n", result);
	return 0;
}

