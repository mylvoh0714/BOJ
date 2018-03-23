#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n;
vector<pair<int, int>> vec;

int main()
{
	scanf("%d", &n);
	vec.resize(n);
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d %d", &vec[i].first, &vec[i].second);
	}
	sort(vec.begin(), vec.end());
	for ( int i = 0; i < n; i++ )
	{
		printf("%d %d\n", vec[i].first, vec[i].second);
	}
}