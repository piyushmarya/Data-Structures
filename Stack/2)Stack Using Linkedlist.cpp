#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class stack{
	node *top;
	public:
		stack()
		{
			top=NULL;	
		}
		void push(int item){
			{
				node *newnode=new struct node;
				newnode->data=item;
				newnode->next=top;
				top=newnode;
			}
		}
		void pop()
		{
			top=top->next;
		}
		void traverse()
		{
			node *curr;
			for(curr=top;curr!=NULL;curr=curr->next)
			{
				cout<<"The data is "<<curr->data<<endl;
			}
			cout<<endl;
		}
		
		
};
int main()
{
	stack t;
	t.push(10);
	t.push(20);
	t.push(30);
	t.pop();
	t.traverse();
}
