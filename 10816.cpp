// 10816_숫자카드2
#include <iostream>
#include <map>	
#include <algorithm>
using namespace std;
map<int, int> mp;

int main()
{
	int N1, N2, num;
	scanf("%d", &N1);
	while ( N1-- )
	{
		scanf("%d", &num);
		mp[num]++;
	}

	scanf("%d", &N2);
	while ( N2-- )
	{
		scanf("%d", &num);
		printf("%d ", mp[num]);
	}
	return 0;
}