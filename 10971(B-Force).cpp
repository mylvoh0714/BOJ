// BOJ 10971 외판원순회2
// Version1 : Brute Force
// Version2 : Dynamic(planning..)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cost[11][11];
int visited[11];
int ans = 987654321;
int n;

void dfs(int i, int dist, int cnt) {
	if ( i == 1 && cnt == n + 1 ) {
		ans = min(ans, dist);
		return;
	}

	for ( int j = 1; j <= n; j++ )
	{
		if ( cost[i][j] && !visited[j] ) {
			visited[j] = 1;
			dfs(j, dist + cost[i][j], cnt + 1);
			visited[j] = 0;
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for ( int i = 1; i <= n; i++ ) 
	{
		for ( int j = 1; j <= n; j++ ) {
			cin >> cost[i][j];
		}
	}
	dfs(1, 0, 1);
	cout << ans << '\n';
}