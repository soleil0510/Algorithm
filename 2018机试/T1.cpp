#include<iostream>
using namespace std;


int main(){
	int sum=0;
	cout<<"1000以内的完数:"<<endl;
	for(int n=1;n<=1000;n++){
		sum=0;
		for(int i=1;i<n;i++){
			if(n%i==0){
				sum+=i;
			}
		}
		if(sum==n)
			cout<<sum<<endl;
	}
	
	
	return 0;
} 
