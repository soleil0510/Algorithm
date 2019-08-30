#include<iostream>
using namespace std;

int main(){
	string s;
	string c;
	while(cin>>s){
		cin>>c;
		int pos=s.find(c,0);
		while(pos!=string::npos){
			s.erase(pos,c.length());
			pos=s.find(c,0);
		}
		cout<<s<<endl;
	}
	
	return 0;
}
