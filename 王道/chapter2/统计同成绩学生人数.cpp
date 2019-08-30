#include<iostream>
using namespace std;

int main(){
	int N;
	int score;
	int Hash[101]={0};
	int n;
	while(cin>>N){
		if(N==0)
			break;
		for(int i=0;i<N;i++){
			cin>>n;
			Hash[n]++;
		}
		cin>>score;
		cout<<Hash[score]<<endl;
	}
	
	return 0;
} 
