// 10823 ´õÇÏ±â2
#include <iostream>
#include <string>
using namespace std;
string str, num = "";
int i = 0, sum = 0;
int main()
{
	while ( getline(cin, str) )
	{
		if ( str[i] == ',' )
		{
			sum += stoi(num);
			num = "";
		}
		else
		{
			num += str[i];
		}
	}
	sum += stoi(num);
	printf("%d", sum);
}
