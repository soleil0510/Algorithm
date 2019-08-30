#include<iostream>
using namespace std;

int main(){
	int n;
	int h[100];
	int left[100];
	int right[100];
	
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>h[i];
			left[i]=1;
			right[i]=1;
		}
		
		//求以h[i]为首的最长下降子序列 
		for(int i=n-2;i>=0;i--){
			for(int j=i+1;j<n;j++){
				if(h[i]>h[j]){
					right[i]=max(right[i],right[j]+1);
				}
			}
		}

		
		//求以h[i]为结尾的最长上升子序列 
		for(int i=1;i<n;i++){
			for(int j=i-1;j>=0;j--){
				if(h[i]>h[j]){
					left[i]=max(left[i],left[j]+1);
				}
			}
		}

		int max=1;
		for(int i=0;i<n;i++){
			if(max<(left[i]+right[i]-1))
				max=left[i]+right[i]-1;
		}
		
		cout<<n-max<<endl;
	}
	return 0;
}
