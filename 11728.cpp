#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> Array1; Array1.resize(N);
	vector<int> Array2; Array2.resize(M);
	vector<int> Array3; Array3.resize(N + M);
	for ( int i = 0; i < N; i++ ) cin >> Array1[i];
	for ( int i = 0; i < M; i++ ) cin >> Array2[i];
	int i, j, k;
	i = j = k = 0;
	
	while ( i < N && j < M )
	{
		if ( Array1[i] < Array2[j] ) 
			Array3[k++] = Array1[i++];
		else						
			Array3[k++] = Array2[j++];
	}

	while ( i < N ) Array3[k++] = Array1[i++];
	while ( j < M ) Array3[k++] = Array2[j++];

	for ( int i = 0; i < N + M; i++ )
	{
		cout << Array3[i] << " ";
	}
	cout << '\n';
}