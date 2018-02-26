// BOJ_1005 ACM Craft
#include <iostream>
using namespace std;
int N, K;
int cost[1001], d[1001];

int main()
{
	scanf("%d %d", &N, &K); // N은 건물의수, K는 규칙의수
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &cost[i]); // cost[2]는 2번건물을 짓는데 소요되는 시간
	}
	for ( int i = 1; i <= N; i++ )
	{
		d[i] = d[i - 1] + cost[i];
	}
}