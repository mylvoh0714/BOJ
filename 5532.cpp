#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int lang = a%c == 0 ? a / c : a / c + 1;
	int math = b%d == 0 ? b / d : b / d + 1;
	int result = max(lang, math);
	cout << l-result << '\n';

	return 0;
}