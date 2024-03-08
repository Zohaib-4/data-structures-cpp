#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
};
node* head;
class singleelinkedlist
{
	
public:
	singleelinkedlist()
	{
		head = NULL;
	}
	void insertAtBeggining(int x)
	{
		node* temp = new node;
		temp->data = x;
		temp->next = head;
		head = temp;
	}
	void insertAtAnyLocation(int x, int pos)
	{
		node* temp1 = new node;
		temp1->data = x;
		temp1->next = NULL;
		if (pos == 1)
		{
			temp1->next = head;
			head = temp1;
		}
		node* temp2 = head;
		for (int i = 0; i < pos - 2; i++)
		{
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
	}
	void deleteAtAnyLocation(int pos)
	{
		node* temp = head;
		if (pos == 1)
		{
			head = temp->next;
			delete temp;
		}
		for (int i = 0; i < pos - 2; i++)
		{
			temp = temp->next;
		}
		node* temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;

	}
	//itrative approch
	void reverseByItration()
	{
		node* previous, *current, *next;
		current = head;
		previous = NULL;
		while (current != NULL)
		{
			next=current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		head = previous;
	}
	//recursion approch
	void reverseByRecurrsion(node* temp)
	{
		if (temp == NULL)
			return;
		reverseByRecurrsion(temp->next);
		cout << temp->data << " ";
		
	}
	void print()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};
int main()
{
	singleelinkedlist s;
	cout << "Insert data at beggining:\n";
	s.insertAtBeggining(5);
	s.insertAtBeggining(8);
	s.insertAtBeggining(7);
	s.print();
	cout << endl;
	cout << "Insert at any location:\n";
	s.insertAtAnyLocation(9, 3);
	s.print();
	cout << endl;
	cout << "Delete at any location:\n";
	s.deleteAtAnyLocation(2);
	s.print();
	cout << endl;
	cout << "Reverse By Itration:\n";
	s.reverseByItration();
	s.print();
	cout << endl;
	cout << "Reverse By Recurrsion:\n";
	s.reverseByRecurrsion(head);
	cout << endl;
	system("pause");
	return 0;
}