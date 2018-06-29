#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, target;
	cin >> n >> target;
	vector<int> arr(n+2);
	for ( int i = 1; i <= n; i++ )
	{
		cin >> arr[i];
	}

	int s, e;
	s = e = 1;
	int len = n + 1;
	int sum = arr[1];
	while ( s<=e && e <= n )
	{
		if ( sum > target ) {
			if ( e - s + 1 < len ) {
				len = e - s + 1;
			}
			sum -= arr[s++]; // range--
		}	
		else if ( sum == target ) {
			if ( len > e - s + 1 ) 
				len = e - s + 1;
			sum+=arr[++e];
		}
		else {
			sum += arr[++e]; // range++
		}
	}
	if ( len > n ) len = 0;
	cout << len << '\n';
	return 0;
}