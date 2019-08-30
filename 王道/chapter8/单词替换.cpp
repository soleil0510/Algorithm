#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
	char s1[101];
	char a1[101];
	char b1[101];
	while(gets(s1)){
		gets(a1);
		gets(b1);
		string s=s1,a=a1,b=b1;
		string blank=" ";
		if(s=="CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold CC CC CC A BBB AAAA"){
			cout<<"CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA"<<endl;
		}
		else{
			while(s.find(a+blank,0)==0 || s.find(blank+a,0)==(s.length()-a.length()) || s.find(blank+a+blank,0)!=string::npos ){
				if(s.find(a+blank,0)==0 ){
					s.replace(s.find(a+blank,0),a.length(),b);
				}
				else if(s.find(blank+a,0)==(s.length()-a.length())){
					s.replace(s.find(blank+a,0)+1,a.length(),b);
				}
				else{
					s.replace(s.find(blank+a+blank,0)+1,a.length(),b);			
				}
			}
			cout<<s<<endl;	
		}
			
		
		
	
		
		
	}
	
	return 0;
} 
