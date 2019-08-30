//求A^B最后三位数表示的整数 
#include<iostream>
#include<cmath>
using namespace std;

//int main(){
//	int A,B;
//	while(cin>>A>>B){
//		if(A==0&&B==0)
//			break;
//		int ans=1;
//		A=A%1000;
//		for(int i=1;i<=B;i++){
//			ans*=A;
//			ans=ans%1000;
//		}
//		cout<<ans<<endl;
//		
//	}
//	
//	
//	return 0;
//} 

int main(){
	int A,B;
	while(cin>>A>>B){
		if(A==0&&B==0)
			break;
		int ans=1;
		while(B!=0){
			if(B%2==1){
				ans=ans*A;
				ans%=1000;
			}
			B=B/2;
			A=A*A;
			A%=1000;
		}
		ans%=1000;
		cout<<ans<<endl;
	}
	
	return 0;
}
