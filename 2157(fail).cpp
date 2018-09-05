// BOJ 2157 여행
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int d[301][301]; // d[n][m] : n번까지 m번 도시를 거쳐서 먹을수있는 기내식의 최대값.

struct fly {
	int src;
	int des;
	int food;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<fly> arr(k);
	for ( int i = 0; i < k; i++ )
	{
		int src, des, food;
		cin >> src >> des >> food;
		arr[i].src = src;
		arr[i].des = des;
		arr[i].food = food;
	}
	memset(d, -1, sizeof(d));
	d[1][1] = 0;
	//--- end input

	for ( int c = 2; c <= m; c++ )
	{
		for ( int i = 0; i < k; i++ )
		{
			int src, des, food;
			src = arr[i].src;
			des = arr[i].des;
			food = arr[i].food;
			if ( src > des ) continue;
			if(d[des][c] < d[src][c-1] + food)
				d[des][c] = d[src][c-1] + food;
		}
	}
	int ans = 0;
	for ( int i = 1; i <= m; i++ )
	{
		ans = max(ans, d[n][i]);
	}
	cout << ans << '\n';
}