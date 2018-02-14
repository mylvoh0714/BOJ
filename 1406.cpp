//BOJ_1406 ������
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int cur, N;
	cur = str.size(); // cur�ǰ��� 0���� ~ str.size() ����

	string choice;
	scanf("%d", &N);
	for( int i=0;i<N;i++)
	{
		cin >> choice;
		if ( choice == "L" )
		{
			if ( cur != 0 )
				cur--;
		}
		else if ( choice == "D" )
		{
			if ( cur != str.size() )
				cur++;
		}
		else if ( choice == "B" )
		{
			if ( cur != 0 )
			{
				str.erase(str.begin() + cur - 1);
				cur--;
			}
		}
		else if ( choice == "P" )
		{
			string plusstr;
			cin >> plusstr;
			str.insert(cur, plusstr);
			cur++;
		}
	}
	cout << str;
	
}