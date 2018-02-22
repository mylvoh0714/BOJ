#include <iostream>

using namespace std;

typedef struct Josephus
{
	int num;
	bool visited;
}Josephus;

int main()
{
	int N, M, temp;
	scanf("%d %d", &N,&M);
	Josephus* Jsp = new Josephus[N];
	for ( int i = 0; i < N; i++ ) // Josepus 배열 초기화
	{
		Jsp[i].num = i + 1;
		Jsp[i].visited = false;
	}

	int num = -1 + M;
	Jsp[num].visited = true; // 출력 형식때문에 1번과정은 별도로 지정.

	cout << "<" << Jsp[num].num;

	for(int i=0;i<N-1;i++)
	{
		temp = M;
		while(temp)
		{
			num = ( num + 1 ) % N;
			if ( Jsp[num].visited == true )
				continue;
			temp--;
		}
		Jsp[num].visited = true;
		cout << ", " << Jsp[num].num;
	}
	cout << ">";
	
	
	

}