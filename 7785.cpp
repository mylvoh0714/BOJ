#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,bool> m;
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        char name[7];
        char state[7];
        scanf("%s",name); scanf("%s",state);
        if(strcmp(state,"enter") == 0) {
            m[name] = true;
        } else if(strcmp(state, "leave") == 0) {
            m[name] = false;
        }
    }
    auto itr = m.end(); itr--;
    for(itr;itr!=m.begin();itr--)
    {
        if(itr->second == true) {
            cout << itr->first << '\n';
        }
    }

    // case of itr=m.begin()
    if(itr->second == true) {
        cout << itr->first << '\n';
    }
}
