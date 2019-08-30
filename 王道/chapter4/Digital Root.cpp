//Digital Root
#include<iostream>
using namespace std;

int findroot(int n){
	int i=0;
	int sum=0;
	while(n!=0){
		sum+=n%10;
		n=n/10;
	}
	return sum;
}

int main(){
	int n;
	while(cin>>n){
		
		int sum=findroot(n);
		while(sum>=10){
			sum=findroot(sum);
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
