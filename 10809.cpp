// 10809 ¾ËÆÄºª Ã£±â
#include <iostream>
#include <cstring>
using namespace std;
int Alphbet[26];

int main()
{
	for ( int i = 0; i < 26; i++ )
	{
		Alphbet[i] = -1;
	}
	char input[101];
	scanf("%s", input);
	for ( int i = 0; i < strlen(input); i++ )
	{
		if(Alphbet[input[i]-'a'] == -1 )
			Alphbet[input[i] - 'a'] = i;
	}
	for ( int i = 0; i < 26; i++ )
	{
		printf("%d ", Alphbet[i]);
	}

	return 0;
}