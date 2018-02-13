//10866 deque(덱)
#include <iostream>
#include <string>
using namespace std;

class node
{
public:
	int data;
	node* leftnode;
	node* rightnode;
	node(int data)
	{
		this->data = data;
		leftnode = nullptr;
		rightnode = nullptr;
	}
};

class deque
{
public:
	int size;
	node* front;
	node* rear;

	deque()
	{
		size = 0;
		front = nullptr;
		rear = nullptr;
	}

	void push_back(int data)
	{
		node* newNode = new node(data);
		if ( this->size == 0 )
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->rightnode = newNode;
			newNode->leftnode = rear;
			rear = newNode;
		}
		size++;
		cout << data << "이 push_back 되었습니다." << endl;
	}

	void push_front(int data)
	{
		node* newNode = new node(data);
		if ( this->size == 0 )
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			front->leftnode = newNode;
			newNode->rightnode = front;
			front = newNode;
		}
		size++;
		cout << data << "이 push_front 되었습니다." << endl;
	}

	void pop_front()
	{
		int temp = front->data;
		front = front->rightnode;
		delete front->leftnode;
		front->leftnode = nullptr;
		size--;
		cout << temp << "이 pop_front 되었습니다." << endl;
	}

	void pop_back()
	{
		int temp = rear->data;
		rear = rear->leftnode;
		delete rear->rightnode;
		rear->rightnode = nullptr;
		size--;
		cout << temp << "이 pop_back 되었습니다." << endl;
	}

	void print_size()
	{
		cout << "size()의 수행결과 : " << this->size << endl;
	}

	void print_empty()
	{
		if ( size == 0 )
			cout << "덱이 비어있음" << endl;
		else
			cout << "덱이 비어있지 않음" << endl;
	}

	void print_front()
	{
		cout << "print_front()의 결과 : " << this->front->data << endl;
	}
	
	void print_back()
	{
		cout << "print_back()의 결과 : " << this->rear->data << endl;
	}
};


int main()
{
	string str;
	int N, num;
	deque dq;
	scanf("%d", &N);
	for ( int i = 0; i < N; i++ )
	{
		cin >> str;
		if ( str == "push_back" )
		{
			scanf("%d", &num);
			dq.push_back(num);
		}
		else if ( str == "push_front" ) 
		{
			scanf("%d", &num);
			dq.push_front(num);
		}
		else if ( str == "pop_front" )
			dq.pop_front();
		else if ( str == "pop_back" )
			dq.pop_back();
		else if ( str == "size" )
			dq.print_size();
		else if (str == "empty" )
			dq.print_empty();
		else if ( str == "front" )
			dq.print_front();
		else if ( str == "back" )
			dq.print_back();
		else
			cout << "명령이 잘못되었습니다" << endl;
	}
}