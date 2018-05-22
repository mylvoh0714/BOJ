#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans;

int calDifferMax(const vector<int> &vec)
{
	int sum = 0;
	for ( int i = 0; i < vec.size() - 1; i++ )
	{
		sum += abs(vec[i] - vec[i + 1]);
	}
	return sum;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> vec(n);
	for ( int i = 0; i < n; i++ )
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	do
	{
		int temp = calDifferMax(vec);
		ans = max(ans, temp);
	}
	while ( next_permutation(vec.begin(), vec.end()) );
	
	cout << ans << '\n';
	return 0;

}