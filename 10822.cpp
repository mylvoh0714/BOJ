// 10822 ���ϱ�
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
	sum += stoi(num); // ������ EOF �����ִ� ���� ó��
	printf("%d", sum);
}