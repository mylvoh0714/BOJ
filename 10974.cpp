// BOJ_10974 모든 순열(10972 연관)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool next_permutation(vector<int> &arr, int size)
{
	int i = size - 1;
	while ( i > 0 && arr[i - 1] >= arr[i] ) i--;
	if ( i <= 0 )
		return false;
	int j = size - 1;
	while ( arr[j] <= arr[i - 1] ) j--;
	swap(arr[j], arr[i - 1]);
	sort(arr.begin() + i, arr.end());
	for ( auto i = arr.begin(); i != arr.end(); i++ )
	{
		cout << *i << ' ';
	}
	cout << '\n';
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	vector<int> arr;
	int n;
	cin >> n;
	arr.resize(n);
	for ( int i = 0; i < n; i++ )
		arr[i] = i + 1;
	
	for ( auto itr = arr.begin(); itr != arr.end(); itr++ )
		cout << *itr << ' ';
	cout << '\n';
	
	do
	{
	}
	while ( next_permutation(arr, n) );
	
	return 0;
}