// 10845_queue(c implementation)
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node
{
	int data;
	node* nextnode;
}node;

typedef struct queue
{
	node* front;
	node* rear;
	int size;
}queue;

void queue_init(queue *q)
{
	q->front = q->rear = NULL;
	q->size = 0;
}

bool queue_empty(queue *q)
{
	return (q->size == 0);
}

void queue_enqueue(queue *q, int data)
{
	node* newNode = (node*)malloc(sizeof(node*));
	newNode->data = data;
	newNode->nextnode = NULL;
	q->size++;
	if ( q->front == NULL&& q->front == NULL )
	{
		q->front = q->rear = newNode;
		return;
	}
	q->rear->nextnode = newNode;
	q->rear = newNode;
}

void queue_dequeue(queue *q, int data)
{
	if ( queue_empty(q) )
	{
		cout << "queue가 비어있어 dequeue 할 수 없습니다!" << endl;
		return;
	}
	node* temp = q->front;
	q->front = q->front->nextnode;
	free(temp);
	q->size--;	
}

int main()
{
	queue q;
	queue_init(&q);
	queue_enqueue(&q, 3);
	
}