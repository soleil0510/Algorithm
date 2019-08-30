#include<iostream>
#include<cstring>
using namespace std;

int main(){
	string a;
	int n;
	
	while(cin>>a){
		cin>>n;
		string command; 
		while(n--!=0){
			cin>>command;
			int begin=command[1]-'0';
			int length=command[2]-'0';
			
			int index0=begin+length/2-1;
			int index1=2*begin+length-1;
			
			if(command[0]=='0'){

					for(int i=begin;i<=index0;i++){
						char temp;
						temp=a[i];
						a[i]=a[index1-i];
						a[index1-i]=temp;
					}						
							
			}
			else{
				a.erase(begin,length);
				a.insert(begin,command.substr(3));			
			}
			cout<<a<<endl;
		}		
	}	
	return 0;
}


