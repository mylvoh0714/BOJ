// BOJ 2594 ³îÀÌ°ø¿ø
#include <iostream>
#include <vector>
using namespace std;
int n, start, end;

typedef struct rideTime
{
	int start_time;
	int end_time;

	rideTime(const int start, const int end)
		: start_time(start), end_time(end) { }

}RideTime;

bool operator<(RideTime A, RideTime B)
{
	return A.start_time < B.start_time;
}

int main()
{
	scanf("%d", &n);
	vector<RideTime> vec;
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d %d", &start, &end);
	}
}
