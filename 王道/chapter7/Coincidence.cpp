#include<iostream>
#include<cstring>
using namespace std;

int main(){
	string s1,s2;
	int dp[101][101];
	int maxLength=0;
	while(cin>>s1>>s2){
		int L1=s1.length();
		int L2=s2.length();
		for(int i=0;i<=L1;i++)
			dp[i][0]=0;
		for(int j=0;j<=L2;j++)
			dp[0][j]=0;
		for(int i=1;i<=L1;i++){
			for(int j=1;j<=L2;j++){
				if(s1[i-1]==s2[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
				
			}
		}
		
		cout<<dp[L1][L2]<<endl;
	}
	
	
	return 0;
}
