#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
	char s1[101];
	char str1[101];
	gets(s1);
	string s=s1;
	for(int i=0;i<s.length();i++)
		s[i]=tolower(s[i]);
	while(gets(str1)){
		string str=str1;
		string temp=str; 
		
		int L=str.length();
		//去除空格，并把s去除，不区分大小写 
		for(int i=0;i<L;i++){
			if(temp[i]!=' ')
				temp[i]=tolower(temp[i]);
		} 
		
		//去除s
		int L1=s.length();
		int pos=temp.find(s,0);
		while(pos!=string::npos){
			temp.erase(pos,L1);
			str.erase(pos,L1);
			pos=temp.find(s,pos);
		}
		
		//去除空格	
		int startpos=str.find(' ',0);
		while(startpos!=string::npos){
			str.erase(startpos,1);
			startpos=str.find(' ',startpos);
		}
			
		cout<<str<<endl;
	
		 
	}
	
	
	return 0;
} 
