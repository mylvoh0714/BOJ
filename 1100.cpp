// BOJ_1100 го╬А д╜
#include <iostream>
using namespace std;

int main()
{
	char chess[8][9];
	for ( int i = 0; i < 8; i++ )
	{
		scanf("%s", chess[i]);
	}
	int count = 0;
	for ( int i = 0; i < 8; i++ )
	{
		for ( int j = 0; j < 8; j++ )
		{
			if ( ( i + j ) % 2 == 0 && chess[i][j] == 'F' )
				count++;
		}
	}
	printf("%d\n", count);
	return 0;
}