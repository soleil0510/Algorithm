#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

stack<double> number;
stack<char> sign;



int main(){
	string exp;
	while(cin>>exp){
		int len=exp.length();
		for(int i=0;i<len;i++){
			if(exp[i]>'0' && exp[i]<'9'){
				char temp[100];
				int j=0;
				while(exp[i]>'0' && exp[i]<'9' || exp[i]=='.'){
					temp[i++]=exp[i];
				}
				temp[i]='\0';
				double num=numToDouble(temp);
				number.push(num);
			}
			
			
		}
	}
	
	return 0;
} 
