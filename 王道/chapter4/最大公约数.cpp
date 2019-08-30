//最大公约数

#include<iostream>
using namespace std;

int gcd(int a,int b){
//	while(b!=0){
//		int temp2=a;
//		a=b;
//		b=temp2%b;
//	}	
//	return a;
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}


int main(){
	int a,b;
	while(cin>>a>>b){
		cout<<gcd(a,b)<<endl;
	}
	
	
	return 0;
} 
