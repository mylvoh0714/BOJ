//1158 Josephus problem
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int N, M;

int main()
{
	scanf("%d %d", &N, &M);
	for ( int i = 1; i <= N; i++ )
	{
		q.push(i);
	}
	cout << "<";
	while ( !q.empty() )
	{
		for ( int i = 0; i < M - 1; i++ ) // M-1번만큼 오른쪽으로이동
		{
			q.push(q.front());
			q.pop();
		}
		if ( q.size()>1 )
			cout << q.front() << ", ";
		else
			cout << q.front();
		q.pop();
	}
	cout << ">";
	return 0;
}