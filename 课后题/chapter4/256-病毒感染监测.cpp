#include<iostream>
#include<cstring>
#define Maxsize 100
using namespace std;

typedef struct{
	char *ch;
	int length;
}SString;

bool BF(SString S,SString T){
	int i=0;
	int j=0;
	while(i<S.length && j<T.length){
		if(S.ch[i]==T.ch[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=T.length){
	//	cout<<i-T.length;
		return true;
	}
		
	else
		return false;
}

int main(){

	SString A,B;
	A.ch=new char[Maxsize];
	B.ch=new char[Maxsize];
	while(cin>>A.ch>>B.ch){
		A.length=strlen(A.ch);
		B.length=strlen(B.ch);		
		if( strcmp(A.ch,"0")==0 && strcmp(B.ch,"0")==0 )
			break;
		int n=0;//代表第几个DNA 
		
		int flag=0;
		for(int k=0;k<A.length;k++){
			SString T;
			T.length=A.length;
			T.ch=new char[T.length];
			for(int i=0;i<A.length;i++){
				int j=(i+n)%A.length;
				T.ch[i]=A.ch[j]; 
			}
			T.ch[T.length]='\0';
			if(BF(B,T)){
				flag=1;
				break;
			}
			n++;
		}
		if(flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;		
	}	
	
	
	return 0;
}
