#include<iostream>
using namespace std;
int quick(int a[],int left,int right)
{
	int loc,i,temp;
	loc=left;
	for(i=right;i>=0;i--)
	{
		back:
			while(a[loc]<a[right] && right!=loc)
			{
				right--;
			}
			if(right==loc)
			{
				return loc;
			}
			else
			{
				temp=a[right];
				a[right]=a[loc];
				a[loc]=temp;
				loc=right;
			}
			while(a[left]>a[loc] && left!=loc)
			{
				left--;
			}
			if(left==loc)
			{
				return loc;
			}
			else
			{
				temp=a[right];
				a[right]=a[loc];
				a[loc]=temp;
				loc=left;
			}
		goto back;
	}
}
int main()
{
	int i,a[100],n,left,right,res,lower[100],upper[100],top=-1;
	cout<<"Enter the number of elements!\n";
	cin>>n;
	cout<<"Enter the elements!\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	top++;
	lower[top]=0;
	upper[top]=n-1;
	while(top!=-1)
	{
		left=lower[top];
		right=upper[top];
		top--;
		res=quick(a,left,right);
		if(left<res-1)
		{
			lower[++top]=left;
			upper[top]=res-1;
		}
		if(res+1<right)
		{
			lower[++top]=res+1;
			upper[top]=right;
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
