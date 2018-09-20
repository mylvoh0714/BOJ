#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
int arr[100004];
int ans[100004];

int main()
{
		
	int n; scanf("%d", &n);
	for ( int i = 0; i < n; i++ ) scanf("%d", arr + i);
	int k; scanf("%d", &k);

	int max_v = 0;
	deque<pair<int, int>> dq;

	for ( int i = 0; i < k; i++ )
	{
		int up, down;
		scanf("%d %d", &up, &down);
		while ( !dq.empty() && dq.back().first <= up ) dq.pop_back();

		if ( max_v <= up ) max_v = up;

		dq.push_back({ up,1 }); // {value, up} = {value,1} <--> {value,down} = {value,2} 


		while ( !dq.empty() && dq.back().first <= down ) dq.pop_back();

		if ( max_v <= down ) max_v = down;

		dq.push_back({ down,2 });
	}

	sort(arr, arr + max_v);
	
	// for answer arr
	for ( int i = max_v; i < n; i++ ) ans[i] = arr[i];
	
	int itr1 = 0;
	int itr2 = --max_v;
	while ( !dq.empty() )
	{
		int val = dq.front().first;
		int type = dq.front().second;
		dq.pop_front();
		int cnt = val;
		if(!dq.empty()) cnt -= dq.front().first;

		if ( type == 1 ) {
			for ( int i = 0; i < cnt; i++ ) ans[max_v--] = arr[itr2--];
		}
		else {
			for ( int i = 0; i < cnt; i++ ) ans[max_v--] = arr[itr1++];
		}
	}
	for ( int i = 0; i < n; i++ ) printf("%d ", ans[i]);
}