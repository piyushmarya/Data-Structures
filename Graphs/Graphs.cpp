#include<iostream>
using namespace std;
class graph{
	public:
	int m,n,**arr;
	graph(int a,int b){
		m=a;
		n=b;
		arr=new int*[n];
		for(int i=0;i<m;i++) 
			arr[i]=new int[m];
		}
	void insert(){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(i==j)
				arr[i][j]=0;
				else
				cin>>arr[i][j];
			}
		}
	}
	void show(){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j];
				}
				cout<<endl;
			}
		}
};
int main(){
	int m,n;
	cin>>m>>n;
	graph g(m,n);
	g.insert();
	g.show();
}
