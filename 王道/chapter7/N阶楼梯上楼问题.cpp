#include<iostream>
using namespace std;

int main(){
	int N;
	long long f[91];
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=90;i++){
		f[i]=f[i-1]+f[i-2];
	}
	while(cin>>N){
		cout<<f[N]<<endl;
	} 
	return 0; 
} 
