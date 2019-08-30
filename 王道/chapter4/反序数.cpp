//·´ĞòÊı
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n;
	for(n=1000;n<=1111;n++){
		int a[4];
		int i=0;
		int temp=n;
		while(temp!=0){
			a[i]=temp%10;
			temp=temp/10;
			i++;
		}
		int n2=a[3]*1+a[2]*10+a[1]*100+a[0]*1000;
		if(n*9==n2)
			cout<<n<<endl;
		
	}
	
	return 0;
} 
