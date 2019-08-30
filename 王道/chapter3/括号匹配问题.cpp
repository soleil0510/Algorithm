#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

stack<int> s; //数组下标存入堆栈 

int main(){
	char s1[101];
	char s2[101];
	
	while(scanf("%s",s1)!=EOF){
		int len=strlen(s1);
		int i;
		for(i=0;i<len;i++){
			if(s1[i]=='('){
				s.push(i);
				s2[i]=' ';
			}
			else if(s1[i]==')'){
				if(!s.empty()){
					s.pop();
					s2[i]=' ';
				}		
				else
					s2[i]='?';
			}
			else
				s2[i]=' ';
		}
		
		if(!s.empty()){
			while(!s.empty()){
				s2[s.top()]='$';
				s.pop();
			}
		}
		
		printf("%s\n%s\n",s1,s2);
		
	}
	
	return 0;
}
