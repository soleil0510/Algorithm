#include<iostream>
using namespace std;

//最大连续和问题 

int main(){
	int n;
	int a[100];
	int sum;
	
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sum=0;
		for(int i=0;i<n-2;i++){
			for(int j=i+2;j<n;j++){
				if(sum<a[i]+a[j])
					sum=a[i]+a[j];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
