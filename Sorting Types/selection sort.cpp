#include<iostream>
using namespace std;
void selectionsort(int a[],int s)
{
	int j,k,i,min,temp;
	for(i=0;i<s;i++)
	{
		min=a[i];
		k=i;
		for(j=i;j<s;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				k=j;
			}
		}
		temp=a[k];
		a[k]=a[i];
		a[i]=temp;
	}
	for(i=0;i<s;i++)
	{
		cout<<a[i]<<"  ";
	}
}
int main()
{
	int s,i,arr[50];
	cin>>s;
	for(i=0;i<s;i++)
	{
		cin>>arr[i];
	}
	selectionsort(arr,s);
	return 0;
}
