#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int score, result;

int main()
{
	vector<pair<int, int>> vec(8);
	for ( int i = 0; i < 8; i++ )
	{
		scanf("%d", &score);
		vec[i].first = score;
		vec[i].second = i+1;
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	vector<int> resultvec(5);
	for ( int i = 0; i < 5; i++ )
	{
		result += vec[i].first;
		resultvec[i] = vec[i].second;
	}
	printf("%d\n", result);
	sort(resultvec.begin(), resultvec.end());

	for ( int i = 0; i < 5; i++ )
	{
		printf("%d ", resultvec[i]);
	}
}