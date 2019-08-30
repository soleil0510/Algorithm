//”÷“ª∞ÊA+B
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int m;
	long long A,B;
	while(scanf("%d",&m)!=EOF){
		if(m==0)
			break;
		scanf("%lld%lld",&A,&B);
		int a[40];
		int i=0;
		long n=A+B;
		if(n==0)
			printf("%d\n",0);
		else{
			while(n!=0){
				a[i]=n%m;
				n=n/m;
				i++;
			}
			
			for(int j=i-1;j>=0;j--){
				printf("%d",a[j]);
			}
			printf("\n");	
			
		}	
	}
	
	
	return 0;
} 
