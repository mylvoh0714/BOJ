#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int max_team = 0;
	while ( N >= 2 && M >= 1 && N + M >= K + 3 )
	{
		max_team += 1;
		N -= 2;
		M -= 1;
	}
	printf("%d\n", max_team);
	return 0;
}