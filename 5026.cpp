#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> str;
		if ( str == "P=NP" )
			cout << "skipped" << '\n';
		else {
			string a, b;
			int i;
			for ( i = 0; str[i] != '+'; i++ );
			a = str.substr(0, i);
			b = str.substr(i + 1, str.size() - a.size());
			cout << stoi(a) + stoi(b) << '\n';
		}
	}
}