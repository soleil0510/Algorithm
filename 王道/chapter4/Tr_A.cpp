//Tr A  二分求幂练习

//每循环一次，都做一次求余，减小乘数的大小

#include<iostream>
using namespace std;


int main(){
	int T;
	int n;
	long k;
	
	cin>>T;
	while(T--){
		cin>>n>>k;
		int A[11][11];
		int sum=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>A[i][j];
				if(i==j)
					sum+=A[i][j];
			}
		}
		int ans=1;
		for(int i=0;i<k;i++){
			ans=ans*sum;
			
		}
		ans%=9973;
		cout<<ans<<endl;
	}
	
	return 0;
}
