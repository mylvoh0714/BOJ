// BOJ_2346 풍선 터뜨리기
#include <iostream>
#include <list>
using namespace std;

int main()
{
	int N, num;
	list<pair<int, int>> lst;
	scanf("%d", &N);
	for ( int i = 1; i <= N; i++ )
	{
		scanf("%d", &num);
		lst.push_back(make_pair(i, num));
	}
	std::list<pair<int, int>>::iterator itr = lst.begin();
	while ( !lst.empty() )
	{
		int temp = itr->second; // 이동하는 거리
		cout << itr->first << ' '; // 위치(i번째)
		itr = lst.erase(itr);
		if ( lst.empty() )
			break;

		if ( itr == lst.end() )
		{
			itr = lst.begin();
		}

		if ( temp == 1 ) // 이경우는 굳이 반복자 작업을 해줄필요없음.(erase return값 참고)
		{
			if ( itr == lst.end() )
			{
				itr = lst.begin();
			}
		}
		else if ( temp > 0 ) // 오른쪽으로 이동
		{
			for ( int i = 0; i < temp - 1; i++ )
			{
				itr++;
				if ( itr == lst.end() )
				{
					itr = lst.begin();
				}
			}
		}
		else // temp < 0 , 왼쪽으로 이동
		{
			for ( int i = 0; i < -temp; i++ )
			{
				if ( itr == lst.begin() )
				{
					itr = lst.end();
					itr--;
				}
				else
					itr--;
			}
		}
	}
}