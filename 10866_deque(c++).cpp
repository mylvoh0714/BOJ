//10866 deque(��)
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
		cout << data << "�� push_back �Ǿ����ϴ�." << endl;
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
		cout << data << "�� push_front �Ǿ����ϴ�." << endl;
	}

	void pop_front()
	{
		int temp = front->data;
		front = front->rightnode;
		delete front->leftnode;
		front->leftnode = nullptr;
		size--;
		cout << temp << "�� pop_front �Ǿ����ϴ�." << endl;
	}

	void pop_back()
	{
		int temp = rear->data;
		rear = rear->leftnode;
		delete rear->rightnode;
		rear->rightnode = nullptr;
		size--;
		cout << temp << "�� pop_back �Ǿ����ϴ�." << endl;
	}

	void print_size()
	{
		cout << "size()�� ������ : " << this->size << endl;
	}

	void print_empty()
	{
		if ( size == 0 )
			cout << "���� �������" << endl;
		else
			cout << "���� ������� ����" << endl;
	}

	void print_front()
	{
		cout << "print_front()�� ��� : " << this->front->data << endl;
	}
	
	void print_back()
	{
		cout << "print_back()�� ��� : " << this->rear->data << endl;
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
			cout << "����� �߸��Ǿ����ϴ�" << endl;
	}
}