// 10867 �ߺ� ���� �����ϱ�
#include <iostream>
#include <vector> // ��� set�� ���� �ѹ濡��...
#include <algorithm>
using namespace std;

int main()
{
	int N, num;
	scanf("%d", &N);
	vector<int> vec;
	vec.reserve(N);
	for ( int i = 0; i<N; i++ )
	{
		scanf("%d", &num);
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	
	auto itr = vec.begin();
	while ( itr != vec.end() - 1 )
	{
		if ( *itr == *( itr + 1 ) )
		{
			itr = vec.erase(itr);
		}
		else
			itr++;
	}
	for ( auto itr = vec.begin(); itr != vec.end(); itr++ )
	{
		cout << *itr << " ";
	}
}