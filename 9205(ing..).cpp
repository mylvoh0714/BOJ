#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int visited[101];
int adjM[101][101];
int n;

typedef struct Point
{
	int x;
	int y;
	Point() : x(0), y(0)
	{
	}
	Point(int _x, int _y) : x(_x), y(_y)
	{
	}
}Point;

void dfs(Point p)
{

}

void MakeAdjM(vector<Point>& p)
{
	int size = p.size();
	for ( int i = 1; i <= size+1; i++ )
	{
		for ( int j = i + 1; i < size+1; j++ )
		{
			if ( abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) <= 1000 )
				adjM[i][j] = adjM[j][i] = 1;
		}
	}
}

void _main(int TestCase)
{
	cin >> n;
	vector<Point> vecP(n + 3); // [1] ~ [n+2] index
	cin >> vecP[1].x >> vecP[1].y; // start
	for ( int i = 2; i <= n ; i++ ) // store
	{
		int a, b;
		cin >> a >> b;
		vecP[i].x = a;
		vecP[i].y = b;
	}
	cin >> vecP[n + 2].x >> vecP[n + 2].y; // des
	MakeAdjM(vecP);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for ( int i = 1; i <= T; i++ )
	{
		_main(T);
	}
}