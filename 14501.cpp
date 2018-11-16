#include <iostream>
#include <algorithm>
using namespace std;
int cost[16];;
int profit[16];
int n;
int ans;
void go(int day, int sum)
{
	if ( day == n + 1 ) {
		ans = max(ans, sum);
		return;
	}
	
	go(day + 1, sum);
	if ( day + cost[day]-1 <= n ) go(day + cost[day], sum + profit[day]);
}

int main()
{
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) {
		scanf("%d %d", &cost[i], &profit[i]);
	}
	go(1, 0);
	cout << ans << endl;
}