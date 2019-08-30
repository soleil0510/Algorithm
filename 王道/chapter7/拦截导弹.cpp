#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int k;
	int h[25];
	int f[25];
	while(cin>>k){
		for(int i=0;i<k;i++){
			cin>>h[i];
			f[i]=1;
		}
		
		int maxvalue=1;
		for(int i=1;i<k;i++){
			for(int j=i-1;j>=0;j--){
				if(h[j]>=h[i]){
					f[i]=max(f[i],f[j]+1);
				}
			}
			if(maxvalue<f[i])
				maxvalue=f[i];
		}
//		for(int i=0;i<k;i++)
//			cout<<f[i]<<" ";
		cout<<maxvalue<<endl;
	} 
	
	return 0;
} 

