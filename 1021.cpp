// BOJ 1021 회전하는 큐
#include <iostream>
#include <deque>
using namespace std;
int N, M;
int input;

int main()
{
	int result = 0;
	scanf("%d %d", &N, &M); // N은 총 개수, M은 뽑을 개수
	deque<int> dq;
	for ( int i = 1; i <= N; i++ )
	{
		dq.push_back(i);
	}
	for ( int i = 1; i <= M; i++ )
	{
		scanf("%d", &input);
		int index = 1; // deque에서 탐색을 위한 index
		for ( auto itr = dq.begin(); itr != dq.end(); itr++ )
		{
			if ( *itr == input ) break;
			index++;
		}
		int right = index - 1;
		int left = N - index + 1;
		if ( left < right ) // 왼쪽으로이동, 즉 123456이 612345로.
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
		else // 오른쪽으로 이동
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