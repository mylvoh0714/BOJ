// BOJ 1535 ¾È³ç
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int w[21]; // weight array
int v[21]; // value array
int dp[21][101]; // dp[index][life]. maximum value

// Return the maximum value can be put in a knapsack of capacity W
int KnapSack(int W, int n)
{
	if ( n == 0 || W == 0 )
		return 0;

	if ( w[n - 1] >= W )
		return KnapSack(W, n - 1);
	else
		return max(v[n - 1] + KnapSack(W - w[n - 1], n - 1), KnapSack(W, n - 1));
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for ( int i = 0; i < n; i++ ) cin >> w[i];
	for ( int i = 0; i < n; i++ ) cin >> v[i];
	cout << KnapSack(100, n) << '\n';
}