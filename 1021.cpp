// BOJ 1021 ȸ���ϴ� ť
#include <iostream>
#include <deque>
using namespace std;
int N, M;
int input;

int main()
{
	int result = 0;
	scanf("%d %d", &N, &M); // N�� �� ����, M�� ���� ����
	deque<int> dq;
	for ( int i = 1; i <= N; i++ )
	{
		dq.push_back(i);
	}
	for ( int i = 1; i <= M; i++ )
	{
		scanf("%d", &input);
		int index = 1; // deque���� Ž���� ���� index
		for ( auto itr = dq.begin(); itr != dq.end(); itr++ )
		{
			if ( *itr == input ) break;
			index++;
		}
		int right = index - 1;
		int left = N - index + 1;
		if ( left < right ) // ���������̵�, �� 123456�� 612345��.
		{
			while ( dq.front() != input )
			{
				dq.push_front(dq.back());
				dq.pop_back();
				result++;
			}
			dq.pop_front();
			N--;
		}
		else // ���������� �̵�
		{
			while ( dq.front() != input )
			{
				dq.push_back(dq.front());
				dq.pop_front();
				result++;
			}
			dq.pop_front();
			N--;
		}
	}
	printf("%d\n", result);
	
}