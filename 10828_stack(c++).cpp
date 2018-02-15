// 10828 stack
#include <iostream>	
#include <string>
using namespace std;

class node
{
private:
	int data;
	node* nextnode;
public:
	node() :data(0)
	{
		nextnode = nullptr;
	}
	node(int num) : data(num)
	{
		nextnode = nullptr;
	}
	friend class stack;
};

class stack
{
private:
	int size;
	node* head;
public:
	stack() : size(0)
	{
		head = nullptr;
	}

	bool isEmpty()
	{
		return ( size == 0 );
	}

	void push(int num)
	{
		node* newnode = new node(num);
		newnode->nextnode = head;
		head = newnode;
		size++;
	}

	int pop()
	{
		if ( !isEmpty() )
		{
			int temp = head->data;
			node* next = new node();
			next = head->nextnode;
			delete head;
			head = next;
			size--;
			return temp;
		}
		else
			return -1;
	}

	int top()
	{
		if ( !isEmpty() )
			return head->data;
		else
			return -1;
	}
	void print()
	{
		cout << "< Stack printÀÇ °á°ú >" << endl;
		node* Searchnode = head;

		while ( Searchnode != nullptr )
		{
			cout << Searchnode->data << endl;
			cout << "---------------" << endl;
			Searchnode = Searchnode->nextnode;
		}
	}
};

int main()
{
	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.pop();
	cout << st.top() << endl;
	st.print();
	
}