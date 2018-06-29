#include <cstdio>
int arr[10001];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for ( int i = 0; i < n; i++ ) scanf("%d", &arr[i]);
	int cnt = 0;
	for ( int i = 0; i < n; i++ )
	{
		int sum = 0;
		for ( int j = i; j < n; j++ )
		{
			sum += arr[j];
			if ( sum == m ) {
				cnt++;
				break;
			}
			else if ( sum > m ) {
				break;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}