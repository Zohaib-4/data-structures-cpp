#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node* prev;
};

class doubleelinkedlist
{
	node* head;
public:
	doubleelinkedlist()
	{
		head = NULL;
	}
	node* GetNewNode(int x)
	{
		node* newnode = new node;
		newnode->data = x;
		newnode->prev = NULL;
		newnode->next = NULL;
		return newnode;
	}
	void insertAtBeggining(int x)
	{
		node* temp = GetNewNode(x);
		if (head == NULL)
		{
			head = temp;
			return;
		}
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	void printForward()
	{
		node* temp= head;

		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	//REVERSE PRINT
	void printREeverse()
	{
		node* temp = head;
		if (temp == NULL)
			return;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->prev;
		}
	}
	/*void deleteNode(int ele)
	{
		node* temp = head;
		for (int i = 0; i < ele - 1; i++)
		{
			temp = temp->next;
		}
		temp->prev = temp->next;
		delete temp;

	}*/
};
int main()
{
	doubleelinkedlist d;
	d.insertAtBeggining(5);
	d.insertAtBeggining(8);
	d.insertAtBeggining(10);
	d.printForward();
	cout << endl;
	d.printREeverse();
	cout << endl;
	d.deleteNode(2);
	d.printForward();
	cout << endl;
	system("pause");
	return 0;
}