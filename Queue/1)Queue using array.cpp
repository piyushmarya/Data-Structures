#include <iostream>
using namespace std;

class queue
{
    int front ,rear,size;
    int *arr;
public:
    queue()
    {
        size=0;
    }
    queue(int n)
    {
        front=-1;
        rear=-1;
        arr=new int[n];
        size=n;
    }
    void enqueue(int a)
    {
        if(rear==size-1)
        {
            cout<<"queue overflow\n";
        }
        else if(front==-1)
        {
            front=rear=0;
            arr[rear]=a;
        }
        else{
            rear++;
            arr[rear]=a;
        }
    }
    void dequeue()
    {
        if(front>rear || front==-1)
        {
            cout<<"queue empty";
            
        }
        else{
            front++;
        }
    }
    void traverse()
    {
        if(front>rear)
        {
            cout<<"queue empty";
        }
        else
        {  cout<<"queue is:\n";
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
        }
    }
};
int main()
{
    queue q;
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
