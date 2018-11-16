#include <bits/stdc++.h>
int a[4];
int visited[61][61][61];
using namespace std;

typedef struct abc{
	int a;
	int b;
	int c;
}abc;

int main()
{
	int n; scanf("%d", &n);
	abc scv;
	
	for ( int i = 1; i <= n; i++ ) scanf("%d", a + i);
	if ( n == 1 ) {
		scv.a = a[1];
		scv.b = 0;
		scv.c = 0;
	}
	else if ( n == 2 ) {
		scv.a = a[1];
		scv.b = a[2];
		scv.c = 0;
	}
	else {
		scv.a = a[1];
		scv.b = a[2];
		scv.c = a[3];
	}

	queue<int> q;
	
}