// 10824 ³× ¼ö
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;
	string str12 = str1 + str2;
	string str34 = str3 + str4;
	long long sum = stoll(str12) + stoll(str34);
	printf("%lld", sum);
	
}