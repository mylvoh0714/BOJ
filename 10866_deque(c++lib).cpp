//10866 deque(µ¦)
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	string str;
	int N, num;
	deque<int> dq;
	scanf("%d", &N);
	for ( int i = 0; i < N; i++ )
	{
		cin >> str;
		if ( str == "push_back" )
		{
			scanf("%d", &num);
			dq.push_back(num);
		}
		else if ( str == "push_front" )
		{
			scanf("%d", &num);
			dq.push_front(num);
		}
		else if ( str == "pop_front" )
		{
			cout << ( dq.empty() ? -1 : dq.front() ) << endl;
			if ( !dq.empty() )
				dq.pop_front();
		}
		else if ( str == "pop_back" )
		{
			cout << ( dq.empty() ? -1 : dq.back() ) << endl;
			if ( !dq.empty() )
				dq.pop_back();
		}
		else if ( str == "size" )
			cout << dq.size() << endl;
		else if ( str == "empty" )
			cout << dq.empty() << endl;
		else if ( str == "front" )
			cout << ( dq.empty() ? -1 : dq.front() ) << endl;
		else if ( str == "back" )
			cout << ( dq.empty() ? -1 : dq.back() ) << endl;
	}
}
