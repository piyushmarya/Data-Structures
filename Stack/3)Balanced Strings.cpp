#include<iostream>
#include<string.h>
using namespace std;
class stack{
	int *arr;
	int s;
	public:
		int top;
		stack(int size)
		{
			//cin>>size;
			top=-1;
			s=size;
			arr=new int[size];
		}
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
		void balanced(string s,int size)
		
		{
			//siz = size;
			for(int i=0;i<size;i++)
			{
				if(s[i]=='['||s[i]=='{'||s[i]=='(')
				push(s[i]);
				else if(s[i]==')'||s[i]=='}'||s[i]==']')
				{
					if(s[i]==')' && arr[top]=='(')
					pop();
					else if(s[i]=='}' && arr[top]=='{')
					pop();
					else if(s[i]==']' && arr[top]=='[')
					pop();
					else
					push(s[i]);
				}
			}
			if(top==-1)
			cout<<"balanced";
			else
			cout<<"not balanced";
		}
	
};
int main()
{
	
	int size;
	string s;
	cin>>s;
    size=s.length();
    stack st(size);
    
}
