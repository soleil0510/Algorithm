#include<iostream>
using namespace std;

int main(){
	int n;
	long long f[21];
	f[1]=0;
	f[2]=1;
	for(int i=3;i<=20;i++){
		f[i]=(i-1)*f[i-1]+(i-1)*f[i-2];
	}
	while(cin>>n){
		cout<<f[n]<<endl;
	}
	
	return 0;
} 
