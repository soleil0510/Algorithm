#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

stack<char> sign;

int main(){
	string str;

	while(cin>>str){
		while(!sign.empty()){
			sign.pop();
		} 
		for(int i=0;i<str.length();i++){
			if(str[i]=='['){
				sign.push(str[i]);
			}
			if(str[i]==']'){
				if(!sign.empty())
					sign.pop();
				else{
					sign.push(str[i]);
					break;
				}
					
			}	
			if(str[i]=='*'){
				if(!sign.empty())
					sign.pop();	
				else
					sign.push('[');							
			}
		}
		if(sign.empty())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
