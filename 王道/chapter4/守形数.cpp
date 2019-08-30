//ÊØĞÎÊı
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int N;
	while(cin>>N){
		int N2=N*N;
		int n=1;
		int temp=N;
		while(temp/10!=0){
			temp=temp/10;
			n++;
		}
		int m=pow(10,n);
		if(N2%m==N)
			cout<<"Yes!"<<endl;
		else
			cout<<"No!"<<endl;
		
	}
	
	
	return 0;
} 
 
