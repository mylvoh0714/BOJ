#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	while ( 1 )
	{
		int n;
		scanf("%d", &n);
		if ( n == 0 ) break;
		vector<int> arr(n);
		for ( int i = 0; i < n; i++ )
		{
			scanf("%d", &arr[i]);
		}
	}
}