#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class Queue{
	node *head;
	node *tail;
	public:
		Queue()
		{
			head=NULL;
			tail=NULL;
		}
		void create(int a)
		{
			node *newnode;
			newnode=new struct node;
			newnode->data=a;
			newnode->next=newnode;
			head=newnode;
			tail=head;
		}
		void enqueue(int a)
		{
			if(head==NULL)
			{
				create(a);
			}
			else
			{
				node *nn=new node;
				nn->data=a;
				nn->next=head;
				tail->next=nn;
				tail=nn;
			}
		}
		void dequeue()
		{
			if(head==tail)
			{
				head=tail=NULL;
				cout<<"Queue is empty\n";
			}
			else
			{
				node *ptr=head;
				head=head->next;
				tail->next=head;
				delete ptr;
			}
		}
		void traverse()
		{
			node *ptr=head;
			if(head==NULL)
			{
				cout<<"Queue is empty";
			}
			else
			{
				cout<<"Queue is:\n";
				do
				{
					cout<<ptr->data<<" ";
					ptr=ptr->next;
				}while(ptr!=head);
			}
		}
};
int main()
{
	Queue q;
	cout<<"1 for insert\n2 for delete\n3 for traversal\n0 for end\n";
	int n,a;
	cout<<"Enter choice:";
	cin>>n;
	while(n!=0)
	{
		switch(n)
		{
			case 1:
				cout<<"Enter element:";
				cin>>a;
				q.enqueue(a);
				cout<<"Enter choice:";
				cin>>n;
				break;
			case 2:
				q.dequeue();
				cout<<"Enter choice:";
				cin>>n;
				break;
			case 3:
				q.traverse();
				n=0;
				break;
		}
	}
}
