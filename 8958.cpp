#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while ( n-- )
	{
		string str;
		cin >> str;
		int score = 0;
		int result = 0;
		for ( int i = 0; i < str.size(); i++ )
		{
			if ( str[i] == 'O' )
			{
				score++;
				result += score;
			}
			else if ( str[i] == 'X' )
			{
				score = 0;
			}
		}
		cout << result << '\n';
	}
	return 0;
}