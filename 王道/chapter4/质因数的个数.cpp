//分解质因数
#include<iostream>
#include<cmath>
using namespace std;


int main(){
	
	long N;
	while(cin>>N){
		long sum=0;
		long len=sqrt(N)+1;
		for(long i=2;i<len;i++){
			while(N%i==0){
				N=N/i;
				sum++;
			}
			if(N<=1)
				break;
		}
		if(N>1)
			sum++;
		cout<<sum<<endl;
	} 
	
	return 0;
} 
