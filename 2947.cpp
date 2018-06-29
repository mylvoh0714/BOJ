#include <iostream>
using namespace std;
int arr[5];

void printarr()
{
	for ( int i = 0; i < 5; i++ )
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for ( int i = 0; i < 5; i++ )
	{
		cin >> arr[i];
	}

	bool flag = true;
	while ( flag )
	{
		flag = false;
		for ( int i = 0; i < 4; i++ )
		{
			if ( arr[i] > arr[i + 1] ) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = true;
				printarr();
			}
		}
	}
	return 0;
}