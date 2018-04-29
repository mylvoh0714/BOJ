#include <iostream>
#include <string>
using namespace std;
int res;

int main()
{
	string str;
	int n, flag;
	n = flag = 0;
	cin >> str;

	for ( int i = 0; i < str.size(); i++ )
	{
		// number
		if ( '0' <= str[i] && str[i] <= '9' )
		{
			n *= 10;
			n += str[i] - '0';
		}
		// '+' or '-'
		else
		{
			if ( flag == 0 ) res += n;
			else res -= n;
			
			n = 0;
			if ( str[i] == '-' )
				flag = 1;
		}
	}

	// last number
	if ( flag == 0 ) res += n;
	else res -= n;

	cout << res << "\n";
}