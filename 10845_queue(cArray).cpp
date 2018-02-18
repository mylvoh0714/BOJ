//10845_queue(cArray)
//BOJ 문제와는 조금 다르게 원형큐로 구현.
#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXSIZE 5
int Queue[MAXSIZE];

typedef struct queue
{
	int Arr[MAXSIZE];
	int front, rear;
	int size;
}queue;

void queue_init(queue* q)
{
	q->front = q->rear = 0;
	q->size = 0;
}

void queue_push(queue* q, int data)
{
	if ( ( q->rear + 1 ) % MAXSIZE == q->front )
	{
		cout << "queue가 다 찼습니다" << "\n";
		return;
	}
	q->rear = ( q->rear + 1 ) % MAXSIZE;
	q->Arr[q->rear] = data;	
	q->size++;
}

int queue_pop(queue* q)
{
	if ( ( q->rear ) % MAXSIZE == q->front )
	{
		return -1;
	}
	q->front = ( q->front + 1 ) % MAXSIZE;
	int temp = q->Arr[q->front];
	q->size--;
	return temp;		
}

int queue_size(queue q)
{
	return q.size;
}

int queue_empty(queue q)
{
	if ( q.size == 0 )
		return 1;
	else
		return 0;
}

int queue_front(queue q)
{
	if ( queue_empty(q) == 1 )
		return -1;
	else
		return q.Arr[q.front+1];
}

int queue_back(queue q)
{
	if ( queue_empty(q) == 1 )
		return -1;
	else
		return q.Arr[q.rear];
}

void queue_showstatus(queue q)
{
	cout << "front : " << q.front << endl;
	cout << "rear : " << q.rear << endl;
}

int main()
{
	queue* q = (queue*)malloc(sizeof(queue));
	queue_init(q);
	
	int N;
	char command[10];
	scanf("%d", &N);
	while ( N-- )
	{
		scanf("%s", command);
		if ( strcmp(command,"push")==0 )
		{
			int num;
			scanf("%d", &num);
			queue_push(q, num);
		}
		else if ( strcmp(command,"pop")==0 )
		{
			int temp = queue_pop(q);
			printf("%d\n", temp);
			
		}
		else if ( strcmp(command,"front")==0 )
		{
			printf("%d\n",queue_front(*q));
		}
		else if ( strcmp(command,"back")==0 )
		{
			printf("%d\n", queue_back(*q));
		}
		else if ( strcmp(command, "size") == 0 )
		{
			printf("%d\n", queue_size(*q));
		}
		else if ( strcmp(command,"empty")==0 )
		{
			printf("%d\n", queue_empty(*q));
		}
	}
	return 0;
}