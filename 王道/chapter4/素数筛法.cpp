//ËØÊıÉ¸·¨

#include<iostream>
#include<cmath>
using namespace std;

int prime[10000];
int size;
int mark[10001];

void initPrime(){
	size=0;
	for(int i=1;i<=10000;i++)
		mark[i]=false;
	for(int i=2;i<10000;i++){
		if(mark[i]==true)
			continue;
		else{
			prime[size++]=i;
			for(int j=i*i;j<10000;j+=i){
				mark[j]=true;
			}
		}
	}			
}

int main(){
	int n;
	initPrime();
	while(cin>>n){
		int flag=0;		
		if(prime[0]<n && prime[0]%10==1)
			cout<<prime[0]; 
		for(int i=1;i<size;i++){
			if(prime[i]<n && prime[i]%10==1){
				if(flag==0)
					cout<<prime[i];
				else
					cout<<" "<<prime[i];
				flag=1;
			}		
		}
		if(flag==0)
			cout<<-1;
		
		cout<<endl;
		
	}
		
	return 0;
} 
