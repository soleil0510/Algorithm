#include<iostream>
#define N 1000
using namespace std;



int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		int a[N];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int k;
		for(int i=0;i<n-1;i++){
			if(a[i]<0)
				continue;
			else{
				for(int j=i+1;j<n;j++){
					if(a[j]<0){
					
						k=j;
						int t=a[i];
						a[i]=a[k];
						a[k]=t;
						break;
					}
				}	
			}
		}
		cout<<a[0];
		for(int i=1;i<n;i++){
			cout<<" "<<a[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}
