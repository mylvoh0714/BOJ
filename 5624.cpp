#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> vec;
int n;
bool arr[400001]; // arr[n+200000] = n�� ����Ǿ������� true;

int main()
{
	int result = 0;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	vec.resize(n + 1);
	for ( int i = 1; i <= n; i++ )
	{
		cin >> vec[i];
	}
	for ( int i = 1; i <= n; i++ )
	{
		
	}
	
	for ( int i = 1; i <= n; i++ ) // check if set = i-j
	{
		for ( int j = 1; j < i; j++ )
		{
			int temp = vec[i] - vec[j];
			if ( arr[temp + 200000] == true )
			{	
				result++;
				break;
			}
		}
		for ( int j = 1; j < i; j++ )
		{
			int temp = vec[i] + vec[j];
			arr[temp + 200000] = true;
		}
	}

	cout << result << '\n';
	return 0;
}