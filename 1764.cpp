// 1764_µË∫∏¿‚
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
map<string, int> strmap;
vector<string> vec;

int main()
{
	int N1,N2;
	int count = 0;
	string str;
	scanf("%d %d", &N1, &N2);
	while ( N1-- ) // no hear
	{
		cin >> str;
		strmap[str]++;
	}
	while ( N2-- ) // no see
	{
		cin >> str;
		strmap[str]++;
	}
	for ( auto itr = strmap.begin(); itr != strmap.end(); itr++ )
	{
		if ( itr->second == 2 )
		{
			count++;
			vec.push_back(itr->first);
		}
	}
	printf("%d\n", count);
	for ( auto itr = vec.begin(); itr != vec.end(); itr++ )
		cout << *itr << "\n";
}