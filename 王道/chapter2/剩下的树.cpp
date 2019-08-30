#include<iostream>
using namespace std;
int Hash[10001];

int main(){
	int L,M;
	while(cin>>L>>M){
		for(int i=0;i<=L;i++)
			Hash[i]=1;
		int a,b;
		for(int i=0;i<M;i++){
			cin>>a>>b;
			for(int j=a;j<=b;j++){
				if(Hash[j]==1)
					Hash[j]=0;
			}
		}
		
		int num=0;
		for(int i=0;i<=L;i++){
			if(Hash[i]==1)
				num++;
		}
		
		cout<<num<<endl;
	}
} 
