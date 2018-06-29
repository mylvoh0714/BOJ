#include <iostream>
#include <vector>
using namespace std;

// suppose sqaure matrix and the size of matrix1,2 are equal. 
vector<vector<int>> multiplyMatrix(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2)
{
	if ( matrix1.size() != matrix2.size() ) {
		cout << "error" << '\n';
		return matrix1;
	}
		
	int n = matrix1.size();
	vector<vector<int>> retMatrix(n, vector<int>(n));
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			for ( int k = 0; k < n; k++ )
			{
				retMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			retMatrix[i][j] %= 1000;
		}
	}
	return retMatrix;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	long long pow;
	cin >> n >> pow;
	vector<vector<int>> matrix(n,vector<int>(n));
	vector<vector<int>> result(n, vector<int>(n));

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			cin >> matrix[i][j];
		}
		result[i][i] = 1; // setting resultM to identity matrix
	}

	while ( pow > 0 )
	{
		if ( pow % 2 == 1 ) {
			result = multiplyMatrix(result, matrix);
		}
		matrix = multiplyMatrix(matrix, matrix);
		pow /= 2;
	}

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}