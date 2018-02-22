// BOJ 10820 문자열 분석
#include <iostream>
#include <string>
using namespace std;
string input;

int main()
{
	while (getline(cin,input) )
	{
		int uppercase = 0, lowercase = 0 , number= 0, blank= 0;
		for ( int i = 0; i < input.size(); i++ )
		{
			//printf("%d ", input[i]);
			if ( input[i] >= 'A' && input[i] <= 'Z' )
				uppercase++;
			else if ( input[i] >= 'a' && input[i] <= 'z' )
				lowercase++;
			else if ( input[i] >= '0' && input[i] <= '9' )
				number++;
			else if ( input[i] == ' ' )
				blank++;
		}
		printf("%d %d %d %d\n", lowercase, uppercase, number, blank);
	}
}