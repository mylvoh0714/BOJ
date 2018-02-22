// 10822 더하기
#include <iostream>
#include <string>
using namespace std;
string str, num;
int sum = 0, i = 0;

int main()
{
	cin >> str;
	while ( str[i] != '\0' )
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
		i++;
	}
	sum += stoi(num); // 마지막 EOF 옆에있는 숫자 처리
	printf("%d", sum);
}