#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, k;
string arr[1001];
int temp, result;

string reverse_string(const string str) // num <= 1000
{
	string temp = "";
	int last = str.size() - 1;
	for ( int i = last; i>=0; i-- )
	{
		temp += str[i];
	}
	return temp;
}

int main()
{
	scanf("%d %d", &n, &k);
	for ( int i = 1; i <= k; i++ )
	{
		arr[i] = to_string(n*i);
		arr[i] = reverse_string(arr[i]);
		temp = stoi(arr[i]);
		if ( result < temp ) result = temp;
	}
	printf("%d\n", result);
}