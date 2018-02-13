//10866 deque(덱)eee
#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	node* leftnode;
	node* rightnode;
}node;

typedef struct deque
{
	int size;
	node* front;
	node* rear;
}deque;

deque* deque_init();
void push_back(deque* dq, int data);
void push_front(deque* dq, int data);
int pop_front(deque* dq);
int pop_back(deque* dq);
void print_size(deque* dq);
int print_empty(deque* dq);
void print_front(deque* dq);
void print_back(deque* dq);

int main()
{

	int N, num;
	char command[10];
	deque *dq;
	dq = deque_init();
	scanf("%d", &N);
	for ( int i = 0; i < N; i++ )
	{
		scanf("%s", command);
		if ( command[0] == 'p' && command[5] == 'b' ) // push_back
		{
			scanf("%d", &num);
			push_back(dq, num);
		}
		else if ( command[0] == 'p' && command[5] == 'f' ) // push_front
		{
			scanf("%d", &num);
			push_front(dq, num);
		}
		else if ( command[0] == 'p' && command[4] == 'f' ) // pop_front
			pop_front(dq);
		else if ( command[0] == 'p' && command[4] == 'b' ) // pop_back
			pop_back(dq);
		else if ( command[0] == 's' ) // size
			print_size(dq);
		else if ( command[0] == 'e' ) // empty
			cout << print_empty(dq) << endl;
		else if ( command[0] == 'f' ) // front
			print_front(dq);
		else if ( command[0] == 'b') // back
			print_back(dq);
		else
			cout << "명령이 잘못되었습니다" << endl;
			

	}
}

deque* deque_init()
{
	deque* dq = (deque*)malloc(sizeof(deque));
	dq->size = 0;
	dq->front = dq->rear = NULL;
	return dq;
}

void push_back(deque* dq, int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	if ( dq->size == 0 )
	{
		dq->front = newNode;
		dq->rear = newNode;
		newNode->leftnode = newNode;
		newNode->rightnode = newNode;
	}
	else
	{
		newNode->leftnode = dq->rear;
		newNode->rightnode = newNode;
		dq->rear->rightnode = newNode;
		dq->rear = newNode;
	}
	dq->size++;
	cout << "push_back이 수행되었습니다, size : " << dq->size << endl;
}

void push_front(deque* dq, int data)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	if ( dq->size == 0 )
	{
		dq->front = newNode;
		dq->rear = newNode;
		newNode->leftnode = newNode;
		newNode->rightnode = newNode;
	}
	else
	{
		newNode->leftnode = newNode;
		newNode->rightnode = dq->front;
		dq->front->leftnode = newNode;
		dq->front = newNode;
	}
	dq->size++;
	cout << "push_front이 수행되었습니다, size : " << dq->size << endl;
}

int pop_front(deque* dq)
{
	int temp;
	if ( dq->front == NULL )
		return -1;
	temp = dq->front->data;
	dq->front = dq->front->rightnode;
	free(dq->front->leftnode);
	dq->front->leftnode = dq->front;
	dq->size--;
	cout << "pop_front가 수행되었습니다, size : " << dq->size << endl;
	return temp;
}

int pop_back(deque* dq)
{
	int temp;
	if ( dq->rear == NULL )
		return -1;
	temp = dq->rear->data;
	dq->rear = dq->rear->leftnode;
	free(dq->rear->rightnode);
	dq->rear->rightnode = dq->rear;
	dq->size--;
	cout << "pop_back이 수행되었습니다, size : " << dq->size << endl;
	return temp;
}

void print_size(deque* dq)
{
	cout << "print_size이 수행되었습니다" << dq->size << endl;
}

int print_empty(deque* dq)
{
	if ( dq->size == 0 )
		return 1;
	else
		return 0;
}

void print_front(deque* dq)
{
	cout << "print_front가 수행되었습니다, front : " << dq->front->data << endl;
}

void print_back(deque* dq)
{
	cout << "print_back이 수행되었습니다, back : " << dq->rear->data << endl;
}