#include <cstdio>
int calender[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char* day[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

int main()
{
	int m, d;
	scanf("%d %d", &m, &d);
	for ( int i = 1; i < m; i++ ) d += calender[i];
	
	printf("%s\n", day[d % 7]);
}