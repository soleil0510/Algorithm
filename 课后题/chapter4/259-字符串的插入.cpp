#include<iostream>
#include<cstring>
#define Maxsize 1000
using namespace std;

typedef struct{
	char *ch;
	int length;
}SString;
//将字符串t插到s中，插入位置为pos 
void insert(SString &s,SString &t,int pos){
	
	for(int j=s.length-1;j>=pos-1;j--){
		s.ch[j+t.length]=s.ch[j];
	}
	s.length+=t.length;
	s.ch[s.length]='\0';
	
	int k=0;
	for(int i=pos-1;i<pos-1+t.length;i++){
		s.ch[i]=t.ch[k];
		k++;
	}
	
	cout<<s.ch<<endl;
}

int main(){
	int pos;

	SString s;
	SString t;
	while(cin>>pos){
		
		if(pos==0)
			break;
		s.ch=new char[Maxsize];
		t.ch=new char[Maxsize];
		cin>>s.ch>>t.ch;
		s.length=strlen(s.ch);
		t.length=strlen(t.ch);
		insert(s,t,pos);
		delete s.ch;
		delete t.ch;
	}
	
	
	return 0;
}
