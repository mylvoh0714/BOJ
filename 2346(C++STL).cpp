// BOJ_2346 ǳ�� �Ͷ߸���
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
		int temp = itr->second; // �̵��ϴ� �Ÿ�
		cout << itr->first << ' '; // ��ġ(i��°)
		itr = lst.erase(itr);
		if ( lst.empty() )
			break;

		if ( itr == lst.end() )
		{
			itr = lst.begin();
		}

		if ( temp == 1 ) // �̰��� ���� �ݺ��� �۾��� �����ʿ����.(erase return�� ����)
		{
			if ( itr == lst.end() )
			{
				itr = lst.begin();
			}
		}
		else if ( temp > 0 ) // ���������� �̵�
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
		else // temp < 0 , �������� �̵�
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