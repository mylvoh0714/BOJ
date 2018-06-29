#include <iostream>
#include <string>
using namespace std;
int numarr[10];
int main()
{
	string str;
	cin >> str;
	for ( int i = 0; i < str.size(); i++ )
	{
		int index = str[i] - '0';
		numarr[index]++;
	}
	numarr[6] += numarr[9];
	numarr[9] = 0;
	numarr[6] = ( numarr[6] + 1 ) / 2;
	
	int ret = 0;
	for ( int i = 0; i <= 9; i++ )
	{
		if ( ret < numarr[i] )
			ret = numarr[i];
	}
	cout << ret << '\n';

	return 0;
}