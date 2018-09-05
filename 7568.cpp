#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> arr1(n); // weight
	vector<int> arr2(n); // height
	for ( int i = 0; i < n; i++ )
	{
		cin >> arr1[i] >> arr2[i];
	}
	
	for ( int i = 0; i < n; i++ )
	{
		int ans = 0;
		for ( int j = 0; j < n; j++ )
		{
			if ( i == j ) continue;
			if ( arr1[i] < arr1[j] && arr2[i] < arr2[j] ) ans++;
		}
		cout << ans+1 << ' ';
	}
	cout << '\n';
}