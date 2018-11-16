#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
int indegree[27];

int solution(string skill, vector<string> skill_trees)
{
	int ans = 0;

	for ( int tree = 0; tree < skill_trees.size(); tree++ )
	{
		memset(indegree, 0, sizeof(indegree));
		for ( int i = 0; i < skill.size(); i++ )
		{
			indegree[skill[i] - 'A'] = i + 1;
		}

		string str = skill_trees[tree];
		bool flag = false;
		for ( int i = 0; i<str.size(); i++ )
		{
			if ( skill.find(str[i]) != str.npos ) {
				for ( int idx = skill.find(str[i]); idx < skill.size(); idx++ )
				{
					indegree[skill[idx] - 'A']--;
				}
			}

			if ( indegree[str[i] - 'A'] > 0 ) {
				flag = true;
				break;
			}
		}
		if ( flag == false ) ans++;
	}

	return ans;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<string> skill_trees;
	skill_trees.push_back("BDA");
	skill_trees.push_back("CDEF");
	skill_trees.push_back("CBD");

	string skill = "CBD";
	int ans = solution(skill, skill_trees);
	cout << ans << endl;

}
