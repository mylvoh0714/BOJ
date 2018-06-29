#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str1, str2;
	string oper;
	cin >> str1;
	cin >> oper;
	cin >> str2;

	string ret = "";
	int size1 = str1.size();
	int size2 = str2.size();
	if ( oper == "*" ) {
		ret = "1";
		for ( int i = 1; i <= size1 + size2 - 2; i++ )
		{
			ret += "0";
		}
	}
	else if ( oper == "+") {
		if ( size1 == size2 ) {
			ret = "2";
			for ( int i = 1; i <= size1 - 1; i++ )
			{
				ret += "0";
			}
		}
		else if ( size1 > size2 ) {
			ret = "1";
			for ( int i = 1; i <= size1 - 1; i++ )
			{
				ret += "0";
			}

			ret.replace(size1 - size2, 1, "1");
		}
		else {
			ret = "1";
			for ( int i = 1; i <= size2 - 1; i++ )
			{
				ret += "0";
			}
			ret.replace(size2 - size1, 1, "1");
		}
	}
	cout << ret << '\n';

	return 0;
}