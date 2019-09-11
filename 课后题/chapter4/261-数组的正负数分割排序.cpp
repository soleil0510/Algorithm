#include<iostream>
#define N 100
using namespace std;


void split_arr(int a[],int n){
	int b[N];
	int c[N];
	
	int lb=0;
	int lc=0;
	for(int i=0;i<n;i++){
		if(a[i]>0)
			b[lb++]=a[i];
		if(a[i]<0)
			c[lc++]=a[i];
	}
	
	cout<<b[0];
	for(int i=1;i<lb;i++)
		cout<<" "<<b[i];
	for(int j=0;j<lc;j++)
		cout<<" "<<c[j];
	cout<<endl;
}

int main(){
	int n;
	int a[N];
	while(cin>>n){
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		split_arr(a,n);
		
	}
	
	return 0;
}
