// 1076 _ ÀúÇ×
#include <iostream>
#include <cmath>
#include <string>
#include <map>		
using namespace std;
string color[] = { "black","brown","red","orange",
"yellow","green","blue","violet","grey","white" };

map<string, long long> colormap;

int main()
{
	for ( int i = 0; i <= 9; i++ )
	{
		colormap[color[i]] = i;
	}

	long long arr[10];
	arr[0] = 1;
	for ( int i = 1; i <= 9; i++ )
	{
		arr[i] = arr[i - 1] * 10;
	}
	string a, b, c;
	cin >> a >> b >> c;

	cout << ( 10 * colormap[a] + colormap[b] )*arr[colormap[c]];
	
};
	
