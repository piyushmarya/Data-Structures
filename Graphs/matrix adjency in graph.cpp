#include<iostream>
using namespace std;
int main()
{
	int a[100][100],j,k,i,n;
	int x=0,y=0;
	cin>>n;
	int ch;
	cout<<"enter 1 for new and 2 for adding new edge and 3 for deleting the edge"<<endl;
	cin>>ch;
	while(ch!=0)
	{
	switch(ch)
	{
	case 1:
	{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	while(x!=0 && y!=0)
	{
		cin>>x;
		cin>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<endl;
	}
	break;
	}
	case 2:
		{
			cin>>x;
			cin>>y;
			if(x<=n && y<=n)
			{
				a[x][y]=1;
				a[y][x]=1;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					{
						cout<<a[i][j]<<"  ";
					}
					cout<<endl;
			}
		}
			else
			{
				cout<<"invalid choice";
			}
		}
		break;
	case 3:
		{
			cin>>x;
			cin>>y;
			if(x<=n && y<=n)
			{
				a[x][y]=0;
				a[y][x]=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					{
						cout<<a[i][j]<<"  ";
					}
					cout<<endl;
			}
		}
			else
			{
				cout<<"invalid choice";
			}
		}
	}
	cout<<"enter 1 for new and 2 for adding new edge and 3 for deleting the edge"<<endl;
	cin>>ch;
	}
}
