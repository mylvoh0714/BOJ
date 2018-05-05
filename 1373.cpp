#include <cstdio>
char arr[1000006] = { '0','0' }; // to make multiples of 3

int main()
{
	int i = 0;
	int j = 0;
	scanf("%s", arr + 2);
	while ( arr[i] ) arr[i++] -= '0';
	for ( j = i % 3; j < i; j += 3 ) printf("%d", arr[j] * 4 + arr[j + 1] * 2 + arr[j + 2]);
	return 0;
}