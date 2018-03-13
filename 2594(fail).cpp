// BOJ 2594 놀이공원
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[721]; // arr[i] is "after i minute from 10:00"
int n, start_t, end_t;
int cnt,result;

int ClockIdx_To_ArrIdx(int num) // 17:50분이면 7시간 50분경과한거이므로
{
	int temp = ( num - 1000 ) / 100 * 60 + ( num - 1000 ) % 100;
	return temp;
}

int main()
{
	scanf("%d", &n);
	while ( n-- )
	{
		scanf("%d %d", &start_t, &end_t);
		start_t = ClockIdx_To_ArrIdx(start_t) >= 10 ?
				ClockIdx_To_ArrIdx(start_t) - 10 : ClockIdx_To_ArrIdx(start_t);
		end_t = ClockIdx_To_ArrIdx(end_t) <= 710 ?
				ClockIdx_To_ArrIdx(end_t) + 10 : ClockIdx_To_ArrIdx(end_t);

		for ( int i = start_t; i < end_t; i++ )
		{
			if ( arr[i] == 1 ) continue;
			arr[i] = 1;
		}
	}
		
	for ( int i = 0; i < 720; i++ )
	{
		if ( arr[i] == 0 ) cnt++;
		else
		{
			result = max(result, cnt);
			cnt = 0;
		}
	}	
	printf("%d\n", result);
}