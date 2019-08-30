#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	int a[1001];
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<a[0]<<endl;
			cout<<-1<<endl;
		}
		else{
			sort(a,a+n);
			cout<<a[n-1]<<endl;
			for(int i=0;i<n-1;i++){
				cout<<a[i]<<" ";
			}		
			cout<<endl;
		}
	
	}
	
	return 0;
} 
