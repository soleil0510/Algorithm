//ÊýÖÆ×ª»»

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


int main(){
	
	int a,b;
	char n[65];
	
	while(cin>>a){
		cin>>n;
		cin>>b;
		
		int sum=0;
		int temp;
		int len=strlen(n);
		for(int i=0;i<len;i++){
			if(n[i]>='0'&&n[i]<='9')
				temp=n[i]-'0';
			else if(n[i]>='a'&&n[i]<='z')
				temp=n[i]-'a'+10;
			else
				temp=n[i]-'A'+10;
			sum+=temp*pow(a,len-i-1);
		} 
		
		char result[65];
		char temp2;
		int j=0;	
		while(sum!=0){
			int ans=sum%b;
			if(ans<10)
				temp2='0'+ans;
			else if(ans>=10)
				temp2='A'+ans-10;
			result[j]=temp2;
			sum=sum/b;
			j++;
		}
		for(int k=j-1;k>=0;k--){
			cout<<result[k];
		}
		cout<<endl;
		
		
	}	
	
	return 0;
} 
