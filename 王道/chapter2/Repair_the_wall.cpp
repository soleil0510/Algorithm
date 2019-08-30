#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	
	int L,N;
	int size[600];
	while(cin>>L>>N){
		for(int i=0;i<N;i++){
			cin>>size[i];
		}
		sort(size,size+N,cmp);
		int rest_L=L;
		int sum=0;
		for(int i=0;i<N;i++){
			if(rest_L!=0){
				if(size[i]<=rest_L){
					rest_L-=size[i];
					sum++;
				}
				else{
					rest_L=0;
					sum++;
					break;
				}	
			}

		}
		if(rest_L==0)
			cout<<sum<<endl;
		else
			cout<<"impossible"<<endl;
	}
	
	return 0;
}
