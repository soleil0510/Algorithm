//A+B 末尾K位数字相同时输出-1

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	int a,b,k;
	while(cin>>a){
		cin>>b;
		cin>>k;
		if(a==0&&b==0)
			break;
		int n=pow(10.0,k);
		int A=a%n;
		int B=b%n;
		if(A==B)
			cout<<"-1"<<endl;
		else
			cout<<a+b<<endl;
		
		
	}
	
	return 0;
} 
