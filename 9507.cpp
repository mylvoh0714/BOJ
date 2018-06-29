#include <iostream>
using namespace std;
typedef long long ll;
ll koongArr[68];

ll koongFibo(int num)
{
	if ( koongArr[num] > 0 )
		return koongArr[num];
	else
		return koongArr[num] = koongFibo(num - 1) + koongFibo(num - 2) + 
								koongFibo(num - 3) + koongFibo(num - 4);
}

int main()
{
	koongArr[0] = koongArr[1] = 1;
	koongArr[2] = 2;
	koongArr[3] = 4;
	int T;
	cin >> T;
	for ( int i = 1; i <= T; i++ )
	{
		int target;
		cin >> target;
		cout << koongFibo(target) << '\n';
	}
}