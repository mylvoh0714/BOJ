#include <iostream>
#include <queue>
using namespace std;
int input[51];
int indegree[51];
vector<int> vec[51];
int rootnum, delnum;
int main()
{
	int n;
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d", &input[i]);
		if ( input[i] == -1 )
		{
			rootnum++;
			continue;
		}
		vec[i].push_back(input[i]);
		indegree[input[i]]++;
	}
	scanf("%d", &delnum);

	int result = indegree[delnum];
	for ( int i = 0; i < vec[delnum].size(); i++ )
	{
		int index = vec[delnum][i];
		result += indegree[index];
	}
	printf("%d\n", n - rootnum - result);
}