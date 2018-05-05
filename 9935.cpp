// BOJ 9935 문자열 폭발
#include <iostream>
#include <string>

using namespace std;

void ReplaceString(string& str, const string& search, const string& replace)
{
	size_t pos = 0;
	while ( ( pos = str.find(search, pos) ) != string::npos )
	{
		str.replace(pos, search.length(), replace);
		pos += replace.length();
	}
}

int main()
{
	string str;
	string del_Str;
	cin >> str;
	cin >> del_Str;
	

	int idx = str.find(del_Str);
	//str.replace(str,)
	
	
}