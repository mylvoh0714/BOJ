#include <iostream>
using namespace std;

int main()
{
	char c[1001];
	scanf("%s", c);
	for ( int i = 0; c[i] != '\0'; i++ )
	{
		if ( c[i] == 'A' || c[i] == 'B' || c[i] == 'C' || c[i] == 'a' || c[i] == 'b' || c[i] == 'c' )
			printf("%c", c[i] + 23);
		else
			printf("%c", c[i] - 3);
	}
		
	return 0;
}