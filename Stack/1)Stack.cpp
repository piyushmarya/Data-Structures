#include<iostream>
#include<string.h>
using namespace std;
class stack{
	int *arr;
	int s;
	public:
		int top;
		void push(char item)
		{
		if(top>=s-1)
		{
			cout<<"overflow";
			
		}
		else
			{
				top++;
				arr[top]=item;
			}
		}
		void pop()
		{
			if(top==-1)
			{
				cout<<"underflow";
			}
			else
			{
				int temp=arr[top];
				top--;
			}
			//return temp;
		}
		void traverse(){
		for(int i=top;i>-1;i--)
		cout<<arr[i]<<" ";
		cout<<endl;
	}
};
int main()
{
	
	stack q;
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
                q.push(x);
                cout<<"enter the choice";
                cin>>n;
                break;
            case 2:
                q.pop();
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
    

