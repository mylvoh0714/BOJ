// BOJ 10828_Stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> st;

int main()
{
	int N, num;
	scanf("%d", &N);
	while ( N-- )
	{
		string str;
		cin >> str;
		if ( str == "push" )
		{
			scanf("%d", &num);
			st.push(num);
		}
		else if ( str == "pop" )
		{
			if ( !st.empty() )
			{
				printf("%d\n", st.top());
				st.pop();
			}
			else
				printf("%d\n", -1);
		}
		else if ( str == "size" )
		{
			printf("%d\n", st.size());
		}
		else if ( str == "empty" )
		{
			printf("%d\n", st.empty());
		}
		else if ( str == "top" )
		{
			if ( !st.empty() )
			{
				printf("%d\n", st.top());
			}
			else
				printf("%d\n", -1);
		}
	}
}