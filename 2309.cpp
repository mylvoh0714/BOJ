// BOJ 2309 ÀÏ°ö³­ÀïÀÌ
#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
int sum;


int main()
{
	for ( int i = 0; i < 9; i++ )
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sort(arr, arr + 9);
	sum -= 100;
	for ( int i = 0; i < 9; i++ )
	{
		for ( int j = i + 1; j < 9; j++ )
		{
			if ( arr[i] + arr[j] == sum )
			{
				for ( int k = 0; k < 9; k++ )
				{
					if ( k == i || k == j )
						continue;
					printf("%d\n", arr[k]);
				}
			}
		}
	}
}