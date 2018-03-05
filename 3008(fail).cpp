//BOJ 3008 직각 삼각형의 개수
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> myPoint;
int n,result;
myPoint PointArr[1501]; // 3<=N<=1500

myPoint getVecSub(myPoint p1, myPoint p2) // get vector subtraction(difference)
{
	myPoint ret = { 0,0 };
	ret.first = p2.first - p1.first;
	ret.second = p2.second - p1.second;
	return ret;
}

double getDistance(myPoint p1, myPoint p2) // return pow(distance,2)
{
	myPoint temp = getVecSub(p1, p2);
	return ( temp.first )*(temp.first) + ( temp.second )*(temp.second);
}

bool is_Rtriangle(myPoint p1, myPoint p2, myPoint p3)
{
	double Max, p1p2, p1p3, p2p3;
	p1p2 = getDistance(p1, p2);
	p1p3 = getDistance(p1, p3);
	p2p3 = getDistance(p2, p3);
	Max = max(p1p2, max( p1p3, p2p3 ));
	if ( Max == p1p2 ) // p1p3와 p2p3 내적 == 0 검사
	{
		return getVecSub(p1, p3).first * getVecSub(p2, p3).first +
			getVecSub(p1, p3).second * getVecSub(p2, p3).second == 0;
	}
	else if ( Max == p1p3 ) // p1p2 p2p3
	{
		return getVecSub(p1, p2).first * getVecSub(p2, p3).first +
			getVecSub(p1, p2).second*getVecSub(p2, p3).second == 0;
	}
	else // p1p2 p1p3
	{
		return getVecSub(p1, p2).first*getVecSub(p1, p3).first +
			getVecSub(p1, p2).second * getVecSub(p1, p3).second == 0;
	}
}

int main()
{
	scanf("%d", &n);
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d %d", &PointArr[i].first, &PointArr[i].second);
	}
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			for ( int k = j + 1; k < n; k++ )
			{
				if(is_Rtriangle(PointArr[i], PointArr[j], PointArr[k])==true)
					result++;
			}
		}
	}
	printf("%d\n", result);
}