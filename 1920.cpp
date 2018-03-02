// BOJ_1920 ¼ö Ã£±â
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100002];
int N, M;

int Bsearch(int target)
{
	int left = 1, right = N;
	while ( left <= right )
	{
		int mid = ( left + right ) / 2;
		if ( arr[mid] == target )
			return 1;
		else if ( arr[mid] < target )
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}

int main()
{
	scanf("%d", &N);
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d",&arr[i]);
	}
	sort(arr + 1, arr + N + 1);
	
	scanf("%d", &M);
	while ( M-- )
	{
		int target;
		scanf("%d", &target);
		printf("%d\n", Bsearch(target));
	}
}