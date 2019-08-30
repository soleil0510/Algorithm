//´óÊýa+b
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

char a[1000];
char b[1000];
char ans[1001];

int main(){
	//ÄæÐò´æ´¢
	while(cin>>a>>b){
		
		memset(ans,0,1001*sizeof(char));
		int len1 = strlen(a);
		int len2 = strlen(b);
		for(int i=len1;i<1000;i++)
			a[i]='0';
		for(int i=len2;i<1000;i++)
			b[i]='0';
		
		for(int i=0;i<len1/2;i++){
			int temp=a[i];
			a[i]=a[len1-i-1];
			a[len1-i-1]=temp;
		}
	
		for(int j=0;j<len2/2;j++){
			int temp=b[j];
			b[j]=b[len2-j-1];
			b[len2-j-1]=temp;
		}
	
		int len=max(len1,len2);
		
		int num=0;
		int k;
		for(k=0;k<len;k++){
			
			int temp=(a[k]-'0')+(b[k]-'0')+num;
			if(temp>=10){
				temp=temp%10;
				num=1;
			}
			else{
				num=0;
			}
			ans[k]='0'+temp;
		}
		if(num==1)
			ans[k]='1';
		
		int ans_len=strlen(ans);
		for(int z=ans_len-1;z>=0;z--){
			cout<<ans[z];
		}
		cout<<endl;
		
		
	}
	
	
	return 0;
}
