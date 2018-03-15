#include <iostream>
#include <stack>
#include <string>	
using namespace std;
string input;
stack<int> data;
stack<string> oper;

void Process(char str)
{

}

int main()
{
	cin >> input;
	for ( int i = 0; i < input.size(); i++ )
	{
		Process(input[i]);
	}
}