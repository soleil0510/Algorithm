#include<iostream>
#include<map>
#include<cstring>
using namespace std;

map<string,int> M;
int in[2002];


int main(){
	int n;
	while(cin>>n){
		if(n==0)
			break;
		for(int i=0;i<2*n;i++){
			in[i]=0;	
		}
		M.clear();
		int index=0;
		
		for(int i=0;i<n;i++){
			string a,b;
			cin>>a>>b;
			int indexb;
			if(M.find(a)==M.end()){
				M[a]=index;
				index++;
			} 
			if(M.find(b)==M.end()){
				indexb=index;
				M[b]=index;
				index++;
			}
			else
				indexb=M[b];
			in[indexb]++;
		}
		
		int count=0;
		for(int i=0;i<n;i++){
			if(in[i]==0)
				count++;
		}
		
		if(count==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	
	
	return 0;
}
