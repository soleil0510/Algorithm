#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	
	char s[201];
	while(cin>>s){
		int n=strlen(s);
		sort(s,s+n);
		cout<<s<<endl;
	}
	
	
	return 0;
}
