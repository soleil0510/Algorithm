#include<iostream>
#include<algorithm>
#define offset 500000
using namespace std;
int hash[1000001];

int main(){
	int n;
	int m;
	
	
	while(cin>>n>>m){
		for(int i=-500000;i<=500000;i++){
			hash[i+offset]=0;
		}
		
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			hash[x+offset]=1;
		}
		
		for(int i=500000;i>=-500000;i--){
			if(m==0)
				break;
			
			if(hash[i+offset]==1){
				cout<<i<<" ";
				m--;
			}
		}
		cout<<endl;
	}
	
	return 0;
}
