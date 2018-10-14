#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class linkedlist
{
 node *head;
 public:
 linkedlist()
 {	
 head=NULL;
 }	
 void createnode(int val)
 {
 	node *newnode;
 	newnode=(node*)malloc(sizeof node );
 	newnode->data=val;
 	newnode->next=NULL;
 	head=new node ;
 }
void insert(int val)
{
 	if(head==NULL)
	 createnode(val);
	 else
	 {
	 	node *firstnode;
	 	firstnode=(node*)malloc(sizeof node);
	 	firstnode->data=val;
	 	firstnode->next=head;
	 	head=firstnode;
	 }	
}
void traverse()
{
	struct node *curr;
	for(curr=head;curr!=NULL;curr=curr.next)
	cout<<curr;
}
void insertatend(int val)
{
	if(head==NULL)
 	{
 		createnode(val);
	}
	else
	{
		node *temp;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		node *newnode;
		newnode=(node*)malloc(sizeof node);
		newnode->data=val;
		newnode->next=NULL;
		temp->next=newnode;
	}
}
 void insertatloc(int val,int loc)
 {
 	if(head==NULL)
 	{
 		createnode(val);
	}
	else if(head->next==NULL)
	insertatend(val);
	else
	{
		node->temp;
		temp=head;
		for(int i=1;i<loc-1;i++)
		{
			temp=temp->next;
		}
		node *newnode;
		newnode->data=val;
		newnode->next=temp->next;
		temp-next+=newnode;
	}
 }
 
};
void main()
{
	linkedlist l;
	l.createnode(50);
	l.insert(60);
	l.insert(70);
	l.traverse();
}
