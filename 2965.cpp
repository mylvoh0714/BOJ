// BOJ_2965 캥거루 세마리
#include <iostream>
using namespace std;
int A, B, C;

int main()
{
	scanf("%d %d %d", &A, &B, &C);
	int result = B - A > C - B ? B - A : C - B;
	printf("%d", result - 1);
	return 0;
}