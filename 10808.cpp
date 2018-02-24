// 10808 ¾ËÆÄºª °³¼ö
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int Alphbet[26] = { 0 };
	char input[101];
	scanf("%s", input);
	for ( int i = 0; i < strlen(input); i++ )
	{
		Alphbet[input[i] - 'a']++;
	}
	for ( int i = 0; i < sizeof(Alphbet)/sizeof(int); i++ )
	{
		printf("%d ", Alphbet[i]);
	}
	
}