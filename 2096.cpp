//BOJ_2096 내려가기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[4]; 
int prevMaxdp[4], nextMaxdp[4];								
int prevMindp[4], nextMindp[4];
int n, MaxResult, MinResult;

int main()
{
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%d %d %d", &arr[1], &arr[2], &arr[3]);
		nextMaxdp[1] = max(prevMaxdp[1], prevMaxdp[2]) + arr[1];
		nextMaxdp[2] = max(prevMaxdp[1], max(prevMaxdp[2], prevMaxdp[3])) + arr[2];
		nextMaxdp[3] = max(prevMaxdp[2], prevMaxdp[3]) + arr[3];
		nextMindp[1] = min(prevMindp[1], prevMindp[2]) + arr[1];
		nextMindp[2] = min(prevMindp[1], min(prevMindp[2], prevMindp[3])) + arr[2];
		nextMindp[3] = min(prevMindp[2], prevMindp[3]) + arr[3];
		for ( int j = 1; j <= 3; j++ ) prevMaxdp[j] = nextMaxdp[j];
		for ( int j = 1; j <= 3; j++ ) prevMindp[j] = nextMindp[j];
	}
	MaxResult = max(prevMaxdp[1], max(prevMaxdp[2], prevMaxdp[3]));
	MinResult = min(prevMindp[1], min(prevMindp[2], prevMindp[3]));
	printf("%d %d", MaxResult, MinResult);
	return 0;
}