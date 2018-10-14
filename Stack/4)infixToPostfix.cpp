#include<iostream>
#include<string.h>
using namespace std;
class stack{
	char *arr;
	int s;
	char temp;
	char c;
	public:
		int top;
		stack(int size)	{
			//cin>>size;
			top=-1;
			s=size;
			arr=new char[size];
		}
		void push(char item){
		if(top>=s-1){
			cout<<"overflow";
			}
		else{
				top++;
				arr[top]=item;
			}
		}
		char pop(){
			if(top==-1)
			{
				//return "u";
			}
			else{
				temp=arr[top];
				top--;
			}
			return temp;
		}
		void convert(string s,int size)
	{
		string str = "";
		for(int i=0;i<size;i++){
			if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z'){
				str+=s[i];
			}
			else if(s[i]=='^'){
					push(s[i]);
				}
				else if(s[i]=='*') {
					if(arr[top]=='^')
					{
					c=pop();
					if(c!='(' && c!=')'){
				str+=c;
				push(s[i]);
			}
			    	}
					else{
					 push(s[i]);
					}
				}
				else if(s[i]=='/'){
			    if(arr[top]=='^' || arr[top]=='*' )
				//push(c);
				{
				c=pop();
				if(c!='(' && c!=')'){
			    str+=c;
				push(s[i]);
			}
		    	}
				else{
				  push(s[i]);
				}
			}
			else if(s[i]=='+'){
			if(arr[top]=='^' || arr[top]=='*' || arr[top]=='/' )
			{
			c=pop();
		//	cout<<c;
			if(c!='(' && c!=')'){
				str+=c;
				push(s[i]);
			}
		    }
				else{
				  push(s[i]);
				}
			}
			else if(s[i]=='-'){
			if(arr[top]=='^' || arr[top]=='*' || arr[top]=='/' || arr[top]=='+' ){
				c=pop();
				if(c!='(' && c!=')'){
				str+=c;
				push(s[i]);
			}
		    	}
				else{
				  push(s[i]);
				}
			}
			else if(s[i]=='(' && c!=')')
			push(s[i]);
				else if(s[i]==')'){
					while(arr[top]!=')'){
						c=pop();
						if(c!='('){
				str+=c;
				push(s[i]);
			}
					}
				}
			}
			while(top!=-1){
				c=pop();
				if(c!='(' && c!=')'){
				str+=c;
				//push(s[i]);
			}
				//push(s[i]);
		}
	cout<<str;}};
int main(){
	int size;
	string s;
	cin>>s;
    size=s.length();
    stack st(size);
	st.convert(s,size);
	//st.out();
}
