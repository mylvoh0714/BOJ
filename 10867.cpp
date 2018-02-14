// 10867 중복 빼고 정렬하기
#include <iostream>
#include <vector> // 사실 set을 쓰면 한방에끝...
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