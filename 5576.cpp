// BOJ 5576
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> vec1(10);
	vector<int> vec2(10);
	for ( int i = 0; i < 10; i++ )
	{
		cin >> vec1[i];
	}
	for ( int i = 0; i < 10; i++ )
	{
		cin >> vec2[i];
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	cout << vec1[7] + vec1[8] + vec1[9] << ' ';
	cout << vec2[7] + vec2[8] + vec2[9] << ' ';
}