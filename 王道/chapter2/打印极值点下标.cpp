#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int k;
	int a[81];
	while(cin>>k){
		for(int i=0;i<k;i++){
			cin>>a[i];
		}
		if(a[0]!=a[1])
			cout<<"0"<<" ";
		for(int i=1;i<k-1;i++){
			if((a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1])){
				cout<<i<<" ";
			}
		}
		if(a[k-2]!=a[k-1])
			cout<<k-1;
		cout<<endl;
	} 
	
	
	return 0;
} 
