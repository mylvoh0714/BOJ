// 10845_queue(c++) circular queue
// 문제랑 조금 다르게 원형큐로 구현.
#include <iostream>
#include <cstring>
using namespace std;

class queue
{
private:
	int* Arr;
	int front;
	int rear;
	int maxsize;
	int size;
public:
	queue(int size) : front(0), rear(0), maxsize(size), size(0)
	{
		Arr = new int[size];
	}
	
	bool isFull()
	{
		return ( size == maxsize - 1 ) && ( ( rear + 1 ) % maxsize == front );
	}

	bool isEmpty()
	{
		return ( size == 0 ) && ( rear%maxsize == front );
	}
	void enqueue(int num)
	{
		if ( this->isFull() )
			return;
		Arr[rear] = num;
		rear = (rear + 1) % maxsize;
		size++;
	}
	int dequeue()
	{
		if ( this->isEmpty() )
			return -1;
		int temp = Arr[front];
		front = ( front + 1 ) % maxsize;
		size--;
		return temp;
	}
	int print_size()
	{
		return this->size;
	}
	int print_empty()
	{
		return this->isEmpty() ? 1 : 0;
	}
	int print_front()
	{
		return this->isEmpty() ? -1 : this->Arr[front];
	}
	int print_back()
	{
		return this->isEmpty() ? -1 : (rear==0?Arr[maxsize-1]:rear-1);
	}	
};

int main()
{	
	queue Queue(10);
	int N;
	char command[10];
	scanf("%d", &N);
	while ( N-- )
	{
		scanf("%s", command);
		if ( strcmp(command, "push") == 0 )
		{
			int num;
			scanf("%d", &num);
			Queue.enqueue(num);

		}
		else if ( strcmp(command, "pop") == 0 )
		{
			int temp = Queue.dequeue();
			printf("%d\n", temp);
		}
		else if ( strcmp(command, "front") == 0 )
		{
			int temp = Queue.print_front();
			printf("%d\n", temp);
		}
		else if ( strcmp(command, "back") == 0 )
		{
			int temp = Queue.print_back();
			printf("%d\n", temp);
		}
		else if ( strcmp(command, "size") == 0 )
		{
			int temp = Queue.print_size();
			printf("%d\n", temp);
		}
		else if ( strcmp(command, "empty") == 0 )
		{
			int temp = Queue.print_empty();
			printf("%d\n", temp);
		}
	}
}