//ตÝน้ 
#include<iostream>
#include<cstring>
using namespace std;

int i;
void rever(char *c){
	char ch;
	i=0;
	cin>>ch;
	if(ch=='.')
		return;
	else{
		rever(c);
		c[i++]=ch;
	}	
	c[i]='\0';
}

int main(){

		char c[1000];
		rever(c);
		if(strcmp(c,"0")==0)
			break;
		cout<<c<<endl;

	
	return 0;
}
