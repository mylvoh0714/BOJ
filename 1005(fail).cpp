// BOJ_1005 ACM Craft
#include <iostream>
using namespace std;
int N, K;
int cost[1001], d[1001];

int main()
{
	scanf("%d %d", &N, &K); // N�� �ǹ��Ǽ�, K�� ��Ģ�Ǽ�
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &cost[i]); // cost[2]�� 2���ǹ��� ���µ� �ҿ�Ǵ� �ð�
	}
	for ( int i = 1; i <= N; i++ )
	{
		d[i] = d[i - 1] + cost[i];
	}
}