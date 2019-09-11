#include<iostream>
#define N 100
using namespace std;

bool isRepeat(int a[N][N],int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n-1;j++){
			//与同行比
			for(int k=j+1;k<n;k++){
				if(a[i][j]==a[i][k]){
					return true;
				}
			} 
			
			//与其他行比
			for(int p=i+1;p<m;p++){
				for(int q=0;q<n;q++){
					if(a[i][j]==a[p][q])
						return true;
				}
			} 
			
		}
	}
	
	return false;
}

int main(){
	int m,n;
	while(cin>>m>>n){
		if(m==0 && n==0)
			break;
		int a[N][N];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		}
		if(isRepeat(a,m,n))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
}
