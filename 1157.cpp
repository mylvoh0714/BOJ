	#include <iostream>
	using namespace std;
	char input[20];
	int charToint[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	int result;

	int main()
	{
		scanf("%s", input);
		for ( int i = 0; input[i] != '\0'; i++ )
		{
			int index = input[i] - 'A';
			result += charToint[index];
		}
		printf("%d\n", result);
	}