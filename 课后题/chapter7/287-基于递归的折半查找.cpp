#include<iostream>
#define N 1000
using namespace std;

int search(int a[],int k,int low,int high){
	if(low<=high){
		int mid=(low+high)/2;
		if(a[mid]==k)
			return mid;
		else if(a[mid]>k)
			return search(a,k,low,mid-1);
		else
			return search(a,k,mid+1,high);
	}
	else
		return -1;
		
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
		int k;
		cin>>k;
		//cout<<search(a,k,0,n-1)<<endl;
		if(search(a,k,0,n-1)==-1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		
	}
	return 0;
}
