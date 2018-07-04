#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int cnt[26];

int main()
{
	while ( 1 )
	{
		string str = "";
		getline(cin, str);
		if ( str == "*" )
			break;
		for ( int i = 0; i < str.size(); i++ )
		{
			int idx = str[i] - 'a';
			if ( idx < 0 || idx >= 26 )
				continue;
			cnt[idx] += 1;
		}

		for ( int i = 0; i < 26; i++ )
		{
			if ( cnt[i] == 0 ) {
				cout << "N" << '\n';
				break;
			}
			if ( i == 25 ) {
				cout << "Y" << '\n';
			}
		}

		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}