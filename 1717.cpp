// BOJ 1717 집합의 표현
#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int n, m, a, b, c;

int find_root(int num)
{
	if ( arr[num] == num )
		return num;
	else
	{
		arr[num] = find_root(arr[num]); // <<< 핵심부분
		return arr[num];
	}
		
}

void merge(int num1, int num2)
{
	arr[find_root(num1)] = find_root(num2);
}

int main()
{
	scanf("%d %d", &n, &m);
	arr.resize(n+1);
	for ( int i = 0; i <= n; i++ )
	{
		arr[i] = i;
	}

	while ( m-- )
	{
		scanf("%d %d %d", &a, &b, &c);
		if ( a == 0 )
		{
			merge(b, c);
		}
		else if ( a == 1 )
		{
			if ( find_root(b) == find_root(c) )
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}