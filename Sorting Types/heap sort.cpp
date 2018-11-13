#include<iostream>
using namespace std;
void max_heapify(int arr[],int i,int n)
{
	int largest=0,l,r;
	l=2*i+1;
	r=2*i+2;
	if(l<n && arr[l]>arr[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest,n);
	}
}
void build_maxheap(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		max_heapify(arr,i,n);
	}
}
void heapsort(int arr[],int n)
{
	int heapsize=n;
	build_maxheap(arr,n);
	for(int i=n-1;i>=1;i--)
	{
		int temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		heapsize=heapsize-1;
		max_heapify(arr,0,heapsize);
	}
	for(int j=0;j<n;j++)
	{
		cout<<arr[j]<<" 3";
	}
}
int main()
{
	int a[100],i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	heapsort(a,n);
}
