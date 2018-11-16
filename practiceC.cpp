#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > table;

int times;
int asize;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num1, num2;
	int dot1, dot2, fin;

	cin >> asize >> times;

	vector<int> isVisit(asize + 1);
	for ( int i = 0; i <= asize; i++ )
	{
		vector<int> arr(asize+1);
		table.push_back(arr);
	}
	for ( int i = 0; i < asize - 1; i++ )
	{
		cin >> num1 >> num2;
		table[num2][num1] = table[num1][num2] = 1;
	}

	for ( int i = 0; i < times; i++ )
	{
		queue<int> last;
		int len = 0;
		for ( int i = 0; i <= asize; i++ )
			isVisit[i] = 0;

		cin >> dot1 >> dot2 >> fin;
		
		int odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
		even2 = 1;
		isVisit[dot1] = 1;
		isVisit[dot2] = 1;
		for ( int i = 1; i <= asize; i++ )
		{
			if ( table[dot2][i] == 1 && i != dot1)
			{
				int k = i;
				isVisit[i] = 1;
				len = 1;
				odd2++;
				last.push(k);
			}
		}
		while ( !last.empty() )
		{
			int p = last.front();
			last.pop();
			len++;
			for ( int i = 1; i <= asize; i++ )
			{
				if ( isVisit[i] != 1 && table[p][i] == 1 )
				{
					int k = i;
					isVisit[i] = 1;
								
					if ( len % 2 == 0 )
						even2++;
					if ( len % 2 == 1 )
						odd2++;
					last.push(k);
				}
			}
		}

		
		for ( int i = 0; i <=asize; i++ )
			isVisit[i] = 0;

		even1 = 1;
		isVisit[dot1] = 1;
		isVisit[dot2] = 1;

		for ( int i = 1; i <= asize; i++ )
		{
			if ( table[dot1][i] == 1 && i != dot2 )
			{
				int k = i;
				isVisit[i] = 1;
				len = 1;
				odd1++;
				last.push(k);
			}
		}
		while ( !last.empty() )
		{
			int p = last.front();
			last.pop();
			len++;
			for ( int i = 1; i <= asize; i++ )
			{
				if ( isVisit[i] != 1 && table[p][i] == 1 )
				{
					int k = i;
					isVisit[i] = 1;

					if ( len % 2 == 0 )
						even1++;
					if ( len % 2 == 1 )
						odd1++;

					last.push(k);
				}
			}
		}
		int total;
		if ( fin == 1 )
			total = ( ( even1 ) * ( even2 ) ) + ( ( odd1 ) * ( odd2 ) );
		else
			total = ( ( even1 ) * ( odd2 ) ) + ( ( odd1 ) *( even2 ) );
	
		cout << total << "\n";
	}
	for ( int i = 0; i <= asize; i++ )
	{
		table[i].clear();
	}

	table.clear();
	isVisit.clear();
	return 0;
}