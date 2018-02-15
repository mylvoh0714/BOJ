//10815_숫자 카드
#include <iostream>
#include <set>	
using namespace std;

int main()
{
	int N1,N2,num1,num2;
	set<int> set;
	scanf("%d", &N1);
	while ( N1-- )
	{
		scanf("%d", &num1);
		set.insert(num1);
	}
	
	scanf("%d", &N2);
	while ( N2-- )
	{
		scanf("%d", &num2);
		auto itr = set.find(num2);
		if ( itr != set.end() )
			cout << 1 << ' ';
		else
			cout << 0 << ' ';
	}
}