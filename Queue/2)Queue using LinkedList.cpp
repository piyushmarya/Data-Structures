#include <iostream>
using namespace std;
struct node
{
    node *next;
    int data;
};
class queue1
{
    node *front;
    node *rear;
public:
    queue1()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue(int x)
    {
        if(rear==NULL)
        {
            node *p;
            p=new node;
            p->data=x;
            p->next=NULL;
            front=p;
            rear=p;
        }
        else{
            node *q;
            q=new node;
            q->data=x;
            rear->next=q;
            q->next=NULL;
            rear=q;
            
        }
    }
    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"queue is empty"<<endl;
        }
        else
        {
            node *t;
            t=front;
            front=front->next;
            //t->next=NULL;
            delete(t);
        }
    }
    void traverse()
    {
        node *cur;
        cur=front;
        if(front==NULL)
        {
            cout<<"queue is empty"<<endl;
        }
        else{
            while(cur!=NULL)
            {
                cout<<cur->data<<" ";
                cur=cur->next;
            }
        }
    }
};
int main() {
    queue1 q;
    cout<<"1 for insertion\n 2 for deletion\n 3 for traverse"<<endl;
    int n,x;
    cout<<"enter your choice";
    cin>>n;
    while(n!=0)
    {
        switch(n)
        {
            case 1:
                cout<<"enter the element";
                cin>>x;
                q.enqueue(x);
                cout<<"enter the choice";
                cin>>n;
                break;
            case 2:
                q.dequeue();
                cout<<"enter the choice";
                cin>>n;
                break;
            case 3:
                q.traverse();
                n=0;
                break;

        }
    }
   }
