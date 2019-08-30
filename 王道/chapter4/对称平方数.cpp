//对称平方数 11*11=121

#include<iostream>
#include<cstring>
using namespace std;

int main(){
	for(int n=1;n<256;n++){
		int temp=n*n;
		int a[20];
		int i=0;
		while(temp!=0){
			a[i]=temp%10;
			temp=temp/10;
			i++;
		}
		
		int flag=1;
		int len=i;
		for(int j=0;j<len/2;j++){
			if(a[j]!=a[len-j-1]){
				flag=0;
			}
		}
		if(flag==1)
			cout<<n<<endl;
	}
	
	
	return 0;
} 
