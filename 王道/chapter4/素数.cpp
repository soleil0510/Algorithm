#include<iostream>
#include<cmath>
using namespace std;


bool isPrime(int n){
	int flag=0;
	int len=sqrt(n)+1;
	for(int i=2;i<len;i++){
		if(n%i==0){
			flag=1;
			return false;
		}
	}
	return true;
	
}

int main(){
	int n;
	
	while(cin>>n){
		int flag=0;
		for(int i=2;i<n;i++){
			if(isPrime(i) && i%10==1){
				if(flag==0)
					cout<<i;
				else
					cout<<" "<<i;
				flag=1;
			}
		}
		if(flag==0)
			cout<<-1;
		cout<<endl;
		
		
	}
	return 0;
}
