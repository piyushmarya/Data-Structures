#include<iostream>
using namespace std;
class Queue{
	int front,rear;
	int *arr,size;
	public:
	Queue()
	{
		size=0;
	}
		
	Queue(int n)
	{
		front=-1;
		rear=-1;
		arr=new int[n];
		size=n;
	}
	void enqueue(int a)
	{
		if((rear==size-1 && front==0) || (rear==front-1))
		{
			cout<<front<<" "<<rear<<" "<<"Queue overflow\n";
		}
		else if(front==-1 && rear==-1)
		{
			front=rear=0;
			arr[rear]=a;
		}
		else if(rear==size-1 && front!=0)
		{
			rear=0;
			arr[rear]=a;
		}
		else
		{
			rear++;
			arr[rear]=a;
		}
		/*if(front==(rear+1)%size)   //shortcut method
		{
			cout<<"Queue overflow\n";
		}
		else if(front==-1 && rear==-1)
		{
			front=rear=0;
			arr[rear]=a;
		}
		else
		{
			rear=(rear+1)%size;
			arr[rear]=a;
		}*/
	}
	void dequeue()
	{
		if(front==-1 && rear==-1)
		{
			cout<<"Queue is empty\n";
		}
		else if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		/*else if(front==size-1)
		{
			front=0;
		}*/
		else
		{
			front=(front+1)%size;
		}
	}
	void traverse()
	{
		if(front==-1)
			cout<<"queue is empty";
		/*else if(front>rear)
		{
			cout<<"Queue is:\n";
			for(int i=front;i<size;i++)
			{
				cout<<arr[i]<<" ";
			}
			for(int i=0;i<=rear;i++)
			{
				cout<<arr[i]<<" ";
			}
		}
		else
		{
			cout<<"Queue is:\n";
			for(int i=front;i<=rear;i++)
			{
				cout<<arr[i]<<" ";
			}
		}*/
		else
		{
			for(int i=front;i!=rear;i=(i+1)%size)
			{
				cout<<arr[i]<<" ";
			}
			cout<<arr[rear];
		}
	}
};
int main()
{
	  Queue q;
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
