#include <bits/stdc++.h>
using namespace std;

typedef struct Student {
    string name;
    int lang;
    int eng;
    int math;
}Student;

bool cmp(const Student &s1, const Student &s2) {
    if(s1.lang != s2.lang) return s1.lang > s2.lang;
    else if(s1.eng != s2.eng) return s1.eng < s2.eng;
    else if (s1.math != s2.math) return s1.math > s2.math;
    else return s1.name < s2.name;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<Student> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].name >> a[i].lang >> a[i].eng >> a[i].math;
    }
    sort(a.begin(),a.end(),cmp);
    for(auto itr = a.begin();itr!=a.end();itr++)
    {
        cout << itr->name << '\n';
    }
}
